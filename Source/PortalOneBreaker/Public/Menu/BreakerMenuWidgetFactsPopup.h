// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BreakerMenuWidgetFactsPopup.generated.h"

/**
 * 
 */
UCLASS()
class PORTALONEBREAKER_API UBreakerMenuWidgetFactsPopup : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void RequestFact();

	UFUNCTION()
	void HandleFactResponse(bool bWasSuccessfull, const TArray<FString>& Result);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResponseRecieved(const FString& Result);
	
};
