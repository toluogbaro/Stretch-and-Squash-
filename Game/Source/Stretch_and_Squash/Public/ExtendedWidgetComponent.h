// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ExtendedWidgetComponent.generated.h"

/**
 * Class extended to provide an extra method to more easily transfer ownership of widget
 */
UCLASS()
class STRETCH_AND_SQUASH_API UExtendedWidgetComponent : public UWidgetComponent
  {
  	GENERATED_BODY()
  
	UFUNCTION(BlueprintCallable, Category = UserInterface)
	void setOwner(const int32 ControllerId);
  	
  };
