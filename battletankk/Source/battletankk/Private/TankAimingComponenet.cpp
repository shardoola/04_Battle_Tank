// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "TankAimingComponenet.h"

// Sets default values for this component's properties
UTankAimingComponenet::UTankAimingComponenet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponenet::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponenet::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UTankAimingComponenet::AimAt(FVector HitLocation,float LaunchSpeed) {
	
	UE_LOG(LogTemp, Warning, TEXT("firirng at %f"), LaunchSpeed);
 }
void UTankAimingComponenet::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {

	Barrel = BarrelToSet;
}