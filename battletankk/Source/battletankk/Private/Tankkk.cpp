// Fill out your copyright notice in the Description page of Project Settings.


#include "Tankkk.h"

// Sets default values
ATankkk::ATankkk()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankkk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankkk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankkk::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

