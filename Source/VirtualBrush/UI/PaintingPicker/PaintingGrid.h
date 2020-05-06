// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/UniformGridPanel.h"
#include "CoreMinimal.h"
#include "PaginationDot.h"
#include "PaintingGridCard.h"

#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 Index, FString Name);
	void ClearPaintings();
	void AddPaginationDot(bool IsActive);
	void ClearPaginationDots() const;

	int32 GetNumberOfSlots() const;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UHorizontalBox* PaginationDotBox;

private:
	// Configuration parameters
	UPROPERTY(EditDefaultsOnly)
	float PaginationDotPadding = 8.0;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaintingGridCard> GridCardClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaginationDot> PaginationDotClass;
};
