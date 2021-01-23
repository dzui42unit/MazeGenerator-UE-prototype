// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeBlock.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMazeBlock::AMazeBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh comp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AMazeBlock::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMazeBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

