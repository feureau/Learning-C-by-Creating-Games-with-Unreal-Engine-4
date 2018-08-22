// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GenericHUD.generated.h"

/**
 *
 */
UCLASS()
class CPP_GAMETUT_API AGenericHUD : public AHUD
{
	GENERATED_BODY()

public:
	//Constructor
	AGenericHUD();

	class TSubclassOf<UUserWidget> GetGameplayHUDClass() const
	{
		return GameplayHUDClass;
	}

	class TSubclassOf<UUserWidget> GetDeadMenuClass() const
	{
		return DeadMenuClass;
	}

	class TSubclassOf<UUserWidget> GetPauseMenuClass() const
	{
		return PauseMenuClass;
	}

	bool ShowSpecificMenu(class TSubclassOf<class UUserWidget> ClassToShow, bool GameOnly, bool ShowMouse);

	// hides all other menu on screen.
	UFUNCTION(BlueprintCallable, Category = "GenericHUD") void HideAllMenus();

protected:

	// The Player's HUD during gameplay, showing health, ammo and the crosshair.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GenericHUD")
		class TSubclassOf<UUserWidget> GameplayHUDClass;

	// The Menu to use when the player is dead.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GenericHUD")
		class TSubclassOf<UUserWidget> DeadMenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GenericHUD")
		class TSubclassOf<UUserWidget> PauseMenuClass;
};
