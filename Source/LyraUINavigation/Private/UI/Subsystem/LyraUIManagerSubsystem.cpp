// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/Subsystem/LyraUIManagerSubsystem.h"

#include "CommonGame/CommonLocalPlayer.h"
#include "Components/SlateWrapperTypes.h"
#include "Containers/Array.h"
#include "Delegates/Delegate.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"
#include "CommonGame/GameUIPolicy.h"
#include "CommonGame/PrimaryGameLayout.h"
#include "Templates/Casts.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraUIManagerSubsystem)

class FSubsystemCollectionBase;

ULyraUIManagerSubsystem::ULyraUIManagerSubsystem()
{
}

void ULyraUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TickHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &ULyraUIManagerSubsystem::Tick), 0.0f);
}

void ULyraUIManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();

	FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);
}

bool ULyraUIManagerSubsystem::Tick(float DeltaTime)
{
	SyncRootLayoutVisibilityToShowHUD();
	
	return true;
}

void ULyraUIManagerSubsystem::SyncRootLayoutVisibilityToShowHUD()
{
	if (const UGameUIPolicy* Policy = GetCurrentUIPolicy())
	{
		for (const ULocalPlayer* LocalPlayer : GetGameInstance()->GetLocalPlayers())
		{
			bool bShouldShowUI = true;
			
			if (const APlayerController* PC = LocalPlayer->GetPlayerController(GetWorld()))
			{
				const AHUD* HUD = PC->GetHUD();

				if (HUD && !HUD->bShowHUD)
				{
					bShouldShowUI = false;
				}
			}

			if (UPrimaryGameLayout* RootLayout = Policy->GetRootLayout(CastChecked<UCommonLocalPlayer>(LocalPlayer)))
			{
				const ESlateVisibility DesiredVisibility = bShouldShowUI ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
				if (DesiredVisibility != RootLayout->GetVisibility())
				{
					RootLayout->SetVisibility(DesiredVisibility);	
				}
			}
		}
	}
}