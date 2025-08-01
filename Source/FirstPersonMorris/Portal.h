// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "Portal.generated.h"

class FirstPersonMorrisCharacter;
UCLASS()
class FIRSTPERSONMORRIS_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Set Static Mesh Component
    UPROPERTY(EditAnywhere)
	    UStaticMeshComponent* mesh;
	// Set Scene Capture Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	    USceneCaptureComponent2D* sceneCapture;

	UPROPERTY(EditAnywhere)
	    UArrowComponent* rootArrow;

	// Set Texture Render Target
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	    UTextureRenderTarget2D* renderTarget;

	UPROPERTY(EditAnywhere)
	    UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	    APortal* OtherPortal;

	UPROPERTY(EditAnywhere)
	    UMaterialInterface* mat;

	UFUNCTION()
	   void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	    void SetBool(AFirstPersonMorrisCharacter* playerChar);

	UFUNCTION()
	    void UpdatePortals();
};
