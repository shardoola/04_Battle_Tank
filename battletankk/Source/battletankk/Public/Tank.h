// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponenet;

UCLASS()
class BATTLETANKK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponenet * TankAimingComponent = nullptr;
	

public:	
	// Called every frame
	
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelRefernce(UTankBarrel * BarrelToSet);
private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;
};
