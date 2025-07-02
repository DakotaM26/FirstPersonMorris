// Copyright Epic Games, Inc. All Rights Reserved.


#include "FirstPersonMorrisPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "FirstPersonMorrisCameraManager.h"

AFirstPersonMorrisPlayerController::AFirstPersonMorrisPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AFirstPersonMorrisCameraManager::StaticClass();
}

void AFirstPersonMorrisPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
