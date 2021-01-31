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
	
protected:
	// Maximum distance AI tank can come close to
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

private:

	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

};
