// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "CoreMinimal.h"
#include "PaintingPicker.h"

#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UActionBar : public UUserWidget
{
	GENERATED_BODY()
public:
	bool Initialize() override;
	void SetParentPicker(APaintingPicker* NewParentPicker) { ParentPicker = NewParentPicker; }

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* AddButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* DeleteButton;

private:
	UFUNCTION()
	void AddButtonClicked();

	UFUNCTION()
	void DeleteButtonClicked();

	UPROPERTY()
	APaintingPicker* ParentPicker;
};