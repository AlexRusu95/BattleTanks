// Alex Rusu 2021

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"

class UTankAimingComponent;
class UTankMovementComponent;

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
        Super::SetPawn(InPawn);

    if (InPawn)
    {
        auto PossessedTank = Cast<ATank>(InPawn);
        if (!ensure(PossessedTank)) {return;}

        // Subscribe out local method to the tank's death event
        PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
    }
}

void ATankAIController::OnPossessedTankDeath()
{
    if (!ensure(GetPawn())) { return; } // TODO remove if ok
	GetPawn()->DetachFromControllerPendingDestroy();

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

        if (AimingComponent->GetFiringState() == EFiringState::Locked)
        AimingComponent->Fire();
    }
}