// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bricks/BreakerBrickExtraBall.h"

#include "Game/BreakerGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"


void ABreakerBrickExtraBall::HandleInteraction()
{
	Super::HandleInteraction();
	ABreakerGameGameModeBase* GameMode = Cast<ABreakerGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		GameMode->SpawnNewBall();
	}
}
