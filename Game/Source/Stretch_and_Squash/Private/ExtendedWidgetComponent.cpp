// Fill out your copyright notice in the Description page of Project Settings.


#include "ExtendedWidgetComponent.h"

//Set WidgetComponent Owner by ControllerId
void UExtendedWidgetComponent::setOwner(const int32 ControllerId)
{
	if (!GetWorld()) return;
	ULocalPlayer* InPlayer = GEngine->GetLocalPlayerFromControllerId(GetWorld(), ControllerId);
	UWidgetComponent::SetOwnerPlayer(InPlayer);
};