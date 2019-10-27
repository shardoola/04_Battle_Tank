// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "TankAimingComponenet.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Components/ActorComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	
}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) {


		MoveToActor(PlayerTank, AcceptanceRadius);
		auto AiminngComponent = ControlledTank->FindComponentByClass< UTankAimingComponenet>();
		AiminngComponent->AimAt(PlayerTank->GetActorLocation());
		
		

		
		AiminngComponent->Fire(); 
	}

}