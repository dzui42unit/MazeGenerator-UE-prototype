// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeBlock.generated.h"

class UStaticMeshComponent;


UCLASS()
class AZEGENERATORINUE_API AMazeBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent*	MeshComp;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
