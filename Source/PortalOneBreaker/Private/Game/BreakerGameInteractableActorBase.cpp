// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerGameInteractableActorBase.h"


// Sets default values
ABreakerGameInteractableActorBase::ABreakerGameInteractableActorBase()
{
	// We dont need tick on this actor.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABreakerGameInteractableActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}
void ABreakerGameInteractableActorBase::OnInteraction(const AActor* CallingActor)
{
	IBreakerInteractable::OnInteraction(CallingActor);
}

