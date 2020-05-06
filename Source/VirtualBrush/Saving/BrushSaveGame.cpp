// Fill out your copyright notice in the Description page of Project Settings.

#include "BrushSaveGame.h"

#include "BrushSaveGameIndex.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Guid.h"
#include "VirtualBrush/Stroke.h"

UBrushSaveGame* UBrushSaveGame::Create()
{
	auto NewSaveGame = Cast<UBrushSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	if (NewSaveGame)
	{
		NewSaveGame->SlotName = FGuid::NewGuid().ToString();
		if (!NewSaveGame->Save())
		{
			return nullptr;
		}
		UBrushSaveGameIndex* Index = UBrushSaveGameIndex::Load();
		Index->AddSaveGame(NewSaveGame);
		Index->Save();

		return NewSaveGame;
	}
	else
	{
		return nullptr;
	}
}

bool UBrushSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UBrushSaveGame* UBrushSaveGame::Load(FString SlotName)
{
	USaveGame* SaveGame = UGameplayStatics::LoadGameFromSlot(SlotName, 0);
	if (SaveGame)
	{
		return Cast<UBrushSaveGame>(SaveGame);
	}
	else
	{
		return nullptr;
	}
}

void UBrushSaveGame::SerializeFromWorld(UWorld* World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UBrushSaveGame::DeserializeToWorld(UWorld* World)
{
	// Clear existing strokes
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}

	// Spawn saved classes
	for (FStrokeState StrokeState : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
	}
}