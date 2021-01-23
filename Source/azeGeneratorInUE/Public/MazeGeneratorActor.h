// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeGeneratorActor.generated.h"

class AMazeBlock;
class USceneComponent;

UCLASS()
class AZEGENERATORINUE_API AMazeGeneratorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeGeneratorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<TArray<int>>		Maze;

	void					CreateDefaultMaze(uint32 width, uint32 height);
	void					PrintMaze() const;
	void					GenerateMaze(int32 startRow, int32 startCol);
	void					MoveUp(int32 startRow, int32 startCol);
	void					MoveDown(int32 startRow, int32 startCol);
	void					MoveLeft(int32 startRow, int32 startCol);
	void					MoveRight(int32 startRow, int32 startCol);
	void					ShuffleArray(TArray<int32>& myArray);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Maze block", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AMazeBlock>	MazeBlock;

	UPROPERTY(EditAnywhere)
	USceneComponent*	SceneComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
