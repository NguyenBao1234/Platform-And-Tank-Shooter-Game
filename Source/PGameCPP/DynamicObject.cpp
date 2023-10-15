// Fill out your copyright notice in the Description page of Project Settings.


#include "DynamicObject.h"

// Sets default values
ADynamicObject::ADynamicObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADynamicObject::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void ADynamicObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateFunction(DeltaTime);
	MoveFunction(DeltaTime);
	if (MovedDistance >= DistanceNeedMove)
	{
		StartLocation = GetActorLocation();
		VectorMove = -VectorMove;
	}

}
void ADynamicObject::MoveFunction(float DeltaT)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + VectorMove * DeltaT;
	SetActorLocation(CurrentLocation);

	MovedDistance = FVector::Dist(StartLocation, CurrentLocation);
}
void ADynamicObject::RotateFunction(float DeltaT)
{
	AddActorLocalRotation(VectorRotate * DeltaT);
}

