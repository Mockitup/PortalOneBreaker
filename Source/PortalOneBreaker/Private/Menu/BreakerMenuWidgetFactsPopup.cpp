// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu/BreakerMenuWidgetFactsPopup.h"
#include "Kismet/GameplayStatics.h"
#include "Menu/BreakerMenuGameModeBase.h"

void UBreakerMenuWidgetFactsPopup::NativeConstruct()
{
	Super::NativeConstruct();
}

void UBreakerMenuWidgetFactsPopup::RequestFact()
{
	ABreakerMenuGameModeBase* GameMode = Cast<ABreakerMenuGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		GameMode->CatFactsComponent->OnRequestCompleted.AddDynamic(this, &ThisClass::HandleFactResponse);
		GameMode->CatFactsComponent->RequestCatFacts();
	}
}

void UBreakerMenuWidgetFactsPopup::HandleFactResponse(bool bWasSuccesfull, const TArray<FString>& Result)
{
	if(bWasSuccesfull)
	{
		OnResponseRecieved(Result[FMath::RandRange(0, Result.Num())]);
	} else
	{
		OnResponseRecieved(Result[0]);
	}
}

