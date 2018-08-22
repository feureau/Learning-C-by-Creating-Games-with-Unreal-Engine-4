// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GamePlayElements/InteractionInterface.h"
#include "InteractionInterface.h"
#include "Interactable_Actor.generated.h"

UCLASS()
class CPP_GAMETUT_API AInteractable_Actor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractable_Actor();

protected:
	virtual void OnInteract_Implementation(AActor* Interactor);
};
