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

	if (IsValid(ActorToEffect))
	{
		switch (ActionType)
		{

		case EActionType::LIFTOFF:
			OriginalActorLocation = ActorToEffect->GetActorLocation();
			CurrentActorLocation = ActorToEffect->GetActorLocation();
			CurrentActorOffset = ActorToEffect->GetActorLocation();

			if (IsValid(SecondActorToEffect))
			{
				SOriginalActorLocation = SecondActorToEffect->GetActorLocation();
				SCurrentActorLocation = SecondActorToEffect->GetActorLocation();
				SCurrentActorOffset = SecondActorToEffect->GetActorLocation();
			}
			
			break;
		}
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
		else
		{
			DeactivateRotation(DeltaTime);
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


void AWire::ActivateAction(EActionType CurrentActionType, float BuildFanSpeed)
{
	if (IsValid(ActorToEffect))
	{
		switch (ActionType)
		{
		case EActionType::NONE:
			bShouldActivateRotation = false;

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("Default"));
			break;

		case EActionType::CONSTANT_ROTATION:
			bShouldActivateRotation = true;
			BuildFanSpeed = MappedRotationSpeed;
			break;

		case EActionType::LIFTOFF:
			bShouldLiftOff = true;
			break;
		}

		
	}
	

}

void AWire::DeactivateAction(float SlowFanSpeed)
{
	if (IsValid(ActorToEffect))
	{
		switch (ActionType)

		{
		case EActionType::NONE:
			break;

		case EActionType::CONSTANT_ROTATION:
			bShouldActivateRotation = false;
			SlowFanSpeed = MappedRotationSpeed;
			break;

		case EActionType::LIFTOFF:
			bShouldLiftOff = false;
			break;
		}
	}
	
}

void AWire::ActivateRotation(float _DeltaTime)
{
	if (BuildUpSpeed < RotationRate)
	{
		BuildUpSpeed += _DeltaTime * BuildUpSpeedMultiplier;
		RotationSpeed = BuildUpSpeed * _DeltaTime;
		MappedRotationSpeed = BuildUpSpeed / RotationRate;		

	}
	else
	{
		RotationSpeed = RotationRate * _DeltaTime;
	}

	switch (_RotationAxis)
	{
	case RotationAxis::X:
		NewRotation = FRotator(RotationSpeed, 0, 0);
		break;

	case RotationAxis::Y:
		NewRotation = FRotator(0, RotationSpeed, 0);
		break;

	case RotationAxis::Z:
		NewRotation = FRotator(0, 0, RotationSpeed);
		break;

	}

	ActorToEffect->AddActorWorldRotation(NewRotation);
	
}

void AWire::DeactivateRotation(float _DeltaTime)
{
	if (BuildUpSpeed > 0.0f)
	{
		BuildUpSpeed -= _DeltaTime * SlowDownSpeedMultiplier;
		RotationSpeed = BuildUpSpeed * _DeltaTime;
		MappedRotationSpeed = BuildUpSpeed / RotationRate;

	}

	switch (_RotationAxis)
	{
	case RotationAxis::X:
		NewRotation = FRotator(RotationSpeed, 0, 0);
		break;

	case RotationAxis::Y:
		NewRotation = FRotator(0, RotationSpeed, 0);
		break;

	case RotationAxis::Z:
		NewRotation = FRotator(0, 0, RotationSpeed);
		break;

	}

	ActorToEffect->AddActorWorldRotation(NewRotation);


}

void AWire::ActivateLiftOff(float _DeltaTime)
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

		if (IsValid(SecondActorToEffect))
		{

			float SLiftOffset = SOriginalActorLocation.Z + LiftHeight;
			TimeElapsedRevert = 0;

			if (TimeElapsedLift < LiftDuration)
			{
				//float LocationChange = FMath::Lerp(OriginalActorLocation.Z, LiftOffset, TimeElapsed / LerpDuration);

				float SLocationChange = FMath::InterpEaseInOut((float)SCurrentActorOffset.Z, SLiftOffset, TimeElapsedLift / LiftDuration, LiftBounciness);

				float SX = SecondActorToEffect->GetActorLocation().X;
				float SY = SecondActorToEffect->GetActorLocation().Y;

				SecondActorToEffect->SetActorLocation(FVector(SX, SY, SLocationChange));

				SCurrentActorLocation = SecondActorToEffect->GetActorLocation();

			}
		}

		
	
}

void AWire::RevertLiftOff(float _DeltaTime)
{
		TimeElapsedLift = 0;

	
		if (TimeElapsedRevert < LiftDuration)
		{

			float LocationChange = FMath::InterpEaseInOut((float)CurrentActorLocation.Z, (float)OriginalActorLocation.Z, TimeElapsedRevert / LiftDuration, LiftBounciness);

			float X = ActorToEffect->GetActorLocation().X;
			float Y = ActorToEffect->GetActorLocation().Y;

			ActorToEffect->SetActorLocation(FVector(X, Y, LocationChange));

			TimeElapsedRevert += _DeltaTime * LiftSpeed;

			CurrentActorOffset = ActorToEffect->GetActorLocation();
		}

		if (IsValid(SecondActorToEffect))
		{

			float SLiftOffset = SOriginalActorLocation.Z + LiftHeight;
			TimeElapsedRevert = 0;

			if (TimeElapsedRevert < LiftDuration)
			{
				//float LocationChange = FMath::Lerp(OriginalActorLocation.Z, LiftOffset, TimeElapsed / LerpDuration);

				float SLocationChange = FMath::InterpEaseInOut((float)SCurrentActorOffset.Z,(float) SOriginalActorLocation.Z, TimeElapsedRevert / LiftDuration, LiftBounciness);

				float SX = SecondActorToEffect->GetActorLocation().X;
				float SY = SecondActorToEffect->GetActorLocation().Y;

				SecondActorToEffect->SetActorLocation(FVector(SX, SY, SLocationChange));

				SCurrentActorOffset = SecondActorToEffect->GetActorLocation();
			}
		}

	
	

	
}

