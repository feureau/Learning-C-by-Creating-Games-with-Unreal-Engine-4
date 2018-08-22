// Fill out your copyright notice in the Description page of Project Settings.

#include "Destructible_Actor.h"
#include "Components/StaticMeshComponent.h"
#include "EngineMinimal.h"

// Sets default values
ADestructible_Actor::ADestructible_Actor()
{
	RootComponent = Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	if (Mesh)
	{
		Mesh->SetCollisionObjectType(ECC_WorldDynamic);
	}

	MaxHealth = 25.0f;
	CurrentHealth = MaxHealth;

	DestructionRadius = 400.0f;
	DestructionDamage = 25.0f;
}

// Called when the game starts or when spawned
void ADestructible_Actor::BeginPlay()
{
	Super::BeginPlay();

	if (CurrentHealth != MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void ADestructible_Actor::OnDeath_Implementation()
{
	// Sphere trace for pawns and world dynamics
	{
		// Preapare an array of overlaps
		TArray<FOverlapResult>Overlaps;

		// Save our start position
		const FVector StartPos = Mesh->GetComponentLocation();

		// Save our shape (which is a struct) to use for the trace
		FCollisionShape Sphere = FCollisionShape::MakeSphere(DestructionRadius);

		// Do the trace and check if we overlapped anything
		if (GetWorld()->OverlapMultiByChannel(Overlaps, StartPos, FQuat::Identity, ECC_WorldDynamic, Sphere))
		{
			// loop through each overlap
			for (int index = 0; index < Overlaps.Num(); index++)
			{
				// Make sure we have a good damage type
				TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass());

				// Setup our damage event/type
				FDamageEvent DamageEvent(ValidDamageTypeClass);

				// Apply Damage
				Overlaps[index].GetActor()->TakeDamage(DestructionDamage, DamageEvent, nullptr, this);
			}
		}
	}
	//Destroy this actor
	Destroy();
}

float ADestructible_Actor::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	//Don't continue if health is already below or at zero
	if (CurrentHealth <= 0.0f)
	{
		return 0.0f;
	}

	const float SubtractedHealth = CurrentHealth - DamageAmount;

	// Check if the subtracted health is equal or lower than zero
	if (FMath::IsNearlyZero(SubtractedHealth) || SubtractedHealth < 0.0f)
	{
		// if it is then just lock it to zero and then call our ondeath function
		CurrentHealth = 0.0f;
		OnDeath();
	}
	else
	{
		// otherwise set the current health to the subtracted amount
		CurrentHealth = SubtractedHealth;
	}

	//Check if the subtracted health is equal or lower than zero

	return CurrentHealth;
}