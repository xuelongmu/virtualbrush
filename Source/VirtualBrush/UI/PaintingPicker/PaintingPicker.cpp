// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingPicker.h"

#include "PaintingGrid.h"

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

	auto PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (PaintingGridWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("Painting grid found"));
		PaintingGridWidget->AddPainting();
	}
}
