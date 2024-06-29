// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Widget/BreakerGameHUD.h"

#include "Game/BreakerGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void UBreakerGameHUD::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind events from GameMode
	
	ABreakerGameGameModeBase* GameMode = Cast<ABreakerGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		GameMode->OnGameStarted.AddDynamic(this, &ThisClass::OnGameStarted);
		GameMode->OnGameFinished.AddDynamic(this, &ThisClass::OnGameFinished);
		GameMode->OnPlayerScoreUpdated.AddDynamic(this, &ThisClass::OnPlayerScoreUpdated);
	}
}
