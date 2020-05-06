// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGridCard.h"

#include "Internationalization/Text.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"

void UPaintingGridCard::SetPaintingName(FString Name)
{
	// Check for valid SlotName happens in blueprint compilation stage
	SlotName->SetText(FText::FromString(Name));
	SlotNameToLoad = Name;
	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}

void UPaintingGridCard::CardButtonClicked()
{
	//TODO: Refactor magic string
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Canvas"), true, "SlotName=" + SlotNameToLoad);
}

