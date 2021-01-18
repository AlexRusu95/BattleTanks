// Alex Rusu 2021


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    // auto Time = GetWorld()->GetTimeSeconds();
    auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);	

    // TODO clamp throttle value so player can't override
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
