// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerBallBase.h"

#include "Game/BreakerGamePawn.h"


// Sets default values
ABreakerBallBase::ABreakerBallBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Spawn standard components
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Ball Collider"));
	SphereCollider->SetCollisionProfileName("OverlapAllDynamic");
	SphereCollider->SetGenerateOverlapEvents(true);
	SetRootComponent(SphereCollider);

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(SphereCollider);
	BallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Set Initial Direction, which is always up with a slight variation
	Direction = FVector(0.f, FMath::RandRange(-0.5f, 0.5f), 1.f);
	Direction.Normalize();
}

// Called when the game starts or when spawned
void ABreakerBallBase::BeginPlay()
{
	Super::BeginPlay();

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	
}

// Called every frame
void ABreakerBallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Only move the ball if the game has actually started
	if(bIsActive)
	{
		bHasInteractedThisFrame = false;
		
		const FVector Offset = Direction * Speed * DeltaTime;
		AddActorWorldOffset(Offset, true);
		if(GetActorLocation().Z <= ZKillLocation)
		{
			DestroyBall();
		}
	}

}

void ABreakerBallBase::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if this frame already handled collisions
	if(bHasInteractedThisFrame)
	{
		return;
	}
	
	// Calculate new direction
	if(bFromSweep)
	{
		CalculateNewDirection(SweepResult);
	}
	// Check if other actor is interactable
	if(OtherActor->GetClass()->ImplementsInterface(UBreakerInteractable::StaticClass()))
	{
		// Cast OnInteracted to other actor.
		Cast<IBreakerInteractable>(OtherActor)->OnInteraction(this);
	}

	bHasInteractedThisFrame = true;
}

void ABreakerBallBase::CalculateNewDirection(const FHitResult& HitResult)
{
	// Calculate reflection vector from HitResult
	// If we hit the pawn, we try to allow the player more control based on distance from the root.
	if(HitResult.GetActor()->GetClass()->IsChildOf(APawn::StaticClass()))
	{
		ABreakerGamePawn* GamePawn = Cast<ABreakerGamePawn>(HitResult.GetActor());
		if(GamePawn)
		{
			FVector PaddleLocation = GamePawn->PaddleRoot->GetComponentLocation();
			float DistanceToPaddleCenter = (GetActorLocation()-PaddleLocation).Length();
			float DistanceMultiplier = FMath::GetMappedRangeValueClamped(FVector2D(0.f, 50.f), FVector2D(1.0f, 0.5f), DistanceToPaddleCenter);
			
			FVector ModifiedDirection = Direction * FVector(1.f,1.f+(1-DistanceMultiplier),DistanceMultiplier);
			ModifiedDirection.Normalize();
			Direction = FMath::GetReflectionVector(ModifiedDirection, HitResult.ImpactNormal);
			return;
		}
	}
	// If not a pawn, just do simple reflection math
	Direction = FMath::GetReflectionVector(Direction, HitResult.ImpactNormal);
}

void ABreakerBallBase::DestroyBall()
{
	OnBallDeath.Broadcast(this);
	this->Destroy();
}

