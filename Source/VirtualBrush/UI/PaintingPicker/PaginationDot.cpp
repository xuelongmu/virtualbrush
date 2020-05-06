// Fill out your copyright notice in the Description page of Project Settings.

#include "PaginationDot.h"

void UPaginationDot::SetActive(bool IsActive)
{
	DotImage->SetOpacity(IsActive ? ActiveOpacity : InactiveOpacity);
}
