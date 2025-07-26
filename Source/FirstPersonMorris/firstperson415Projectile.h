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
	// Sets Collision Component
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;
	// Sets Projectile Movement Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	// Sets ball as a mesh
	UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* ballMesh;
	// Sets Base Material
	UPROPERTY(EditAnywhere)
	    UMaterial* baseMat;
	// Sets the random color and linear color
	UPROPERTY()
	    FLinearColor randColor;
	
	//Sets the Niagara System and colorP
	UPROPERTY(EditAnywhere)
	    UNiagaraSystem* colorP;

public:	
	// Sets default values for this actor's properties
	Afirstperson415Projectile();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
