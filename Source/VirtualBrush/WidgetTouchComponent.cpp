// Fill out your copyright notice in the Description page of Project Settings.

#include "WidgetTouchComponent.h"

#include "InputCoreTypes.h"

void UWidgetTouchComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsOverInteractableWidget() && !bIsClicked) // Rising edge of hover
	{
		PressPointerKey(EKeys::LeftMouseButton);
		bIsClicked = true;
	}
	if (!IsOverInteractableWidget() && bIsClicked) // Falling edge of hover
	{
		ReleasePointerKey(EKeys::LeftMouseButton);
		bIsClicked = false;
	}
}
