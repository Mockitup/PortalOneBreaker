// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakerBallBase.h"
#include "BreakerBrickSpawner.h"
#include "GameFramework/GameModeBase.h"
#include "Widget/BreakerGameHUD.h"
#include "BreakerGameGameModeBase.generated.h"


// Create events for player score update
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerScoreUpdated, int32, Score);

// Create events for OnGameStarted
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStarted);
// Create events for OnGameFinished
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameFinished);

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API ABreakerGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ABreakerGameGameModeBase();

public:

	virtual void BeginPlay() override;
	
	// Brick Generator
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Game")
	UBreakerBrickSpawner* BrickSpawner;
	
	// Score related variables
	UPROPERTY(BlueprintReadOnly, Category = "Breaker Game")
	int32 PlayerScore;

	UFUNCTION()
	void SetPlayerScore(int32 NewScore);

	UPROPERTY(BlueprintAssignable, Category = "Breaker Game")
	FOnPlayerScoreUpdated OnPlayerScoreUpdated;

	// UI Related variables
	UPROPERTY(EditAnywhere, Category = "Breaker Game")
	TSubclassOf<UBreakerGameHUD> GameHUDWidgetClass;
	
	// Game play related variables
	UPROPERTY(BlueprintAssignable, Category = "Breaker Game")
	FOnGameStarted OnGameStarted;

	UPROPERTY(BlueprintAssignable, Category = "Breaker Game")
	FOnGameStarted OnGameFinished;

	// Ball Related variables
	
	UPROPERTY(EditAnywhere, Category = "Breaker Game")
	FVector BallSpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Breaker Game")
	TSubclassOf<ABreakerBallBase> BallClass;


	// Functions
	UFUNCTION()
	void InitializeWidgets();
	
	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void EndGame();

	UFUNCTION(BlueprintCallable)
	void ResetGame();
	
	UFUNCTION(BlueprintCallable, Category = "Breaker Game")
	void SpawnNewBall();

	UFUNCTION(BlueprintCallable, Category = "Breaker Game")
	void AddToPlayerScore(int32 Amount);
	
private:
	// Balls in play
	UPROPERTY()
	TArray<ABreakerBallBase*> ActiveBreakerBalls;

	UFUNCTION()
	void HandleBallDeath(ABreakerBallBase* Caller);
};
