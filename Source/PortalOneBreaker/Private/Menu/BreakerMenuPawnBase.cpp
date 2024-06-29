// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/BreakerMenuPawnBase.h"


// Sets default values
ABreakerMenuPawnBase::ABreakerMenuPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakerMenuPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakerMenuPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABreakerMenuPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

