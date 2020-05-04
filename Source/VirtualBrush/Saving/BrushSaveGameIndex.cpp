// Fill out your copyright notice in the Description page of Project Settings.

#include "BrushSaveGameIndex.h"

#include "Kismet/GameplayStatics.h"

const FString UBrushSaveGameIndex::INDEX_NAME = "Index";

UBrushSaveGameIndex*
UBrushSaveGameIndex::Load()
{
	auto Index = Cast<UBrushSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(INDEX_NAME, 0));
	if (!Index)
	{
		Index = Cast<UBrushSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
		if (!Index->Save())
		{
			return nullptr;
		}
	}
	return Index;
}

bool UBrushSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, INDEX_NAME, 0);
}

void UBrushSaveGameIndex::AddSaveGame(UBrushSaveGame* SaveGame)
{
	SlotNames.Add(SaveGame->GetSlotName());
}
