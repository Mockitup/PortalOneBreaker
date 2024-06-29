// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bricks/BreakerBrickBase.h"

// Sets default values
ABreakerBrickBase::ABreakerBrickBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

// Called every frame
void ABreakerBrickBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}