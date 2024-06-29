// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerGamePawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ABreakerGamePawn::ABreakerGamePawn()
{
	// We dont need tick on this actor, as we only use inputs
	PrimaryActorTick.bCanEverTick = false;

	// Spawn standard components

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	CameraSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraSpring->SetupAttachment(Root);
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PlayerCamera->SetupAttachment(CameraSpring);

	PaddleRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Paddle Root"));
	PaddleRoot->SetupAttachment(Root);
	
	PaddleCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Paddle Collider"));
	PaddleCollision->SetCollisionProfileName("OverlapAllDynamic");
	PaddleCollision->SetGenerateOverlapEvents(true);
	PaddleCollision->SetupAttachment(PaddleRoot);

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	PaddleMesh->SetupAttachment(PaddleCollision);
	PaddleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called when the game starts or when spawned
void ABreakerGamePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ABreakerGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Setup Context
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if(PlayerController)
	{
		if(UEnhancedInputLocalPlayerSubsystem* EISubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			UE_LOG(LogTemp, Warning, TEXT("ADDED INPUIT CONTEXT"));
			EISubSystem->AddMappingContext(InputMappingContext, 0);
		}
	}
	// Add Input Bindings
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		
		EnhancedInputComponent->BindAction(InputStrafe, ETriggerEvent::Triggered, this, &ThisClass::AddStrafeInput);
	}
}

void ABreakerGamePawn::AddStrafeInput(const FInputActionValue& Value)
{
	const float StrafeValue = Value.Get<float>();
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	
	const FVector PaddleRootLocation = PaddleRoot->GetComponentLocation();

	// Check if we're trying to escape positive bounds 
	if(StrafeValue > 0 && PaddleRootLocation.Y > PaddleMaxBounds)
	{
		// Deny action
		return;
	}
	// Check if we're trying to escape negative bounds 
	if(StrafeValue < 0 && PaddleRootLocation.Y < PaddleMaxBounds*-1.f)
	{
		// Deny action
		return;
	}

	// Calculate new position
	FVector NewLocation = PaddleRootLocation + FVector(0.f, StrafeValue * PaddleSpeed * DeltaTime, 0.f);
	NewLocation.Y = FMath::Clamp(NewLocation.Y, PaddleMaxBounds*-1, PaddleMaxBounds);
	PaddleRoot->SetWorldLocation(NewLocation);
	
}

