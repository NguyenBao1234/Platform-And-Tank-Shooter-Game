// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/UnrealMathUtility.h"
#include "RotaterComponent.h"

// Sets default values for this component's properties
URotaterComponent::URotaterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotaterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotaterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	FRotator TargetRotation = OriginalRotator;
	if (unlock)
	{
	    TargetRotation = OriginalRotator + RotateNeed;
	}
	FRotator NewRotator = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, SpeedTrans);
	GetOwner()->SetActorRotation(NewRotator);
	// ...
}

void URotaterComponent::UnlockRotateFunction()
{
	unlock = true;
}

