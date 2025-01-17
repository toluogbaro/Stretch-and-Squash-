// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <CableComponent.h>
#include "CableModification.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRETCH_AND_SQUASH_API UCableModification : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCableModification();

	UPROPERTY(EditAnywhere)
	UCableComponent* Cable;

	UFUNCTION(BlueprintCallable)
	void StretchCable(float CableSizeMdodifier);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
