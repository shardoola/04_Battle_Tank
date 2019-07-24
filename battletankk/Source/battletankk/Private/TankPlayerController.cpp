// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
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
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Playrcontroller not posseing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Playrcontroller  posseing a tank: %s"), *ControlledTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("Playrcontroller begin play"));

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) { return; }
	FVector OutLocation;
	FVector HitLocation;
	if (GetSightRayHitLocation(OutLocation))
	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("OutLocation: %s"), *OutLocation.ToString());
}
	bool  ATankPlayerController::GetSightRayHitLocation(FVector &OutLocation) const
	{
		OutLocation = FVector(1.0);
		return true;

	 }



	


