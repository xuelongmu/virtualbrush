// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaintingGrid.h"

#include "PaintingPicker.generated.h"

UCLASS()
class VIRTUALBRUSH_API APaintingPicker : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APaintingPicker();
	void AddPainting();
	void ToggleDeleteMode();

	void UpdateCurrentPage(int32 Offset);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Refresh()
	{
		RefreshSlots();
		RefreshDots();
	}
	void RefreshSlots();
	void RefreshDots();
	int32 GetNumberOfPages() const;

	// Components
	UPROPERTY(VIsibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaintingGrid;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* ActionBar;

	UPaintingGrid* PaintingGridReference;

	// state
	bool bDeleteModeEnabled;

	int32 CurrentPage = 0;
};
