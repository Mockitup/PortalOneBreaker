// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerGameInteractableActorBase.h"


// Sets default values
ABreakerGameInteractableActorBase::ABreakerGameInteractableActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakerGameInteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakerGameInteractableActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABreakerGameInteractableActorBase::OnInteraction(const AActor* CallingActor)
{
	IBreakerInteractable::OnInteraction(CallingActor);
}

