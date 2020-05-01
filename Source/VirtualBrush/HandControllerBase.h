// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"

#include "HandControllerBase.generated.h"

UCLASS()
class VIRTUALBRUSH_API AHandControllerBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHandControllerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetHand(EControllerHand Hand) { MotionController->SetTrackingSource(Hand); }
	virtual void TriggerPressed() { UE_LOG(LogTemp, Error, TEXT("TriggerPressed not overridden in child HandController class")) }
	virtual void TriggerReleased() { UE_LOG(LogTemp, Error, TEXT("TriggerReleased not overridden in child HandController class")) }

public:
	//components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;
};
