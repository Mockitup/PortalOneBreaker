// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalOneBreaker/Public/Game/BreakerGameGameModeBase.h"

#include "Kismet/GameplayStatics.h"

ABreakerGameGameModeBase::ABreakerGameGameModeBase()
{
	// Spawn components
	BrickSpawner = CreateDefaultSubobject<UBreakerBrickSpawner>(TEXT("Brick Spawner"));
}

void ABreakerGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeWidgets();

	StartGame();
}

void ABreakerGameGameModeBase::SetPlayerScore(int32 NewScore)
{
	PlayerScore = NewScore;
	OnPlayerScoreUpdated.Broadcast(PlayerScore);
}

void ABreakerGameGameModeBase::AddToPlayerScore(const int32 Amount)
{
	const int32 NewScore = PlayerScore + Amount;
	SetPlayerScore(NewScore);
}

void ABreakerGameGameModeBase::HandleBallDeath(ABreakerBallBase* Caller)
{
	ActiveBreakerBalls.Remove(Caller);
	if(ActiveBreakerBalls.Num() == 0)
	{
		EndGame();
	}
}

void ABreakerGameGameModeBase::InitializeWidgets()
{
	if(UUserWidget* MenuWidget = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), GameHUDWidgetClass))
	{
		MenuWidget->AddToViewport(0);
	}
}

void ABreakerGameGameModeBase::StartGame()
{
	// Spawn bricks and balls
	BrickSpawner->GenerateBricks();
	SpawnNewBall();
	
	//Activate all balls
	for(ABreakerBallBase* Ball : ActiveBreakerBalls)
	{
		Ball->bIsActive = true;
	}

	// Broadcast start
	OnGameStarted.Broadcast();
	
}

void ABreakerGameGameModeBase::EndGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game is done"));
	OnGameFinished.Broadcast();
}

void ABreakerGameGameModeBase::ResetGame()
{
	// Remove any remaining balls
	for(ABreakerBallBase* Ball : ActiveBreakerBalls)
	{
		Ball->Destroy();
	}
	// Cleanup bricks
	BrickSpawner->CleanUpBricks();
	// Reset player score
	SetPlayerScore(0);
	// Start game
	StartGame();
	
}

void ABreakerGameGameModeBase::SpawnNewBall()
{
	FVector SpawnLocation = BallSpawnLocation;
	FRotator SpawnRotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ABreakerBallBase* SpawnedBall = GetWorld()->SpawnActor<ABreakerBallBase>(BallClass, SpawnLocation, SpawnRotation, SpawnParameters);
	if(SpawnedBall)
	{
		SpawnedBall->OnBallDeath.AddDynamic(this, &ThisClass::HandleBallDeath);
		ActiveBreakerBalls.Add(SpawnedBall);
	}
	
}
