// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerBoxComponent.h"

UTriggerBoxComponent::UTriggerBoxComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}



void UTriggerBoxComponent::BeginPlay()
{
	Super::BeginPlay();
}




void UTriggerBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
	TArray <AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* ActorOverlapped : Actors)
	{
		if (ActorOverlapped->ActorHasTag(TagTrigger))
		{
			UE_LOG(LogTemp, Display, TEXT("Actor dang chong cheo la: %s"), *ActorOverlapped->GetName());
			if (Rotater != nullptr)
			{
				Rotater->UnlockRotateFunction();
			}
			

		}
	}


}


void UTriggerBoxComponent::SetRotaterREF(URotaterComponent* RotatorREF)
{
	Rotater = RotatorREF;

}
