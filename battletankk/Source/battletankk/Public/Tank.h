// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
// Enum for aiming state



class UTankBarrel;
class UTankAimingComponenet;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANKK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable)
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponenet * TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

	

public:	
	// Called every frame
	
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelRefernce(UTankBarrel * BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretRefernce(UTankTurret* TurretToSet);
	
private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile>ProjectileBlueprint;
	  UTankBarrel* Barrel = nullptr;
	  UPROPERTY(EditDefaultsOnly, Category = Firing)
	  float ReloadTimeInSeconds = 3;
	  double LastFireTime = 0; 

	 
	
};
