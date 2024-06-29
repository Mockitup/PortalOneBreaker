// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakerGameInteractableActorBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Utilities/BreakerInteractable.h"
#include "BreakerBallBase.generated.h"

// Used to handle Ball deaths
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBallDeath, ABreakerBallBase*, Caller);

UCLASS()
class PORTALONEBREAKER_API ABreakerBallBase : public ABreakerGameInteractableActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABreakerBallBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Ball")
	USphereComponent* SphereCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Ball")
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Breaker Ball")
	float Speed = 500.f;

	UPROPERTY(BlueprintReadOnly, Category = "Breaker Ball")
	FVector Direction;

	UPROPERTY(EditAnywhere, Category = "Breaker Ball")
	bool bIsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Breaker Ball")
	float ZKillLocation = -300.f;
	
	UPROPERTY(BlueprintAssignable)
	FOnBallDeath OnBallDeath;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Is used to reduce jitter in collisions.
	UPROPERTY()
	bool bHasInteractedThisFrame = false;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void CalculateNewDirection(const FHitResult& HitResult);

	UFUNCTION()
	void DestroyBall();
};
