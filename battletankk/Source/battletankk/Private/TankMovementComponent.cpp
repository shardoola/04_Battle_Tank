//Copyright Emebrace IT.Ltd
#include  "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw) {


	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO DOUBLE-SPEDD

 }
void UTankMovementComponent::IntendTurnRight(float Throw) {

	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	

}
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankFoward,AIForwardIntention);
	auto RightThrow = FVector::CrossProduct(TankFoward, AIForwardIntention).Z;
	IntendMoveForward(ForwardThrow);
	IntendTurnRight(RightThrow);
	
}
