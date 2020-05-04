// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BrushSaveGame.h"
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "BrushSaveGameIndex.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UBrushSaveGameIndex : public USaveGame
{
	GENERATED_BODY()

public:
	static UBrushSaveGameIndex* Load();
	bool Save();

	void AddSaveGame(UBrushSaveGame* SaveGame);

	TArray<FString> GetSlotNames() const { return SlotNames; }

private:
	static const FString INDEX_NAME;

	UPROPERTY(VisibleAnywhere)
	TArray<FString> SlotNames;
};
