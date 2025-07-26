// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcTerrian.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
AProcTerrian::AProcTerrian()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh");
	ProcMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AProcTerrian::BeginPlay()
{
	Super::BeginPlay();
	//Create Vertices and Triangles, call upon the mesh and set materials
	CreateVertices();
	CreateTriangles();
	ProcMesh->CreateMeshSection(sectionID, Vertices, Triangles, Normals, UV0, UpVertexColors, TArray<FProcMeshTangent>(), true);
	ProcMesh->SetMaterial(0, Mat);
}

// Called every frame
void AProcTerrian::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProcTerrian::AlterMesh(FVector impactPoints)
{
	//Cylcing through a for loop and checking the vertices
	for (int i = 0; i < Vertices.Num(); i++)
	{
		//Set up local variable
		FVector tempVector = impactPoints - this->GetActorLocation();
		//Looking for point and grabbing the radius
		if (FVector(Vertices[i] - tempVector).Size() < radius)
		{
			//Set the vertices in index and subtract it by the depth
			Vertices[i] = Vertices[i] - Depth;
			ProcMesh->UpdateMeshSection(sectionID, Vertices, Normals, UV0, UpVertexColors, TArray<FProcMeshTangent>());
		}
	}
}

void AProcTerrian::CreateVertices()
{
	for (int X = 0; X <= XSize; X++)
	{
		for (int Y = 0; Y <= YSize; Y++)
		{
			float Z = FMath::PerlinNoise2D(FVector2D(X * NoiseScale + 0.1, Y * NoiseScale + 0.1)) * ZMultiplier;
			GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Yellow, FString::Printf(TEXT("Z %f"), Z));
			Vertices.Add(FVector(X * Scale, Y * Scale, Z));
			UV0.Add(FVector2D(X * UVScale, Y * UVScale));
		}
	}
}

void AProcTerrian::CreateTriangles()
{
	//Calculating the vertices
	int Vertex = 0;

	for (int X = 0; X < XSize; X++)
	{
		for (int Y = 0; Y < YSize; Y++)
		{
			Triangles.Add(Vertex);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 1);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 2);
			Triangles.Add(Vertex + YSize + 1);

			Vertex++;

		}
		Vertex++;
	}
}

