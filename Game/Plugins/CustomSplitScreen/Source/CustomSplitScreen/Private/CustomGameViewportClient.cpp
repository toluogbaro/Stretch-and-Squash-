#include "CustomGameViewportClient.h"

// initial implementation found here:
// https://spyro-soft.com/developers/customising-unreal-engine-split-screen-with-a-simple-plugin

UCustomGameViewportClient::UCustomGameViewportClient()
	 : Super(FObjectInitializer::Get())
{
	// resize SplitscreenInfo to fit custom config
	SplitscreenInfo.SetNum(ECustomSplitScreenType::SplitTypeCount, false);

	// player 1 viewport constraints
	SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(
		0.5f,
		1.00f,
		0.0f,
		0.00f));
    // player 2 viewport constraints
	SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(
		0.5f,
		1.00f,
		0.5f,
		0.00f));
}

void UCustomGameViewportClient::UpdateActiveSplitscreenType()
{
	ECustomSplitScreenType::Type SplitType = ECustomSplitScreenType::None;
	const int32 playerCount = GEngine->GetNumGamePlayers(GetWorld());

	if (playerCount == 2)
	{
		ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
	}
	else
	{
		Super::UpdateActiveSplitscreenType();
	}
}

void UCustomGameViewportClient::LayoutPlayers()
{
	Super::LayoutPlayers();
}



