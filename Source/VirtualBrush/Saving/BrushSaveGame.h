// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "../HandController.h"

#include "BrushSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UBrushSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	static UBrushSaveGame* Create();
	bool Save();
	static UBrushSaveGame* Load(); //TODO: add save location
	void SerializeFromWorld(UWorld* World);
	void DeserializeToWorld(UWorld* World);

	UPROPERTY(VisibleAnywhere)
	AHandController* RightController;

	UPROPERTY(VisibleAnywhere)
	TArray<TSubclassOf<AStroke>> Strokes;
};
