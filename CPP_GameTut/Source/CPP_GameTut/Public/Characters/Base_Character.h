// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Base_Character.generated.h"

UCLASS()
class CPP_GAMETUT_API ABase_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABase_Character();

	UFUNCTION(BlueprintCallable, Category = "Character|Health")
		void SetCurrentHealth(float NewHealth)
	{
		CurrentHealth = NewHealth;
	}

	UFUNCTION(BlueprintPure, Category = "Character|Health")
		float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	UFUNCTION(BlueprintPure, Category = "Character|Health")
		float GetMaxHealth() const
	{
		return MaxHealth;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character|Death")
		void OnDeath();
	virtual void OnDeath_Implementation() PURE_VIRTUAL(ABase_Character::OnDeath_Implementation, );

	float CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Health")
		float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
		bool bIsSprinting;
};
