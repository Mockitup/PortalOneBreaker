// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "BreakerGamePawn.generated.h"

UCLASS()
class PORTALONEBREAKER_API ABreakerGamePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABreakerGamePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Components
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	USpringArmComponent* CameraSpring;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	UCameraComponent* PlayerCamera;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	USceneComponent* PaddleRoot;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	UBoxComponent* PaddleCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Breaker Pawn")
	UStaticMeshComponent* PaddleMesh;

	// Gameplay variables
	UPROPERTY(EditAnywhere, Category = "Breaker Pawn")
	float PaddleSpeed;

	UPROPERTY(EditAnywhere, Category = "Breaker Pawn")
	float PaddleMaxBounds = 500.f;

	UPROPERTY(EditAnywhere, Category = "Breaker Pawn")
	float PaddleBoundsTolerance = 0.25f;
	
	// Input mappings for bindings
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Breaker Pawn")
	class UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Breaker Pawn")
	class UInputAction* InputStrafe;

	// Setup for Input
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	void AddStrafeInput(const FInputActionValue& Value);
};
