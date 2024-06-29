// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Components/ActorComponent.h"
#include "CatFacts.generated.h"


// Create event for when HTTP response gets back, allows other systems to handle them as they want.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRequestCompleted, bool, bWasSuccessful,const TArray<FString>&, Result);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PORTALONEBREAKER_API UCatFacts : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCatFacts();

protected:

	UPROPERTY()
	FString CatFactsEndPoint = "https://cat-fact.herokuapp.com/facts";

	FHttpModule* HttpModule;
	void HandleRequestCallback(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

public:

	UFUNCTION(BlueprintCallable, Category = "Cat Facts")
	void RequestCatFacts();

	UPROPERTY(BlueprintAssignable, Category = "Cat Facts")
	FOnRequestCompleted OnRequestCompleted;
	
};
