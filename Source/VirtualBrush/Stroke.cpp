// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"

#include "Engine/StaticMesh.h"

// Sets default values
AStroke::AStroke()
{
	PrimaryActorTick.bCanEverTick = true;

	StrokeInstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeInstanceMesh"));
	StrokeInstancedMesh->SetupAttachment(GetRootComponent());
}

void AStroke::Update(FVector CursorLocation)
{
	if (PreviousCursorLocation == FVector::ZeroVector)
	{
		PreviousCursorLocation = CursorLocation;
	}

	StrokeInstancedMesh->AddInstance(GetNextSegmentTransform(CursorLocation));

	PreviousCursorLocation = CursorLocation;
}

FTransform AStroke::GetNextSegmentTransform(FVector CurrentLocation)
{
	auto SegmentTransform = FTransform();

	//get location, starting point
	auto StartLocation = GetActorTransform().InverseTransformPosition(PreviousCursorLocation);
	auto EndLocation = GetActorTransform().InverseTransformPosition(CurrentLocation);
	SegmentTransform.SetLocation(StartLocation);

	//get rotation, the rotation between forward vector and the segment's rotation
	auto Segment = EndLocation - StartLocation;
	auto SegmentNormal = Segment.GetSafeNormal();
	auto Rotation = FQuat::FindBetweenNormals(FVector::ForwardVector, SegmentNormal);
	SegmentTransform.SetRotation(Rotation);

	//get scale, from beginning to end of stroke
	SegmentTransform.SetScale3D(FVector(Segment.Size(), 1, 1));

	return SegmentTransform;
}
