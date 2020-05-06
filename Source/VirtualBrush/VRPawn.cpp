// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

#include "EngineUtils.h"
#include "PaintingGameMode.h"
#include "VirtualBrush/UI/PaintingPicker/PaintingPicker.h"

// Sets default values
AVRPawn::AVRPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (RightHandControllerClass)
	{
		RightController = GetWorld()->SpawnActor<AHandControllerBase>(RightHandControllerClass);
		RightController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightController->SetHand(EControllerHand::Right);
		RightController->SetOwner(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("RightHandControllerClass not set up for %s"), *GetName());
	}
	if (LeftHandControllerClass)
	{
		LeftController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerClass);
		LeftController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		LeftController->SetHand(EControllerHand::Left);
		LeftController->SetOwner(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LeftHandControllerClass not set up for %s"), *GetName());
	}
}

// Called every frame
void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("StrokeRight"), IE_Pressed, this, &AVRPawn::TriggerPressedRight);
	PlayerInputComponent->BindAction(TEXT("StrokeRight"), IE_Released, this, &AVRPawn::TriggerReleasedRight);
	PlayerInputComponent->BindAxis(TEXT("PaginateRight_X"), this, &AVRPawn::PaginateRightAxisInput);
	PlayerInputComponent->BindAction(TEXT("TestInput"), IE_Pressed, this, &AVRPawn::TestInput);
}

void AVRPawn::PaginateRightAxisInput(float AxisValue)
{
	int32 RoundedAxisInput = FMath::RoundHalfFromZero(AxisValue);
	if (RoundedAxisInput != 0)
	{
		if (RoundedAxisInput != PreviousAxisInput)
		{
			UpdateCurrentPage(RoundedAxisInput);
			PreviousAxisInput = RoundedAxisInput;
		}
	}
	else
	{
		PreviousAxisInput = 0;
	}
}

void AVRPawn::UpdateCurrentPage(int32 Offset)
{
	for (TActorIterator<APaintingPicker> PaintingPickerItr(GetWorld()); PaintingPickerItr; ++PaintingPickerItr)
	{
		PaintingPickerItr->UpdateCurrentPage(Offset);
	}
}

void AVRPawn::TestInput()
{
	UE_LOG(LogTemp, Warning, TEXT("Test input triggered"));
}
