// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void UTankTrack::SetThrottle(float Throttle) {
	
    
	//TODO clamp value

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}