// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
    // Get references and game win/lose conditions

    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor *DeadActor)
{
    // Check what type of Actor died, and act accordingly
}

void ATankGameModeBase::HandleGameStart()
{
    // Initialise the start countdown, turret activation, pawn check etc.
    // Call blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
    // See if player has destroyed all the turrets, show win result.
    // else if turret destoyed plyer, show game over result.

    // Call blueprint version GameOver(bool)
}
