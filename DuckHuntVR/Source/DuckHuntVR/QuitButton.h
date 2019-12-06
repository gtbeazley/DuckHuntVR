// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuitButton.generated.h"

UCLASS()
class DUCKHUNTVR_API AQuitButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuitButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* The static mesh of the button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

	/* The static mesh of the button highlighted */
	UMaterialInterface* HLMat;

	/* The static mesh of the button when unhighlighted*/
	UMaterialInterface* UHLMat;

	/* Used for the widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		FText displayText;
public:	
	/* Mesh Accessor */
	UFUNCTION(BlueprintCallable)
		UStaticMeshComponent* GetMesh();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool Highlighted = false;
	
};
