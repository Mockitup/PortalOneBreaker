// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Utilities/CatFacts.h"
#include "BreakerMenuGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API ABreakerMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ABreakerMenuGameModeBase();
	
protected:
	virtual void BeginPlay();

public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<class UUserWidget> MenuWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Settings")
	FName GameMapName;

	UPROPERTY(BlueprintReadOnly, Category = "Utilities")
	UCatFacts* CatFactsComponent;
	
	UFUNCTION()
	void InitializeWidgets() const;

	UFUNCTION(BlueprintCallable)
	void LoadGameMap();
};
