// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponenet.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"


// Tick
 
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	

}
//super
//aimtowardscrosshair();

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AiminngComponent = GetPawn()->FindComponentByClass<UTankAimingComponenet>();
	if (!ensure(AiminngComponent)) {
		return;
	}


		FoundAimingComponent(AiminngComponent);
	}
	




void ATankPlayerController::AimTowardsCrosshair() {
	auto AiminngComponent = GetPawn()->FindComponentByClass<UTankAimingComponenet>();
	
	if (!ensure(AiminngComponent)) { return; }
	
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)){
		AiminngComponent->AimAt(HitLocation);
	
      }
}
bool  ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	FVector LookDirection;
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	if (GetLookDirection(ScreenLocation, LookDirection))
		{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	
		}
		return true;

	 }
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility))
		{
			HitLocation= HitResult.Location;
			return true;
		}
		HitLocation = FVector(0);
	return false;
}

	bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector &LookDirection) const
		{
		FVector CameraWorldLocation;
		
		return DeprojectScreenPositionToWorld(
			ScreenLocation.X,
			ScreenLocation.Y,
			CameraWorldLocation,
			LookDirection);
	}



	


