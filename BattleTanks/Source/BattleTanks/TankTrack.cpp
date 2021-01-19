// Alex Rusu 2021


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // TODO clamp throttle value so player can't override
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
