// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetComponent.h"
#include "CoreMinimal.h"
#include "VirtualBrush/HandControllerBase.h"

#include "PaletteMenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API APaletteMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	APaletteMenuHandController();

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaletteMenu;
};
