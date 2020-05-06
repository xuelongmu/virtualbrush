// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "CoreMinimal.h"

#include "PaletteMenu.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UPaletteMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UButton* BackButton;

private:
	UFUNCTION()
	void BackButtonClicked();
};
