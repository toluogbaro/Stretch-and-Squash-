// Fill out your copyright notice in the Description page of Project Settings.


#include "CableModification.h"

// Sets default values for this component's properties
UCableModification::UCableModification()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	
}


// Called when the game starts
void UCableModification::BeginPlay()
{
	Super::BeginPlay();

	AActor* AttachedActor = GetOwner();
	if (IsValid(AttachedActor))
	{
		Cable = AttachedActor->FindComponentByClass<UCableComponent>();
	}

	if(IsValid(Cable)) Cable->CableWidth = 115;
	
}


// Called every frame
void UCableModification::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

