// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonInputBaseTypes.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPtr.h"

#include "LyraMappableConfigPair.generated.h"

class UPlayerMappableInputConfig;

/** A container to organize loaded player mappable configs to their CommonUI input type */
USTRUCT(BlueprintType)
struct LYRAUINAVIGATION_API FLoadedMappableConfigPair
{
	GENERATED_BODY()

	FLoadedMappableConfigPair() = default;
	FLoadedMappableConfigPair(const UPlayerMappableInputConfig* InConfig, ECommonInputType InType, const bool InIsActive)
		: Config(InConfig)
		, Type(InType)
		, bIsActive(InIsActive)
	{}

	/** The player mappable input config that should be applied to the Enhanced Input subsystem */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Lyra Mappable Config Pair")
	TObjectPtr<const UPlayerMappableInputConfig> Config = nullptr;

	/** The type of device that this mapping config should be applied to */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Lyra Mappable Config Pair")
	ECommonInputType Type = ECommonInputType::Count;

	/** If this config is currently active. A config is marked as active when it's owning GFA is active */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Lyra Mappable Config Pair")
	bool bIsActive = false;
};

/** A container to organize potentially unloaded player mappable configs to their CommonUI input type */
USTRUCT()
struct LYRAUINAVIGATION_API FMappableConfigPair
{
	GENERATED_BODY()
	
	FMappableConfigPair() = default;
	
	UPROPERTY(EditAnywhere, Category = "Lyra Mappable Config Pair")
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	/**
	 * The type of config that this is. Useful for filtering out configs by the current input device
	 * for things like the settings screen, or if you only want to apply this config when a certain
	 * input type is being used.
	 */
	UPROPERTY(EditAnywhere, Category = "Lyra Mappable Config Pair")
	ECommonInputType Type = ECommonInputType::Count;

	/**
	 * Container of platform traits that must be set in order for this input to be activated.
	 * 
	 * If the platform does not have one of the traits specified it can still be registered, but cannot
	 * be activated. 
	 */
	UPROPERTY(EditAnywhere, Category = "Lyra Mappable Config Pair")
	FGameplayTagContainer DependentPlatformTraits;

	/**
	 * If the current platform has any of these traits, then this config will not be actived.
	 */
	UPROPERTY(EditAnywhere, Category = "Lyra Mappable Config Pair")
	FGameplayTagContainer ExcludedPlatformTraits;

	/** If true, then this input config will be activated when it's associated Game Feature is activated.
	 * This is normally the desirable behavior
	 */
	UPROPERTY(EditAnywhere, Category = "Lyra Mappable Config Pair")
	bool bShouldActivateAutomatically = true;

};