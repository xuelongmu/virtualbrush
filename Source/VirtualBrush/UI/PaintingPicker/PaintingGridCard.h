// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CoreMinimal.h"

#include "PaintingGridCard.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UPaintingGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPaintingName(FString Name);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UTextBlock* SlotName;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* CardButton;

private:
	UFUNCTION()
	void CardButtonClicked();

	//state
	UPROPERTY(VisibleAnywhere)
	FString SlotNameToLoad;
};
