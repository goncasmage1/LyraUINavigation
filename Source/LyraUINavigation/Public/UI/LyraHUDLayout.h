// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LyraActivatableWidget.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"

#include "LyraHUDLayout.generated.h"

class UCommonActivatableWidget;
class UObject;


/**
 * ULyraHUDLayout
 *
 *	Widget used to lay out the player's HUD (typically specified by an Add Widgets action in the experience)
 */
UCLASS(Abstract, BlueprintType, Blueprintable, Meta = (DisplayName = "Lyra HUD Layout", Category = "Lyra|HUD"))
class LYRAUINAVIGATION_API ULyraHUDLayout : public ULyraActivatableWidget
{
	GENERATED_BODY()

public:

	ULyraHUDLayout(const FObjectInitializer& ObjectInitializer);

	void NativeOnInitialized() override;

protected:
	void HandleEscapeAction();

	UPROPERTY(EditDefaultsOnly, Category = "Lyra HUD Layout")
	TSoftClassPtr<UCommonActivatableWidget> EscapeMenuClass;
};
