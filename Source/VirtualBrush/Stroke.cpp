// Fill out your copyright notice in the Description page of Project Settings.

#include "Stroke.h"

#include "Engine/StaticMesh.h"

// Sets default values
AStroke::AStroke()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StrokeMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeMeshes"));
	StrokeMeshes->SetupAttachment(Root);

	JointMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("JointMeshes"));
	JointMeshes->SetupAttachment(Root);
}

void AStroke::Update(FVector CursorLocation)
{
	if (PreviousCursorLocation.IsNearlyZero())
	{
		PreviousCursorLocation = CursorLocation;
		JointMeshes->AddInstance(GetNextJointTransform(CursorLocation));
		return;
	}

	StrokeMeshes->AddInstance(GetNextSegmentTransform(CursorLocation));

	JointMeshes->AddInstance(GetNextJointTransform(CursorLocation));

	PreviousCursorLocation = CursorLocation;
}

FTransform AStroke::GetNextJointTransform(FVector CurrentLocation) const
{
	auto JointTransform = FTransform();
	JointTransform.SetLocation(GetActorTransform().InverseTransformPosition(CurrentLocation));
	return JointTransform;
}

FTransform AStroke::GetNextSegmentTransform(FVector CurrentLocation) const
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
