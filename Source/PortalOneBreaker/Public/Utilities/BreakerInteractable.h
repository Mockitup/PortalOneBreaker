// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BreakerInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UBreakerInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PORTALONEBREAKER_API IBreakerInteractable
{
	GENERATED_BODY()
public:


	// Used to interact with BreakerBall and different objects.
	virtual void OnInteraction(const AActor* CallingActor);
};
