// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetInteractionComponent.h"
#include "CoreMinimal.h"

#include "WidgetTouchComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class VIRTUALBRUSH_API UWidgetTouchComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()
public:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//state
	UPROPERTY(VisibleAnywhere)
	bool bIsClicked = false;
};
