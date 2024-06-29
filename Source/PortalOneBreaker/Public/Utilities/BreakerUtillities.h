// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/BreakerGameGameModeBase.h"
#include "Menu/BreakerMenuGameModeBase.h"
#include "UObject/Object.h"
#include "BreakerUtillities.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API UBreakerUtillities : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext="WorldContext"))
	static ABreakerMenuGameModeBase* GetBreakerMenuGameMode(const UObject* WorldContext);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext="WorldContext"))
	static ABreakerGameGameModeBase* GetBreakerGameMode(const UObject* WorldContext);
};
