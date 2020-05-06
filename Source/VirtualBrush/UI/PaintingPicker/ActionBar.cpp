// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionBar.h"

bool UActionBar::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	AddButton->OnClicked.AddDynamic(this, &UActionBar::AddButtonClicked);
	DeleteButton->OnClicked.AddDynamic(this, &UActionBar::DeleteButtonClicked);
	return true;
}

void UActionBar::AddButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Add button clicked"));
	if (!ParentPicker)
	{
		return;
	}
	ParentPicker->AddPainting();
}

void UActionBar::DeleteButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Delete button clicked"));
	if (!ParentPicker)
	{
		return;
	}
	ParentPicker->ToggleDeleteMode();
}
