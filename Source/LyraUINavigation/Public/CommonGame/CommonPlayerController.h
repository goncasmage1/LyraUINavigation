// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "UObject/UObjectGlobals.h"
#include "CommonPlayerController.generated.h"

class APawn;
class UObject;

// TODO: Remove?
UCLASS(config=Game)
class LYRAUINAVIGATION_API ACommonPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACommonPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void ReceivedPlayer() override;	
	virtual void SetPawn(APawn* InPawn) override;
	virtual void OnPossess(class APawn* APawn) override;
	virtual void OnUnPossess() override;
	
protected:
	virtual void OnRep_PlayerState() override;
};
