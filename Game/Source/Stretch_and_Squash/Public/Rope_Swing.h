// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SphereComponent.generated.h"
#include "Rope_Swing.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRopeSwingHasStartedTDelegate, bool, bCanStartDetermineDistance);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STRETCH_AND_SQUASH_API URope_Swing : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URope_Swing();

	UPROPERTY(EditAnywhere)
	AActor* AnchorPoint;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SphereCollision;

	UPROPERTY(EditAnywhere)
	AActor* Stretch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanDetermineDistance;

	UPROPERTY(VisibleAnywhere)
	float Distance;

	UPROPERTY(EditAnywhere)
	float Spring = 0.1f;

	UPROPERTY(EditAnywhere)
	float Damper = 5.0f;

	UPROPERTY(BlueprintCallable)
	FRopeSwingHasStartedTDelegate OnRopeSwingStarted;

	UFUNCTION(BlueprintCallable)
	void BroadcastRopeDelegate();

	UFUNCTION(BlueprintCallable)
	void BroadCastEndRopeDelegate();

	UFUNCTION(BlueprintCallable)
	void DetermineRopeSwing(float _DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetActors(AActor* Anchor, AActor* _Stretch);

	UPROPERTY(BlueprintReadOnly)
	FVector SpringOutput;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
