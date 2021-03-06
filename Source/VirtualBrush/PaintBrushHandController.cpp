// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintBrushHandController.h"

// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}
}

// Begin brush stroke
void APaintBrushHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass, GetActorLocation(), FRotator::ZeroRotator);
}

// End brush stroke
void APaintBrushHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}