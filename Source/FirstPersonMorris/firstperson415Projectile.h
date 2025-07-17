// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)

class FIRSTPERSONMORRIS_API Afirstperson415Projectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* ballMesh;

	UPROPERTY(EditAnywhere)
	    UMaterial* baseMat;

	UPROPERTY()
	    FLinearColor randColor;
	
		//Niagara System is identfy with colorP
	UPROPERTY(EditAnywhere)
	    UNiagaraSystem* colorP;

public:	
	// Sets default values for this actor's properties
	Afirstperson415Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
