// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "CoreTypes.h"
#include "GameSettingValue.h"
#include "Internationalization/Text.h"
#include "Misc/AssertionMacros.h"
#include "UObject/UObjectGlobals.h"

#include "GameSettingValueDiscrete.generated.h"

class UObject;
struct FFrame;

UCLASS(Abstract)
class LYRAUINAVIGATION_API UGameSettingValueDiscrete : public UGameSettingValue
{
	GENERATED_BODY()

public:
	UGameSettingValueDiscrete();

	/** UGameSettingValueDiscrete */
	virtual void SetDiscreteOptionByIndex(int32 Index) PURE_VIRTUAL(,);
	
	UFUNCTION(BlueprintCallable, Category = "Game Setting Value")
	virtual int32 GetDiscreteOptionIndex() const PURE_VIRTUAL(,return INDEX_NONE;);

	/** Optional */
	UFUNCTION(BlueprintCallable, Category = "Game Setting Value")
	virtual int32 GetDiscreteOptionDefaultIndex() const { return INDEX_NONE; }

	UFUNCTION(BlueprintCallable, Category = "Game Setting Value")
	virtual TArray<FText> GetDiscreteOptions() const PURE_VIRTUAL(,return TArray<FText>(););

	virtual FString GetAnalyticsValue() const;
};
