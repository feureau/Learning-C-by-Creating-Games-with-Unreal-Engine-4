// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModes/GM_Gameplay.h"

void AGM_Gameplay::RespawnPlayer(AController* NewPlayer)
{
	//valid check our new player
	if (NewPlayer)
	{
		// Destroys the current  pawn, then creates a new one at a random spawn point
		NewPlayer->GetPawn()->Destroy();
		RestartPlayer(NewPlayer);
	}
}