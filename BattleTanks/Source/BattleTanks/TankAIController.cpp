// Alex Rusu 2021

#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

class UTankAimingComponent;

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
        Super::Tick(DeltaTime);

        auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
        auto ControlledTank = GetPawn();

        if(!ensure(PlayerTank && ControlledTank)) {return;}
        {
            // Move towards the player
            MoveToActor(PlayerTank, AcceptanceRadius);

            // Aim towards the player
            auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
            AimingComponent->AimAt(PlayerTank->GetActorLocation());

            AimingComponent->Fire(); // TODO limit firing rate
        }
}