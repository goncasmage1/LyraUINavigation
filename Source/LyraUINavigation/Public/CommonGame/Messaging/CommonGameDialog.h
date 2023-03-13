// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonActivatableWidget.h"
#include "CommonMessagingSubsystem.h"
#include "Containers/Array.h"
#include "Internationalization/Text.h"
#include "UObject/Object.h"
#include "UObject/UObjectGlobals.h"

#include "CommonGameDialog.generated.h"

USTRUCT(BlueprintType)
struct FConfirmationDialogAction
{
	GENERATED_BODY()

public:
	/** Required: The dialog option to provide. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Confirmation Dialog")
	ECommonMessagingResult Result = ECommonMessagingResult::Unknown;

	/** Optional: Display Text to use instead of the action name associated with the result. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Confirmation Dialog")
	FText OptionalDisplayText;

	bool operator==(const FConfirmationDialogAction& Other) const
	{
		return Result == Other.Result &&
			OptionalDisplayText.EqualTo(Other.OptionalDisplayText);
	}
};

UCLASS()
class LYRAUINAVIGATION_API UCommonGameDialogDescriptor : public UObject
{
	GENERATED_BODY()
	
public:
	static UCommonGameDialogDescriptor* CreateConfirmationOk(const FText& Header, const FText& Body);
	static UCommonGameDialogDescriptor* CreateConfirmationOkCancel(const FText& Header, const FText& Body);
	static UCommonGameDialogDescriptor* CreateConfirmationYesNo(const FText& Header, const FText& Body);
	static UCommonGameDialogDescriptor* CreateConfirmationYesNoCancel(const FText& Header, const FText& Body);

public:
	/** The header of the message to display */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Confirmation Dialog")
	FText Header;
	
	/** The body of the message to display */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Confirmation Dialog")
	FText Body;

	/** The confirm button's input action to use. */
	UPROPERTY(BlueprintReadWrite, Category = "Confirmation Dialog")
	TArray<FConfirmationDialogAction> ButtonActions;
};


UCLASS(Abstract)
class LYRAUINAVIGATION_API UCommonGameDialog : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
public:
	UCommonGameDialog();
	
	virtual void SetupDialog(UCommonGameDialogDescriptor* Descriptor, FCommonMessagingResultDelegate ResultCallback);

	virtual void KillDialog();
};