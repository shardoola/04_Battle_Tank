// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "TankAimingComponenet.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay() {

	Super::BeginPlay();
	

		TankAimingComponent = FindComponentByClass<UTankAimingComponenet>();

}
// Called every frame


// Called to bind functionality to input

void ATank::AimAt(FVector HitLocation) {

	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation , LaunchSpeed);
	
}


void ATank::Fire() {

	if (!ensure(Barrel)) {
		return;
	}


		bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

		if (isReloaded) {
			auto projectile = GetWorld()->SpawnActor<AProjectile>(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("projectile")),
				Barrel->GetSocketRotation(FName("projectile"))
				);
			projectile->LaunchProjectile(LaunchSpeed);
			LastFireTime = FPlatformTime::Seconds();
		}
	
}