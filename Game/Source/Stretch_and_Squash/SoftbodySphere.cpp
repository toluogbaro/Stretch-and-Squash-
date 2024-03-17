// Fill out your copyright notice in the Description page of Project Settings.


#include "SoftbodySphere.h"

// Sets default values
ASoftbodySphere::ASoftbodySphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

TArray<FVector> ASoftbodySphere::MeshData(const UStaticMeshComponent* StaticMeshComponent)
{
	vertices = TArray<FVector>();

	if (!IsValidLowLevel()) return vertices;
	if (!StaticMeshComponent) return vertices;
	if (!StaticMeshComponent->GetStaticMesh()->HasValidRenderData()) return vertices;

	if (StaticMeshComponent->GetStaticMesh()->GetRenderData()->LODResources.Num() > 0)
	{
		FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->GetStaticMesh()->GetRenderData()->LODResources[0].VertexBuffers.PositionVertexBuffer;

		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();

			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				const FVector CurrentVertexPosition = (FVector)VertexBuffer->VertexPosition(Index);
				const FVector WorldSpaceVertexLocation = GetActorLocation() + GetTransform().TransformVector(CurrentVertexPosition);
				vertices.Add(WorldSpaceVertexLocation);
			}
		}
	}

	return vertices;
}

// Called when the game starts or when spawned
void ASoftbodySphere::BeginPlay()
{
	Super::BeginPlay();

	TArray<UStaticMeshComponent*> SMComponents;
	this->GetComponents<UStaticMeshComponent>(SMComponents);

	for (int32 i = 0; i < SMComponents.Num(); i++)
	{
		if (SMComponents[i]) ActorMesh = SMComponents[i];
	}

	if (GEngine && ActorMesh) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, TEXT("Active"));

	if (ActorMesh) MeshData(ActorMesh);

	

	if (SoftbodyEffect && ActorMesh)
	{
		NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAttached(SoftbodyEffect, ActorMesh, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true);

	}
	
}

// Called every frame
void ASoftbodySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

