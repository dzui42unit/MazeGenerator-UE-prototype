// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGeneratorActor.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MazeBlock.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AMazeGeneratorActor::AMazeGeneratorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultMaze(25, 25);
	GenerateMaze(1, 1);
}

// Called when the game starts or when spawned
void AMazeGeneratorActor::BeginPlay()
{
	Super::BeginPlay();


	if (!MazeBlock)
		return;

	float xOffset = 0.f;
	float yOffset = 0.f;
	float xStep = 100.f;
	float yStep = 100.f;

	UE_LOG(LogTemp, Warning, TEXT("2213132222"));

	for (int32 i = 0; i < Maze.Num(); i++) {
		xOffset = 0.f;
		for (int32 j = 0; j < Maze[i].Num(); j++) {
			FVector		ActorLoc(xOffset, yOffset, 0.f);
			if (Maze[i][j] == 1) {
				AActor* CreatedBlock  = GetWorld()->SpawnActor<AMazeBlock>(MazeBlock, ActorLoc, FRotator(0.f));
			}
			xOffset += xStep;
		}
		yOffset += yStep;
	}

	
}

void AMazeGeneratorActor::CreateDefaultMaze(uint32 width, uint32 height)
{
	for (uint32 i = 0; i < width; i++) {
		TArray<int> row = {};
		for (uint32 j = 0; j < height; j++) {
			row.Add(1);
		}
		Maze.Add(row);
	}
}

void AMazeGeneratorActor::PrintMaze() const
{
	FString MazeRow = "";
	for (int32 i = 0; i < Maze.Num();  i++) {
		MazeRow = "";
		for (int32 j = 0; j < Maze[i].Num();  j++) {
			MazeRow += (" " + FString::FromInt(Maze[i][j]));
		}
		UE_LOG(LogTemp, Warning, TEXT("%s"), *MazeRow);
	}
}

void AMazeGeneratorActor::GenerateMaze(int32 startRow, int32 startCol)
{
	Maze[startRow][startCol] = 0;

	// initialize directions up, right, down, left
	TArray<int> directions = { 0, 1, 2, 3 };

	ShuffleArray(directions);

	for (int32 i = 0; i < directions.Num(); i++) {
		// up
		if (directions[i] == 0) {
			MoveUp(startRow, startCol);
		}
		// right
		if (directions[i] == 1) {
			MoveRight(startRow, startCol);
		}
		// down
		if (directions[i] == 2) {
			MoveDown(startRow, startCol);
		}
		// left
		if (directions[i] == 3) {
			MoveLeft(startRow, startCol);
		}
	}
}

void AMazeGeneratorActor::MoveUp(int32 startRow, int32 startCol)
{
	// check if we do not go out of bounds;
	if (startRow - 2 < 1) {
		return;
	}
	// check if the next two cells are free
	if (Maze[startRow - 1][startCol] == 0 || Maze[startRow - 2][startCol] == 0) {
		return;
	}
	// if we do not go out of bound and the cells are free, we move to that direction
	Maze[startRow - 1][startCol] = 0;
	Maze[startRow - 2][startCol] = 0;
	GenerateMaze(startRow - 2, startCol);
}

void AMazeGeneratorActor::MoveDown(int32 startRow, int32 startCol)
{
	// check if we do not go out of bounds;
	if (startRow + 2 >= Maze.Num() - 1) {
		return;
	}
	// check if the next two cells are free
	if (Maze[startRow + 1][startCol] == 0 || Maze[startRow + 2][startCol] == 0) {
		return;
	}
	// if we do not go out of bound and the cells are free, we move to that direction
	Maze[startRow + 1][startCol] = 0;
	Maze[startRow + 2][startCol] = 0;
	GenerateMaze(startRow + 2, startCol);
}

void AMazeGeneratorActor::MoveLeft(int32 startRow, int32 startCol)
{
	// check if we do not go out of bounds;
	if (startCol - 2 < 1) {
		return;
	}
	// check if the next two cells are free
	if (Maze[startRow][startCol - 1] == 0 || Maze[startRow][startCol - 2] == 0) {
		return;
	}
	// if we do not go out of bound and the cells are free, we move to that direction
	Maze[startRow][startCol - 1] = 0;
	Maze[startRow][startCol - 2] = 0;
	GenerateMaze(startRow, startCol - 2);
}

void AMazeGeneratorActor::MoveRight(int32 startRow, int32 startCol)
{
	// check if we do not go out of bounds;
	if (startCol + 2 >= Maze[0].Num() - 1) {
		return;
	}
	// check if the next two cells are free
	if (Maze[startRow][startCol + 1] == 0 || Maze[startRow][startCol + 2] == 0) {
		return;
	}
	// if we do not go out of bound and the cells are free, we move to that direction
	Maze[startRow][startCol + 1] = 0;
	Maze[startRow][startCol + 2] = 0;
	GenerateMaze(startRow, startCol + 2);
}

void AMazeGeneratorActor::ShuffleArray(TArray<int32>& myArray)
{
	if (myArray.Num() > 0)
	{
		int32 LastIndex = myArray.Num() - 1;
		for (int32 i = 0; i <= LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				myArray.Swap(i, Index);
			}
		}
	}
}

// Called every frame
void AMazeGeneratorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

