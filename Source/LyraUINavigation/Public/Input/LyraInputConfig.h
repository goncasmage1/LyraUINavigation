// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/Array.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/UObjectGlobals.h"

#include "LyraInputConfig.generated.h"

class UInputAction;
class UObject;
struct FFrame;

/**
 * FLyraInputAction
 *
 *	Struct used to map a input action to a gameplay input tag.
 */
USTRUCT(BlueprintType)
struct FLyraInputAction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra Input Action")
	TObjectPtr<const UInputAction> InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra Input Action", Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

/**
 * ULyraInputConfig
 *
 *	Non-mutable data asset that contains input configuration properties.
 */
UCLASS(BlueprintType, Const)
class LYRAUINAVIGATION_API ULyraInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	ULyraInputConfig(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Lyra|Pawn")
	const UInputAction* FindNativeInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Pawn")
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;

public:
	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra Input Config", Meta = (TitleProperty = "InputAction"))
	TArray<FLyraInputAction> NativeInputActions;

	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and are automatically bound to abilities with matching input tags.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra Input Config", Meta = (TitleProperty = "InputAction"))
	TArray<FLyraInputAction> AbilityInputActions;
};
