// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/PanelSlot.h"
#include "SGameResponsivePanel.h"
#include "Templates/SharedPointer.h"
#include "UObject/UObjectGlobals.h"

#include "GameResponsivePanelSlot.generated.h"

class UObject;

UCLASS()
class LYRAUINAVIGATION_API UGameResponsivePanelSlot : public UPanelSlot
{
	GENERATED_UCLASS_BODY()

public:
	

public:

	void BuildSlot(TSharedRef<SGameResponsivePanel> GameResponsivePanel);

	// UPanelSlot interface
	virtual void SynchronizeProperties() override;
	// End of UPanelSlot interface

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

private:
	SGameResponsivePanel::FSlot* Slot;
};
