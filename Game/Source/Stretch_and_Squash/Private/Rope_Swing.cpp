// Fill out your copyright notice in the Description page of Project Settings.


#include "Rope_Swing.h"

// Sets default values for this component's properties
URope_Swing::URope_Swing()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void URope_Swing::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void URope_Swing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void URope_Swing::BroadcastRopeDelegate()
{
	OnRopeSwingStarted.Broadcast(true);

	Stretch = GetOwner();

	//AnchorPoint = Get

	if (IsValid(AnchorPoint) && IsValid(Stretch))
	{
		FVector DistBetweenStretchAndAnchor = AnchorPoint->GetActorLocation() - Stretch->GetActorLocation();

		Distance = DistBetweenStretchAndAnchor.SquaredLength();
	}
}

void URope_Swing::BroadCastEndRopeDelegate()
{
	OnRopeSwingStarted.Broadcast(false);
}

void URope_Swing::DetermineRopeSwing(float _DeltaTime)
{

	if (IsValid(AnchorPoint) && IsValid(Stretch))
	{
		FVector Connection = AnchorPoint->GetActorLocation() - Stretch->GetActorLocation();

		float DifferenceLength = Distance - Connection.SquaredLength();

		FVector NewAnchorPosition = AnchorPoint->GetActorLocation() + (DifferenceLength * Connection.Normalize());

		AnchorPoint->SetActorLocation(NewAnchorPosition);

		FVector VelocityTarget = Connection + (AnchorPoint->GetVelocity() + GetWorld()->GetGravityZ() * Spring);

		FVector ProjectedVector = FVector::VectorPlaneProject(VelocityTarget, Connection);

		FVector OutputVelocity = (VelocityTarget - ProjectedVector) / (1 + Damper * _DeltaTime);

	}
	


}

