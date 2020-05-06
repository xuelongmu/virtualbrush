// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "ActionBar.h"
#include "Math/UnrealMathUtility.h"
#include "VirtualBrush/Saving/BrushSaveGame.h"
#include "VirtualBrush/Saving/BrushSaveGameIndex.h"

// Sets default values
APaintingPicker::APaintingPicker()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	PaintingGridReference = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridReference)
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find painting grid!"));
	}

	auto ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}

	Refresh();
}

void APaintingPicker::UpdateCurrentPage(int32 Offset)
{
	CurrentPage = FMath::Clamp(CurrentPage + Offset, 0, GetNumberOfPages() - 1);
	Refresh();
}

void APaintingPicker::RefreshSlots()
{
	if (!PaintingGridReference)
	{
		return;
	}

	PaintingGridReference->ClearPaintings();

	auto SaveGameIndex = UBrushSaveGameIndex::Load();
	if (!SaveGameIndex)
	{
		return;
	}
	auto SlotNames = SaveGameIndex->GetSlotNames();

	int32 NumberOfSlots = PaintingGridReference->GetNumberOfSlots();
	int32 StartOffset = CurrentPage * NumberOfSlots;

	// Ensure we don't go out of bounds on the last page
	for (int32 i = StartOffset; i < StartOffset + NumberOfSlots && i < SlotNames.Num(); i++)
	{
		PaintingGridReference->AddPainting(i, SlotNames[i]);
	}
}

void APaintingPicker::RefreshDots()
{
	//clear horizontal box
	if (!PaintingGridReference)
	{
		return;
	}
	PaintingGridReference->ClearPaginationDots();

	for (int i = 0; i < GetNumberOfPages(); i++)
	{
		// Set active to true if i matches current page
		PaintingGridReference->AddPaginationDot(i == CurrentPage);
	}
}

void APaintingPicker::AddPainting()
{
	UBrushSaveGame::Create();
	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	bDeleteModeEnabled = !bDeleteModeEnabled;
}

int32 APaintingPicker::GetNumberOfPages() const
{
	auto Saves = UBrushSaveGameIndex::Load()->GetSlotNames().Num();
	if (!PaintingGridReference)
	{
		return 0;
	}
	auto SlotsPerPage = PaintingGridReference->GetNumberOfSlots();

	return FMath::CeilToInt((double)Saves / (double)SlotsPerPage);
}