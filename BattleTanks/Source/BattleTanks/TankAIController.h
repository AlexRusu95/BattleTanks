// Alex Rusu 2021

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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

	// Maximum distance AI tank can come close to
	float AcceptanceRadius = 10000;
};
