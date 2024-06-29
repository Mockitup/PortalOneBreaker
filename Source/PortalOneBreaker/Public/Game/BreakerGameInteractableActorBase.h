// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Utilities/BreakerInteractable.h"
#include "BreakerGameInteractableActorBase.generated.h"

UCLASS()
class PORTALONEBREAKER_API ABreakerGameInteractableActorBase : public AActor, public IBreakerInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABreakerGameInteractableActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteraction(const AActor* CallingActor) override;
};
