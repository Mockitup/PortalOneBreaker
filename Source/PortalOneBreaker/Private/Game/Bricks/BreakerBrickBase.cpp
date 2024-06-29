// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bricks/BreakerBrickBase.h"

#include "Game/BreakerGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABreakerBrickBase::ABreakerBrickBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Spawn standard components
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Brick Collider"));
	BoxCollider->SetCollisionProfileName("OverlapAllDynamic");
	BoxCollider->SetGenerateOverlapEvents(true);
	SetRootComponent(BoxCollider);

	BrickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BrickMesh->SetupAttachment(BoxCollider);
	BrickMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ABreakerBrickBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABreakerBrickBase::OnInteraction(const AActor* CallingActor)
{
	Super::OnInteraction(CallingActor);
	HandleInteraction();
}

void ABreakerBrickBase::HandleInteraction()
{
	ABreakerGameGameModeBase* GameMode = Cast<ABreakerGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		GameMode->AddToPlayerScore(ScoreReward);
	}
	// Call delegate
	OnBrickDeath.Broadcast(this);
	// Destroy object
	this->Destroy();
}
