// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wire.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	NONE,
	CONSTANT_ROTATION,
	LIFTOFF,
};

UENUM(BlueprintType)
enum class RotationAxis : uint8
{
	X,
	Y,
	Z
};

UCLASS()
class STRETCH_AND_SQUASH_API AWire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma region Base Variables

	UPROPERTY(EditAnywhere, Category = "Wire")
	EActionType ActionType = EActionType::NONE;

	UFUNCTION(BlueprintCallable, Category = "Wire")
	void ActivateAction(EActionType CurrentActionType);

	UFUNCTION(BlueprintCallable, Category = "Wire")
	void DeactivateAction();

	UPROPERTY(EditAnywhere)
	AActor* ActorToEffect;

#pragma endregion

#pragma region Rotation


	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::CONSTANT_ROTATION", EditConditionHides))
	RotationAxis _RotationAxis = RotationAxis::X;

	//How Fast You Want The Actor To Rotate
	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::CONSTANT_ROTATION", EditConditionHides))
	float RotationRate;

	UPROPERTY()
	FRotator NewRotation;

	UPROPERTY()
	bool bShouldActivateRotation;

	UFUNCTION()
	void ActivateRotation(float _DeltaTime);

#pragma endregion

#pragma region Lifting

	//How High You Want The Actor To Lift
	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::LIFTOFF", EditConditionHides))
	float LiftHeight = 300.0f;

	//How Fast You Want The Actor To Lift To Height
	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::LIFTOFF", EditConditionHides))
	float LiftSpeed = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::LIFTOFF", EditConditionHides))
	float LiftDuration = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Wire", meta = (EditCondition = "ActionType == EActionType::LIFTOFF", EditConditionHides))
	float LiftBounciness = 10.0f;

	//Save Actor Location In Beginning
	FVector OriginalActorLocation;

	//Get Current Location Only During Lift Off
	FVector CurrentActorLocation;
	
	FVector CurrentActorOffset;

	float TimeElapsedLift = 0;

	float TimeElapsedRevert = 0;

	bool bShouldLiftOff;

	UFUNCTION()
	void ActivateLiftOff(float _DeltaTime);

	UFUNCTION()
	void RevertLiftOff(float _DeltaTime);

#pragma endregion





	

};


