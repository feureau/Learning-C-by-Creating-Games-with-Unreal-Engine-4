// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetGameplay.generated.h"

/**
 *
 */
UCLASS()
class CPP_GAMETUT_API UWidgetGameplay : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay") float GetCurrentHealth();

	UFUNCTION(BlueprintPure, Category = "Widget|Gameplay") FText GetCurrentAmmo();
};
