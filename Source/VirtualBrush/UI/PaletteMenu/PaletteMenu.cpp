// Fill out your copyright notice in the Description page of Project Settings.

#include "PaletteMenu.h"

#include "Engine/World.h"
#include "VirtualBrush/PaintingGameMode.h"

bool UPaletteMenu::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	BackButton->OnPressed.AddDynamic(this, &UPaletteMenu::BackButtonClicked);
	return true;
}

void UPaletteMenu::BackButtonClicked()
{
	auto GameMode = Cast<APaintingGameMode>(GetWorld()->GetAuthGameMode());
	if (!GameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to load GameMode from World!"))
		return;
	}
	GameMode->SaveAndQuit();
}
