// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
