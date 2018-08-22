// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/PauseMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Player_Character.h"

bool UPauseMenu::Initialize()
{
	// Check if we fail the parentversion of super first
	if (!Super::Initialize())
	{
		// if we did then exit the function with a false for failure
		return false;
	}

	// Bind the OnResumeClicked function to the Resume button delegate for OnClicked
	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UPauseMenu::OnResumeClicked);
	}

	// Bind the OnDesktopClicked function to the DesktopButton delegate for OnClicked
	if (DesktopButton)
	{
		DesktopButton->OnClicked.AddDynamic(this, &UPauseMenu::OnDesktopClicked);
	}

	// Bind the OnMainMenuClicked function to the MainMenuButton delegate for OnClicked
	if (MainMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UPauseMenu::OnMainMenuClicked);
	}

	// Finish the function
	return true;
}

void UPauseMenu::OnResumeClicked()
{
	// Check for a valid player reference
	if (APlayer_Character* Player = Cast<APlayer_Character>(GetOwningPlayerPawn()))
	{
		// If its valid then unpause the game, which handles removing the menu
		Player->UnPauseGame();
	}
}

void UPauseMenu::OnDesktopClicked()
{
	// Tell our owning plaeyr controller to quit the game
	GetOwningPlayer()->ConsoleCommand("quit");
}

void UPauseMenu::OnMainMenuClicked()
{
	// Open the main menu level
	UGameplayStatics::OpenLevel(GetOwningPlayerPawn(), "Map_MainMenu");
}