// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HandController.h"

#include "VRPawn.generated.h"

UCLASS()
class VIRTUALBRUSH_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//callbacks
	void BeginStrokeRight()
	{
		if (RightController)
		{
			RightController->BeginStroke();
		}
	}

	void EndStrokeRight()
	{
		if (RightController)
		{
			RightController->EndStroke();
		}
	}

	void Save();
	void Load();

	//components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	//references
	UPROPERTY(VisibleAnywhere)
	AHandController* LeftController;

	UPROPERTY(VisibleAnywhere)
	AHandController* RightController;

	// configuration parameters
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandController> HandControllerClass;
};
