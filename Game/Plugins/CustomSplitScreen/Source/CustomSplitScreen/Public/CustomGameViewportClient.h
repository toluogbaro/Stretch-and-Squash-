// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "Engine/ViewportSplitScreen.h"

#include "CustomGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMSPLITSCREEN_API UCustomGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

	UCustomGameViewportClient();

	virtual void UpdateActiveSplitscreenType() override;

	virtual void LayoutPlayers() override;
};

UENUM(BlueprintType)
namespace ECustomSplitScreenType
{
	enum Type
	{
		// Required by UE
		None,
		// Custom splitscreen type added after last item in existing enum
		TwoPlayer = ESplitScreenType::SplitTypeCount,
		SplitTypeCount
	};
}

