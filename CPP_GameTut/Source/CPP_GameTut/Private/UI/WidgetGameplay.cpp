// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/WidgetGameplay.h"
#include "Runtime/Core/Public/Internationalization/Text.h"
#include "Player_Character.h"

float UWidgetGameplay::GetCurrentHealth()
{
	if (APlayer_Character* Player = Cast<APlayer_Character>(GetOwningPlayerPawn()))
	{
		return (FMath::Clamp<float>((Player->GetCurrentHealth() / Player->GetMaxHealth()), 0.0f, 1.0f));
	}
	return 0.5f;
}

FText UWidgetGameplay::GetCurrentAmmo()
{
	if (APlayer_Character* Player = Cast<APlayer_Character>(GetOwningPlayerPawn()))
	{
		return FText::AsNumber(Player->GetCurrentAmmo());
	}

	return FText::AsNumber(999);
}