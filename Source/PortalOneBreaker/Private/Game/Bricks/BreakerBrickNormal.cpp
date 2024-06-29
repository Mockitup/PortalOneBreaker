// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bricks/BreakerBrickNormal.h"


// Sets default values
ABreakerBrickNormal::ABreakerBrickNormal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakerBrickNormal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakerBrickNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

