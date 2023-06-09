// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonActivatableWidget.h"
#include "CommonInputBaseTypes.h"
#include "Delegates/Delegate.h"
#include "Input/Reply.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/WeakObjectPtrTemplates.h"
#include "GameSettings/Widgets/IGameSettingActionInterface.h"

#include "LyraBrightnessEditor.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UGameSetting;
class UGameSettingValueScalar;
class UObject;
class UWidgetSwitcher;
struct FAnalogInputEvent;
struct FFrame;
struct FGameplayTag;
struct FGeometry;
struct FPointerEvent;

UCLASS(Abstract)
class LYRAUINAVIGATION_API ULyraBrightnessEditor : public UCommonActivatableWidget, public IGameSettingActionInterface
{
	GENERATED_BODY()

public:
	FSimpleMulticastDelegate OnSafeZoneSet;
	
public:
	ULyraBrightnessEditor(const FObjectInitializer& Initializer);

	// Begin IGameSettingActionInterface
	virtual bool ExecuteActionForSetting_Implementation(FGameplayTag ActionTag, UGameSetting* InSetting) override;
	// End IGameSettingActionInterface

protected:

	UPROPERTY(EditAnywhere, Category = "Restrictions")
	bool bCanCancel = true;

	virtual void NativeOnActivated() override;
	virtual void NativeOnInitialized() override;
	virtual FReply NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent) override;
	virtual FReply NativeOnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	void HandleInputModeChanged(ECommonInputType InInputType);

private:
	UFUNCTION()
	void HandleBackClicked();

	UFUNCTION()
	void HandleDoneClicked();

	TWeakObjectPtr<UGameSettingValueScalar> ValueSetting;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Brightness Editor", meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UWidgetSwitcher> Switcher_SafeZoneMessage;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Brightness Editor", meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UCommonRichTextBlock> RichText_Default;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Brightness Editor", meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Brightness Editor", meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UCommonButtonBase> Button_Done;
};
