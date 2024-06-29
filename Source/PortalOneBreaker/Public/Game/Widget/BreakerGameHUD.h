// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BreakerGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API UBreakerGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Breaker Game HUD")
	void OnGameStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnGameFinished();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerScoreUpdated(int Score);
	
	virtual void NativeConstruct() override;
};
