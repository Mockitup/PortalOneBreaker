// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bricks/BreakerBrickBase.h"
#include "Components/ActorComponent.h"
#include "BreakerBrickSpawner.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PORTALONEBREAKER_API UBreakerBrickSpawner : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBreakerBrickSpawner();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	FVector BrickGridCenterLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	FVector2D BrickGridAmount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	FVector2D BrickSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	float BrickSpacing;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	TSubclassOf<ABreakerBrickBase> BrickBaseClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	TSubclassOf<ABreakerBrickBase> BrickSpecialClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick Spawner")
	float BrickSpecialChance;

	UPROPERTY()
	TArray<ABreakerBrickBase*> SpawnedBricks;
	
	UFUNCTION()
	void GenerateBricks();

	UFUNCTION()
	void CleanUpBricks();
};
