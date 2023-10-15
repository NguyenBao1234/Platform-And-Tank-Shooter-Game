// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotaterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PGAMECPP_API URotaterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotaterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UnlockRotateFunction();

private:

	FRotator OriginalRotator;

	UPROPERTY(EditAnywhere)
		FRotator RotateNeed;
	UPROPERTY(EditAnywhere)
		float SpeedTrans;
	UPROPERTY (EditAnywhere)
	bool unlock;


		
};
