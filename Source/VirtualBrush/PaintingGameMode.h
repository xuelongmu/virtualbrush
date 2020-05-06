// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PaintingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API APaintingGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void Save();
	void SaveAndQuit();
	void Load();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//State
	FString SlotName;
};
