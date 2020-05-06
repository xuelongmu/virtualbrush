// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Components/HorizontalBoxSlot.h"
#include "Components/SizeBox.h"
#include "Layout/Margin.h"

void UPaintingGrid::AddPainting(int32 Index, FString Name)
{
	// Check for valid PaintingGrid happens in blueprint compilation stage
	auto NewWidget = CreateWidget<UPaintingGridCard>(GetWorld(), GridCardClass);
	if (!NewWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to create new widget! Check that Grid Card Class is defined."));
		return;
	}
	NewWidget->SetPaintingName(Name);

	auto CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(Index % (GetNumberOfSlots())));
	// auto CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(Index));
	if (!CardContainer)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find child of Painting Grid, or cast it to SizeBox"));
	}
	CardContainer->AddChild(NewWidget);
}

void UPaintingGrid::ClearPaintings()
{
	for (auto i = 0; i < PaintingGrid->GetChildrenCount(); i++)
	{
		auto CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		if (!CardContainer)
		{
			continue;
		}
		CardContainer->ClearChildren();
	}
}

void UPaintingGrid::ClearPaginationDots() const
{
	PaginationDotBox->ClearChildren();
}

void UPaintingGrid::AddPaginationDot(bool IsActive)
{
	auto NewDot = CreateWidget<UPaginationDot>(GetWorld(), PaginationDotClass);
	if (!NewDot)
	{
		return;
	}
	NewDot->SetActive(IsActive);

	UHorizontalBoxSlot* BoxSlot = PaginationDotBox->AddChildToHorizontalBox(NewDot);
	BoxSlot->SetPadding(FMargin(PaginationDotPadding, 0));
}

int32 UPaintingGrid::GetNumberOfSlots() const
{
	return PaintingGrid->GetChildrenCount();
}
