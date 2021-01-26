// Alex Rusu 2021

#include "TankTrack.h"
#include "GameFramework/Actor.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();
    auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
    auto RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward).Z;

    IntendMoveForward(ForwardThrow/4);
    IntendTurnRight(RightThrow*4);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!ensure(LeftTrack && RightTrack)) {return;}
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!ensure(LeftTrack && RightTrack)) {return;}
    LeftTrack->SetThrottle(Throw*2);
    RightTrack->SetThrottle(-Throw*2);
}