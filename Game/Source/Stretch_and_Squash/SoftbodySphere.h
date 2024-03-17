// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components//StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoftbodySphere.generated.h"

class UNiagaraSystem;

UCLASS()
class STRETCH_AND_SQUASH_API ASoftbodySphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoftbodySphere();

	UFUNCTION(BlueprintCallable)
	TArray<FVector> MeshData(const UStaticMeshComponent* StaticMeshComponent);

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ActorMesh;

	UPROPERTY(EditAnywhere)
	TArray<FVector> vertices;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* SoftbodyEffect;

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* NiagaraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
