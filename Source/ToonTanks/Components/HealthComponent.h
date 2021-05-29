// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

class ATankGameModeBase;

UCLASS()
class TOONTANKS_API AHealthComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

UFUNCTION()
	void TakeDamge(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

private:

UPROPERTY(EditAnywhere)
float DefaultHealth = 100.0f;

float Health = 0.f;

 ATankGameModeBase* GameModeRef;


};
