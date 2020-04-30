// Fill out your copyright notice in the Description page of Project Settings.

#include "BrushSaveGame.h"

#include "../Stroke.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

UBrushSaveGame* UBrushSaveGame::Create()
{
	USaveGame* SaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	if (SaveGame)
	{
		return Cast<UBrushSaveGame>(SaveGame);
	}
	else
	{
		return nullptr;
	}
}

bool UBrushSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}

UBrushSaveGame* UBrushSaveGame::Load()
{
	USaveGame* SaveGame = UGameplayStatics::LoadGameFromSlot(TEXT("Test"), 0);
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
		//TODO:Serialize
		Strokes.Add(StrokeItr->GetClass());
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
	for (auto StrokeClass : Strokes)
	{
		World->SpawnActor<AStroke>(StrokeClass);
	}
}