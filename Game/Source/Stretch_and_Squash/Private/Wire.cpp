// Fill out your copyright notice in the Description page of Project Settings.


#include "Wire.h"

// Sets default values
AWire::AWire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWire::BeginPlay()
{
	Super::BeginPlay();


	switch (ActionType)
	{

		case EActionType::LIFTOFF:
			OriginalActorLocation = ActorToEffect->GetActorLocation();
			CurrentActorLocation = ActorToEffect->GetActorLocation();
			CurrentActorOffset = ActorToEffect->GetActorLocation();
		break;
	}
	
}

// Called every frame
void AWire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	switch (ActionType)
	{
	case EActionType::NONE:

		break;

	case EActionType::CONSTANT_ROTATION:
		if (bShouldActivateRotation)
		{
			ActivateRotation(DeltaTime);
		}
		break;

	case EActionType::LIFTOFF:
		if (bShouldLiftOff)
		{
			ActivateLiftOff(DeltaTime);
		}
		else
		{
			RevertLiftOff(DeltaTime);
		}
		
		break;
	}

}


void AWire::ActivateAction(EActionType CurrentActionType)
{

	switch (ActionType)
	{
		case EActionType::NONE:
			bShouldActivateRotation = false;
			
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("Default"));
			break;

		case EActionType::CONSTANT_ROTATION:
			bShouldActivateRotation = true;
			break;

		case EActionType::LIFTOFF:
			bShouldLiftOff = true;
			break;
	}

}

void AWire::DeactivateAction()
{
	switch (ActionType)

	{
	case EActionType::NONE:
		break;

	case EActionType::CONSTANT_ROTATION:
		bShouldActivateRotation = false;
		break;

	case EActionType::LIFTOFF:
		bShouldLiftOff = false;
		break;
	}
}

void AWire::ActivateRotation(float _DeltaTime)
{
	
	if (IsValid(ActorToEffect))
	{

		float Roll = RotationRate * _DeltaTime;

		FRotator NewRotation = FRotator(Roll, 0, 0);

		ActorToEffect->AddActorWorldRotation(NewRotation);
	}
}

void AWire::ActivateLiftOff(float _DeltaTime)
{

	if (IsValid(ActorToEffect))
	{
		float LiftOffset = OriginalActorLocation.Z + LiftHeight;
		TimeElapsedRevert = 0;
		
		if (TimeElapsedLift < LiftDuration)
		{
			//float LocationChange = FMath::Lerp(OriginalActorLocation.Z, LiftOffset, TimeElapsed / LerpDuration);

			float LocationChange = FMath::InterpEaseInOut((float)CurrentActorOffset.Z, LiftOffset, TimeElapsedLift / LiftDuration, LiftBounciness);

			float X = ActorToEffect->GetActorLocation().X;
			float Y = ActorToEffect->GetActorLocation().Y;

			ActorToEffect->SetActorLocation(FVector(X, Y, LocationChange));

			CurrentActorLocation = ActorToEffect->GetActorLocation();

			TimeElapsedLift += _DeltaTime * LiftSpeed;
		}
		
	}
}

void AWire::RevertLiftOff(float _DeltaTime)
{
	TimeElapsedLift = 0;

	if (IsValid(ActorToEffect))
	{
		if (TimeElapsedRevert < LiftDuration)
		{

			float LocationChange = FMath::InterpEaseInOut((float)CurrentActorLocation.Z, (float)OriginalActorLocation.Z, TimeElapsedRevert / LiftDuration, LiftBounciness);

			float X = ActorToEffect->GetActorLocation().X;
			float Y = ActorToEffect->GetActorLocation().Y;

			ActorToEffect->SetActorLocation(FVector(X, Y, LocationChange));

			TimeElapsedRevert += _DeltaTime * LiftSpeed;

			CurrentActorOffset = ActorToEffect->GetActorLocation();
		}

	}
	

	
}

