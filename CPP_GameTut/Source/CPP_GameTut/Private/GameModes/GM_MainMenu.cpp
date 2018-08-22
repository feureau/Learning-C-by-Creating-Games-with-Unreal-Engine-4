// Fill out your copyright notice in the Description page of Project Settings.

#include "Gamemodes/GM_MainMenu.h"
#include "Blueprint/UserWidget.h"

void AGM_MainMenu::BeginPlay()
{
	// Check if the class is valid to spawn
	if (MainMenuClass)
	{
		// Get the only player controller within the world to create our menu
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			// Set our input mode to UI only, just in case we really don't want the player to be able to move
			FInputModeUIOnly InputMode;
			// This allows us to take the mosue out of the viewport
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			PC->SetInputMode(InputMode);
			PC->bShowMouseCursor = true;

			// Create and add our widget to the viewport
			UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(PC, MainMenuClass);
			CreatedWidget->AddToPlayerScreen();
		}
	}
}