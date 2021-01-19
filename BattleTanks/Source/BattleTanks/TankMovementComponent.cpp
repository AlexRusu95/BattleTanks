// Alex Rusu 2021

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!LeftTrack || !RightTrack) {return;}
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!LeftTrack || !RightTrack) {return;}
    LeftTrack->SetThrottle(Throw*2);
    RightTrack->SetThrottle(-Throw*2);
    // TODO prevent double speed
}