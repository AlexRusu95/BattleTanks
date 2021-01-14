// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/WorldSettings.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player not possesing a tank."));
    }
    else 
    {
        UE_LOG(LogTemp, Warning, TEXT("Player possesing tank %s"), *ControlledTank->GetName());
    }
}

// Tick
    // Super

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // AimTowardsCrosshair();
    UE_LOG(LogTemp, Warning, TEXT("DeltaTime Working"));
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank())
        return;

    // Get world location linetrace through crosshair
    // If it hits the landscape -> tell controlled tank to aim at this point
}