// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "CoreMinimal.h"

#include "PaginationDot.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALBRUSH_API UPaginationDot : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetActive(bool IsActive);

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UImage* DotImage;

private:
	// configuration
	UPROPERTY(EditDefaultsOnly)
	float ActiveOpacity = 1.0;
	float InactiveOpacity = 0.4;
};
