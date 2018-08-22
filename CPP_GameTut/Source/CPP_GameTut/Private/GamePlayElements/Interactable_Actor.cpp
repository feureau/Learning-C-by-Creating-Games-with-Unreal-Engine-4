// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable_Actor.h"

// Sets default values
AInteractable_Actor::AInteractable_Actor()
{
}

void AInteractable_Actor::OnInteract_Implementation(AActor * Interactor)
{
	// Prints out a yellow message into the log window
	UE_LOG(LogTemp, Warning, TEXT("Interaction called from %s"), *Interactor->GetName());
}