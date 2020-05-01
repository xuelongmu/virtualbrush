// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineMeshComponent.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Saving/BrushSaveGame.h"

#include "Stroke.generated.h"

UCLASS()
class VIRTUALBRUSH_API AStroke : public AActor
{
	GENERATED_BODY()

public:
	AStroke();

	void Update(FVector CursorLocation);

	FStrokeState SerializeToStruct() const;

	static AStroke* SpawnAndDeserializeFromStruct(UWorld* World, const FStrokeState& StrokeState);

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

	UPROPERTY(VisibleAnywhere)
	TArray<FVector> ControlPoints;
};
