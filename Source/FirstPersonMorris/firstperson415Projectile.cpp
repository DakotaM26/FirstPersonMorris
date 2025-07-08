// Fill out your copyright notice in the Description page of Project Settings.


#include "firstperson415Projectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h
// Sets default values
Afirstperson415Projectile::Afirstperson415Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ballMesh = CreateDefaultSubobject<UStaticMeshComponent>("Ball Mesh");

	//Set as root component.
	RootComponent = CollisionComp;

	ballMesh->SetupAttachment(CollisionComp);

}

// Called when the game starts or when spawned
void Afirstperson415Projectile::BeginPlay()
{
	Super::BeginPlay();
	randColor = FLinearColor(UKismetMathLibrary::execRandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::execRandomFloatInRange(0.f, 1.f);

	dmiMat = UMaterialInstanceDynamic::Create(projMat, this);
	ballMesh->SetMaterial(0, dmiMat);

	dmiMat->SetVectorParameterValue("projColor", randColor);

}
		void Afirstperson412Projectile::OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
		{
			// If it hit object during gameplay.
			if (OtherActor != nullptr)
			{
				float frameNum = UKismetMathLibrary::RandomFloatInRange(0.f, 3.f);// Adjust the frame.

				// Spawns Decal
				auto Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), baseMat, FVector(UKismetMathLibrary::RandomFloatInRange(20.f, 40.f)), Hit.Location, Hit.Normal.Rotation(), 0.f);
				auto MatInstance = Decal->CreateDynamicMaterialInstance();// Creating new material by using decal.

				MatInstance->SetVectorParameterValue("Color", randColor);
				MatInstance->SetScalarParameterValue("Frame", frameNum);
			}
		}
	
