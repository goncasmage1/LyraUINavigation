// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "LyraUIInputActions.generated.h"

/**
 * 
 */
UCLASS()
class LYRAUINAVIGATION_API ULyraUIInputActions : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuDown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuSelect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuReturn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuNext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = EnhancedInput)
	UInputAction* IA_MenuPrevious;
	
};
