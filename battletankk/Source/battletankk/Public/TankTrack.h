// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tanktrack is used to set max drivin force,and to apple forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Input")
	void SetThrottle(float Throttle);
	//max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000000;//assume 40 ton tank,1 g accleration
};
