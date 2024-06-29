// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/BreakerUtillities.h"

#include "Kismet/GameplayStatics.h"

ABreakerMenuGameModeBase* UBreakerUtillities::GetBreakerMenuGameMode(const UObject* WorldContext)
{
	return Cast<ABreakerMenuGameModeBase>(UGameplayStatics::GetGameMode(WorldContext));
}

ABreakerGameGameModeBase* UBreakerUtillities::GetBreakerGameMode(const UObject* WorldContext)
{
	return Cast<ABreakerGameGameModeBase>(UGameplayStatics::GetGameMode(WorldContext));
}
