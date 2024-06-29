// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalOneBreaker/Public/Menu/BreakerMenuGameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

ABreakerMenuGameModeBase::ABreakerMenuGameModeBase()
{
	CatFactsComponent = CreateDefaultSubobject<UCatFacts>(TEXT("Cat Facts Component"));
}

void ABreakerMenuGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin play"));
	InitializeWidgets();
}

void ABreakerMenuGameModeBase::InitializeWidgets() const
{
	UE_LOG(LogTemp, Warning, TEXT("initialize widgets"));
	if(UUserWidget* MenuWidget = CreateWidget(UGameplayStatics::GetPlayerController(GetWorld(), 0), MenuWidgetClass))
	{
		MenuWidget->AddToViewport(0);
	}
}

void ABreakerMenuGameModeBase::LoadGameMap()
{
	UWorld* World = GetWorld();
	UGameplayStatics::OpenLevel(GetWorld(), GameMapName , true);
}
