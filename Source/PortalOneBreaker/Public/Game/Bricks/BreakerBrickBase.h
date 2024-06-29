// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Game/BreakerGameInteractableActorBase.h"
#include "UObject/Object.h"
#include "Utilities/BreakerInteractable.h"
#include "BreakerBrickBase.generated.h"

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
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
