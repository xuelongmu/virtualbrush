// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "Stroke.h"

#include "HandController.generated.h"

UCLASS()
class VIRTUALBRUSH_API AHandController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHandController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetHand(EControllerHand Hand) { MotionController->SetTrackingSource(Hand); }

	//methods
	void BeginStroke();
	void EndStroke();

	//components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

	//configuration parameters
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;

	//state
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;
};
