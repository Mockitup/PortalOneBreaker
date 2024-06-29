// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Game/BreakerGameInteractableActorBase.h"
#include "UObject/Object.h"
#include "Utilities/BreakerInteractable.h"
#include "BreakerBrickBase.generated.h"


// Used to handle Brick deaths
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBrickDeath, ABreakerBrickBase*, Caller);

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API ABreakerBrickBase : public ABreakerGameInteractableActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABreakerBrickBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Brick")
	UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Brick")
	UStaticMeshComponent* BrickMesh;

	UPROPERTY(BlueprintAssignable)
	FOnBrickDeath OnBrickDeath;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Breaker Brick")
	int32 ScoreReward = 1;
	
	// From Interaction Interface
	virtual void OnInteraction(const AActor* CallingActor) override;

	// Handles reward and deletion, and evnetual effects.
	UFUNCTION()
	virtual void HandleInteraction();
	
};
