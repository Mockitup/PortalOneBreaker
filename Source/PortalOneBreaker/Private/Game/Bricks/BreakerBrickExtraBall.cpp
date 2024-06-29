// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bricks/BreakerBrickExtraBall.h"


// Sets default values
ABreakerBrickExtraBall::ABreakerBrickExtraBall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakerBrickExtraBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakerBrickExtraBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

