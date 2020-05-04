// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "CoreMinimal.h"

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
	void AddPainting();

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel* PaintingGrid;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> GridCardClass;
};
