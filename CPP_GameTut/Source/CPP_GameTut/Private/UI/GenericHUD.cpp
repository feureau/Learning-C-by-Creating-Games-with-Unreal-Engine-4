// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/GenericHUD.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetLayoutLibrary.h"

AGenericHUD::AGenericHUD()
{
	GameplayHUDClass = NULL;
	DeadMenuClass = NULL;
	PauseMenuClass = NULL;
}

bool AGenericHUD::ShowSpecificMenu(TSubclassOf<class UUserWidget> ClassToShow, bool GameOnly, bool ShowMouse)
{
	//remove all widgets first
	HideAllMenus();

	if (ClassToShow)
	{
		//Create the widget then add to screen
		UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), ClassToShow);
		CreatedWidget->AddToPlayerScreen();
		if (GameOnly)
		{
			//Set our input mode to game only which allows us full control of the player
			GetOwningPlayerController()->SetInputMode(FInputModeGameOnly());
		}
		else
		{
			// Set our input mode to UI only, just in case we really don't want the player to be able to move
			FInputModeUIOnly InputMode;

			// This allows us to take the mouse out of the viewport
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			// Confirm our input mode
			GetOwningPlayerController()->SetInputMode(InputMode);
		}

		//Update Mouse cursor
		GetOwningPlayerController()->bShowMouseCursor = ShowMouse;

		// Exit the function
		return true;
	}
	return false;
}

void AGenericHUD::HideAllMenus()
{
	// Call an already established function to remove all widgets from the player's screen
	UWidgetLayoutLibrary::RemoveAllWidgets(this);
}