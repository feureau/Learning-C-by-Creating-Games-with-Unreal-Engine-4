// Fill out your copyright notice in the Description page of Project Settings.

#include "Base_Character.h"

// Sets default values
ABase_Character::ABase_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxHealth = 10.0f;
	CurrentHealth = MaxHealth;
	bIsSprinting = false;
}

// Called when the game starts or when spawned
void ABase_Character::BeginPlay()
{
	Super::BeginPlay();

	// For when the max health value was changed
	if (CurrentHealth != MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}