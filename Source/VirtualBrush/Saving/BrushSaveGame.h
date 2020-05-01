// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BrushSaveGame.generated.h"

USTRUCT()
struct FStrokeState
{
	GENERATED_USTRUCT_BODY()

	// FStrokeState(const TSubclassOf<AStroke> InClass,  TArray<FVector> InControlPoints)
	//     : Class(InClass), ControlPoints(InControlPoints) {}
public: 
	UPROPERTY()
	TSubclassOf<class AStroke> Class;

	UPROPERTY()
	TArray<FVector> ControlPoints;
};

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
	TArray<FStrokeState> Strokes;
};
