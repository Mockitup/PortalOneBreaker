// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerBrickSpawner.h"


UBreakerBrickSpawner::UBreakerBrickSpawner()
{
}

void UBreakerBrickSpawner::GenerateBricks()
{
	// Calculate Grid bounds to make centering easier
	const FVector GridSize = FVector(0.f, BrickGridAmount.X*BrickSize.X+(BrickGridAmount.X*BrickSpacing), BrickGridAmount.Y*BrickSize.Y+(BrickGridAmount.Y*BrickSpacing));
	const FVector GridStartLocation = BrickGridCenterLocation - (GridSize/2.f);
	
	for (int32 x = 0; x < BrickGridAmount.X; ++x)
	{
		for (int32 y = 0; y < BrickGridAmount.Y; ++y)
		{
			// Calculate spawn locations, rotations and spawn new bricks
			FVector SpawnLocation = GridStartLocation + FVector(0.f, x * BrickSize.X + (x * BrickSpacing), y * BrickSize.Y + (y * BrickSpacing));
			FRotator SpawnRotation = FRotator::ZeroRotator;
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			TSubclassOf<ABreakerBrickBase> BrickClass = (FMath::RandRange(0.f, 1.f) <= BrickSpecialChance) ? BrickSpecialClass : BrickBaseClass;

			ABreakerBrickBase* SpawnedBrick = GetWorld()->SpawnActor<ABreakerBrickBase>(BrickClass, SpawnLocation, SpawnRotation, SpawnParameters);
			if(SpawnedBrick)
			{
				SpawnedBricks.Add(SpawnedBrick);
			}
		}
	}
	
}

void UBreakerBrickSpawner::CleanUpBricks()
{
	for(ABreakerBrickBase* Brick : SpawnedBricks)
	{
		if(IsValid(Brick))
		{
			Brick->Destroy();
		}
	}
	SpawnedBricks.Empty();
}

