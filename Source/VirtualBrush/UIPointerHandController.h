// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetInteractionComponent.h"
#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "UIPointerHandController.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API AUIPointerHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUIPointerHandController();
	void TriggerPressed() override;
	void TriggerReleased() override;

private:
	//components
	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* Pointer;
};
