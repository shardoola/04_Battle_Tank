// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

#include "TankPlayerController.generated.h"

/**
 * responsible for aiming
 */
class ATank;

UCLASS()
class BATTLETANKK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponenet* AimCompRef);
private:
	
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
	bool GetSightRayHitLocation(FVector &HitLocation) const;
};
