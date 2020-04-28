// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Stroke.generated.h"

UCLASS()
class VIRTUALBRUSH_API AStroke : public AActor
{
	GENERATED_BODY()

public:
	AStroke();

	void Update(FVector CursorLocation);

private:
	//helper
	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;
	FTransform GetNextJointTransform(FVector CurrentLocation) const;

	//components

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* StrokeMeshes;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* JointMeshes;

	//in world coordinates
	UPROPERTY(VisibleAnywhere)
	FVector PreviousCursorLocation = FVector::ZeroVector;
};
