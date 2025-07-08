// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson415Projectile.generated.h"

UCLASS()
class FIRSTPERSONMORRIS_API Afirstperson415Projectile : public AActor
{
	GENERATED_BODY()
	// Set and identify the ball mesh.
	
	UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* ballMesh;

	// Sets and identify the base material.
	UPROPERTY(EditAnywhere)
	    UMaterial* baseMAT;
	// Set ups random color.
     UPROPERTY()
	     FLinearColor randColor;
     // Set up projectile material.
	 UPROPERTY(EditAnywhere)
	     UMaterialInterface* projMat;
	// DMI Material
	 UPROPERTY()
	     UMaterialInstanceDynamic* dmiMat;

public:	
	// Sets default values for this actor's properties
	Afirstperson415Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
