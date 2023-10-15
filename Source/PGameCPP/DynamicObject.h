// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicObject.generated.h"

UCLASS()
class PGAMECPP_API ADynamicObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADynamicObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Di_Chuyen")
		FVector VectorMove = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Di_Chuyen")
		float DistanceNeedMove = 500;

	UPROPERTY(VisibleAnywhere, Category = "Di_Chuyen")
		float MovedDistance;

	void MoveFunction(float DeltaT);

	UPROPERTY(EditAnywhere, Category = "Xoay_Truc")
		FRotator VectorRotate = FRotator(0, 0, 0);

	void RotateFunction(float DeltaT);



};
