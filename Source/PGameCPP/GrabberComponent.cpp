// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "GrabberComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UGrabberComponent::UGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();
    
	// ...
	
}


// Called every frame
void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicHandle == nullptr)
	{
		return;
	}
	else
	{

		FVector NewTargetLocation = GetComponentLocation() + GetForwardVector() * DistanceHold;
		PhysicHandle->SetTargetLocationAndRotation(NewTargetLocation, GetComponentRotation());
	}

	// ...
}

void UGrabberComponent::Grab()
{
	UE_LOG(LogTemp, Display, TEXT("Grabbed"));
	UWorld* ThisWorld = GetWorld();
	FHitResult OutHitResult;
	FVector StartTrace = GetComponentLocation();
	FVector EndTrace = StartTrace + GetForwardVector() * DistanceCanGrab;


	FCollisionShape Sphere = FCollisionShape::MakeSphere(50);
	bool HasHit = ThisWorld->SweepSingleByChannel(OutHitResult,StartTrace, EndTrace, FQuat::Identity,ECC_GameTraceChannel1,Sphere);
	PhysicHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (HasHit)
	{
		DrawDebugSphere(ThisWorld, OutHitResult.ImpactPoint, 50, 10, FColor::Blue, false, 2);
		DrawDebugSphere(ThisWorld, OutHitResult.Location, 50, 10, FColor::Blue, false, 2);
		if (PhysicHandle != nullptr)
		{
			PhysicHandle->GrabComponentAtLocationWithRotation(OutHitResult.GetComponent(), NAME_None, OutHitResult.ImpactPoint, GetComponentRotation());
			UE_LOG(LogTemp, Display, TEXT("Da Gan thanh cong "));

		}
		
	}
	AActor* ActorHit = OutHitResult.GetActor();
	
	
	
}

void UGrabberComponent::Release()
{
	if (PhysicHandle->GetComponentLevel() != nullptr)
	{
		PhysicHandle->ReleaseComponent();
		UE_LOG(LogTemp, Display, TEXT("Released"));
	}
	
}

