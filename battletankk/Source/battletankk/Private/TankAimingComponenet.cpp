// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponenet.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


// Sets default values for this component's properties
UTankAimingComponenet::UTankAimingComponenet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponenet::BeginPlay() {
	LastFireTime = FPlatformTime::Seconds();
	// so that first fire is after intial reloade

}

 void UTankAimingComponenet::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	 if (bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds) {
		 FiringState = EFiringState::Reloading;
	 }

}



// Called when the game starts

void UTankAimingComponenet::AimAt(FVector HitLocation) {
	
	if (!ensure(Barrel)) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
	        this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		
	);
	if ( bHaveAimSolution)
		
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
		
	}
	
}
	
	

	

void UTankAimingComponenet::MoveBarrelTowards(FVector AimDirection) {

	if (!ensure(Barrel || Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Turret->Rotate(DeltaRotator.Yaw);
	Barrel->Elevate(DeltaRotator.Pitch); 
}
void UTankAimingComponenet::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) {
	Barrel = BarrelToSet;
	Turret = TurretToSet;


}

	
void UTankAimingComponenet::Fire() {

	


	

	if (FiringState!=EFiringState::Reloading) {
		if (!ensure(Barrel )) {
			return;
		}
		if (!ensure( ProjectileBlueprint)) {
			return;
		}
		auto projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("projectile")),
			Barrel->GetSocketRotation(FName("projectile"))
			);
		projectile->LaunchProjectile(LaunchSpeed);
		
	}

}