// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakerBrickBase.h"
#include "BreakerBrickNormal.generated.h"

UCLASS()
class PORTALONEBREAKER_API ABreakerBrickNormal : public ABreakerBrickBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABreakerBrickNormal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
