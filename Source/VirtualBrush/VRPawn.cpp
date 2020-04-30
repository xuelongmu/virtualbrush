// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"

#include "Saving/BrushSaveGame.h"

// Sets default values
AVRPawn::AVRPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	// VRRoot->SetupAttachment(GetRootComponent());
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (HandControllerClass)
	{
		// LeftController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
		// LeftController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		// LeftController->SetHand(EControllerHand::Left);
		// LeftController->SetOwner(this);

		RightController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
		RightController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightController->SetHand(EControllerHand::Right);
		RightController->SetOwner(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HandControllerClass not set up for %s"), *GetName());
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
	PlayerInputComponent->BindAction(TEXT("StrokeRight"), IE_Pressed, this, &AVRPawn::BeginStrokeRight);
	PlayerInputComponent->BindAction(TEXT("StrokeRight"), IE_Released, this, &AVRPawn::EndStrokeRight);
	PlayerInputComponent->BindAction(TEXT("Save"), IE_Released, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), IE_Released, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	auto SaveGame = UBrushSaveGame::Create();
	// SaveGame->RightController = RightController;
	SaveGame->SerializeFromWorld(GetWorld());
	SaveGame->Save();
}

void AVRPawn::Load()
{
	auto SaveGame = UBrushSaveGame::Load();
	if (SaveGame)
	{
		// auto TestController = SaveGame->RightController;

		// UE_LOG(LogTemp, Warning, TEXT("Controller found: %s"), *TestController->GetName());
		SaveGame->DeserializeToWorld(GetWorld());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Save Game Not Found"));
	}
}