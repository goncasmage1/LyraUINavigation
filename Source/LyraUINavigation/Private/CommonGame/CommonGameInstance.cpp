// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonGame/CommonGameInstance.h"
#include "CommonGame/CommonLocalPlayer.h"
#include "CommonGame/GameUIManagerSubsystem.h"
#include "CommonGame/CommonGameInstance.h"
#include "UI/LyraNavigationConfig.h"

UCommonGameInstance::UCommonGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UCommonGameInstance::Init()
{
	Super::Init();

	FSlateApplication::Get().SetNavigationConfig(MakeShared<FLyraNavigationConfig>());
}

void UCommonGameInstance::Shutdown()
{
#if WITH_EDITOR
	FSlateApplication::Get().SetNavigationConfig(MakeShared<FNavigationConfig>());
#endif

	Super::Shutdown();
}

int32 UCommonGameInstance::AddLocalPlayer(ULocalPlayer* NewPlayer, FPlatformUserId UserId)
{
	int32 ReturnVal = Super::AddLocalPlayer(NewPlayer, UserId);
	if (ReturnVal != INDEX_NONE)
	{
		if (!PrimaryPlayer.IsValid())
		{
			PrimaryPlayer = NewPlayer;
		}

		GetSubsystem<UGameUIManagerSubsystem>()->NotifyPlayerAdded(Cast<UCommonLocalPlayer>(NewPlayer));
	}

	return ReturnVal;
}

bool UCommonGameInstance::RemoveLocalPlayer(ULocalPlayer* ExistingPlayer)
{
	if (PrimaryPlayer == ExistingPlayer)
	{
		//TODO: do we want to fall back to another player?
		PrimaryPlayer.Reset();
	}
	GetSubsystem<UGameUIManagerSubsystem>()->NotifyPlayerDestroyed(Cast<UCommonLocalPlayer>(ExistingPlayer));

	return Super::RemoveLocalPlayer(ExistingPlayer);
}