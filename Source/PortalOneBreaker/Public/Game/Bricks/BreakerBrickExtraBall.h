// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakerBrickBase.h"
#include "BreakerBrickExtraBall.generated.h"

UCLASS()
class PORTALONEBREAKER_API ABreakerBrickExtraBall : public ABreakerBrickBase
{
	GENERATED_BODY()

public:
	virtual void HandleInteraction() override;
};
