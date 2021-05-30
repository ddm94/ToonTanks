// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{

    Super::BeginPlay();


    // Call HandleGameStart() to initialise the start countdown, turret activation, pawn check etc.
    HandleGameStart();
}

// Check what type of Actor died, and act accordingly
void ATankGameModeBase::ActorDied(AActor *DeadActor)
{

    if (DeadActor == PlayerTank)
    {
        PlayerTank->HandleDestruction();
        HandleGameOver(false);
    }
    else if (APawnTurret *DestroyedTurret = Cast<APawnTurret>(DeadActor)) // Store a temp ptr to the APawnTurret class and cast it to reference the dead actor
    {
        DestroyedTurret->HandleDestruction();

        if (--TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }

    // UE_LOG(LogTemp, Warning, TEXT("A Pawn died"));
}

// Initialise the start countdown, turret activation, pawn check etc.
void ATankGameModeBase::HandleGameStart()
{
    TargetTurrets = GetTargetTurretCount();
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    // Call blueprint version GameStart();
    GameStart();
}

// See if player has destroyed all the turrets, show win result.
// else if turret destoyed plyer, show game over result.
void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{

    // Call blueprint version GameOver(bool)
    GameOver(PlayerWon);
}

int32 ATankGameModeBase::GetTargetTurretCount()
{
    TArray<AActor *> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
    return TurretActors.Num();
}
