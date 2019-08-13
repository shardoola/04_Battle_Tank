// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponenet.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Tank.h"

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
	auto AiminngComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponenet>();
	if (ensure(AiminngComponent)) {


		FoundAimingComponent(AiminngComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("plaayer controller cant find aiming comp at begin play"))
	}


}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!ensure(GetControlledTank())) { return; }
	
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)){
		GetControlledTank()->AimAt(HitLocation);
	
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



	


