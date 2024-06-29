// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerGamePawn.h"


// Sets default values
ABreakerGamePawn::ABreakerGamePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakerGamePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakerGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABreakerGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

