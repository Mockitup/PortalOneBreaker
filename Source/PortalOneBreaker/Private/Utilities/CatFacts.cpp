// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalOneBreaker/Public/Utilities/CatFacts.h"

#include "Interfaces/IHttpResponse.h"


// Sets default values for this component's properties
UCatFacts::UCatFacts()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
	HttpModule = &FHttpModule::Get();
}

void UCatFacts::HandleRequestCallback(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	// Create return array of FStrings, used for both facts and potential error messages
	TArray<FString> ReturnArray;
	bool ReturnSuccessfully = false;
	
	TSharedPtr<FJsonObject> JsonObject;
	if(Response->GetResponseCode() == 200)
	{
		UE_LOG(LogTemp, Warning, TEXT("successful response"));
		// Response was successful
		FString ResponseBody = Response->GetContentAsString();

		// Have to fix root node case, causing deserializer to fail.
		if(ResponseBody[0] == '[')
		{
			ResponseBody = FString("{\"root\":") + ResponseBody + '}';
		}
		TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(ResponseBody);
		// Attempt to process JSON body
		if(FJsonSerializer::Deserialize(Reader, JsonObject))
		{
			// Get root array
			TArray<TSharedPtr<FJsonValue>> FactObjectsArray = JsonObject->GetArrayField("root");

			// Loop all over array of objects and extract text
			for(const TSharedPtr<FJsonValue> FactValue : FactObjectsArray)
			{
				TSharedPtr<FJsonObject> FactObject = FactValue->AsObject();
				ReturnArray.Add(FactObject->GetStringField("text"));
			}

			if(!ReturnArray.IsEmpty())
			{
				// Return successfully
				ReturnSuccessfully = true;
			} else {
				// Handle an empty array, due to failed JSON extraction.
				ReturnArray.Add("Unable to fetch any facts");
			}
		} else
		{
			// Failed to process JSON body, return with error
			ReturnArray.Add("Unable to fetch any facts, invalid response");
		}
	} else
	{
		// Handle unsuccessful response
		UE_LOG(LogTemp, Warning, TEXT("unsuccessful response"));
		// Failed to process JSON body, return with error
		ReturnArray.Add("Unable to fetch any facts, end point didn't respond");
	}
	//Broadcast result with whatever happened.
	OnRequestCompleted.Broadcast(ReturnSuccessfully, ReturnArray);
}


void UCatFacts::RequestCatFacts()
{

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = HttpModule->CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::HandleRequestCallback);
	Request->SetURL(CatFactsEndPoint);
	Request->SetVerb("GET");
	Request->SetHeader("User-Agent", "X-UnrealEngine-Agent");
	Request->SetHeader("Content-Type", "application/json");
	Request->ProcessRequest();
	
}

