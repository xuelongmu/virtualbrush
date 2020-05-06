// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Saving/BrushSaveGame.h"

void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");
	UE_LOG(LogTemp, Warning, TEXT("SlotName: %s"), *SlotName);
}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();
	Load();
}

void APaintingGameMode::Save()
{
	auto PaintingSave = UBrushSaveGame::Load(SlotName);
	if (PaintingSave)
	{
		PaintingSave->SerializeFromWorld(GetWorld());
		PaintingSave->Save();
	}
}

void APaintingGameMode::SaveAndQuit()
{
	Save();
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"), false);
}

void APaintingGameMode::Load()
{
	auto PaintingSave = UBrushSaveGame::Load(SlotName);
	if (PaintingSave)
	{
		PaintingSave->DeserializeToWorld(GetWorld());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SlotName Not Found: %s"), *SlotName);
	}
}
