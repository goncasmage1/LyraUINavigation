// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataTable.h"
#include "Input/UIActionBindingHandle.h"
#include "UObject/UObjectGlobals.h"
#include "GameSettings/Widgets/GameSettingScreen.h"

#include "LyraSettingScreen.generated.h"

class UGameSettingRegistry;
class ULyraTabListWidgetBase;
class UObject;

UCLASS(Abstract, meta = (Category = "Settings", DisableNativeTick))
class LYRAUINAVIGATION_API ULyraSettingScreen : public UGameSettingScreen
{
	GENERATED_BODY()

public:

protected:
	virtual void NativeOnInitialized() override;
	virtual UGameSettingRegistry* CreateRegistry() override;

	void HandleBackAction();
	void HandleApplyAction();
	void HandleCancelChangesAction();

	virtual void OnSettingsDirtyStateChanged_Implementation(bool bSettingsDirty) override;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = Input, meta = (BindWidget, OptionalWidget = true, AllowPrivateAccess = true))
	TObjectPtr<ULyraTabListWidgetBase> TopSettingsTabs;
	
	UPROPERTY(EditDefaultsOnly, Category = "Lyra Setting Screen")
	FDataTableRowHandle BackInputActionData;

	UPROPERTY(EditDefaultsOnly, Category = "Lyra Setting Screen")
	FDataTableRowHandle ApplyInputActionData;

	UPROPERTY(EditDefaultsOnly, Category = "Lyra Setting Screen")
	FDataTableRowHandle CancelChangesInputActionData;

	FUIActionBindingHandle BackHandle;
	FUIActionBindingHandle ApplyHandle;
	FUIActionBindingHandle CancelChangesHandle;
};
