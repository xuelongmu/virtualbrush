// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "Components/SizeBox.h"

void UPaintingGrid::AddPainting()
{
	if (!PaintingGrid)
	{
		UE_LOG(LogTemp, Error, TEXT("Painting Grid not found."));
		return;
	}

	auto NewWidget = CreateWidget<UUserWidget>(GetWorld(), GridCardClass);
	if (!NewWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to create new widget! Check that Grid Card Class is defined."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Ref name: %s"), *PaintingGrid->GetName());
	auto CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(0));
	if (!CardContainer)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find child of Painting Grid, or cast it to SizeBox"));
	}
	CardContainer->AddChild(NewWidget);
}
