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

	/* Material When the actor is unhighlighted */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* UnhighlightedMaterial;

	/* Material When the actor is highlighted */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* HighlightedMaterial;

	/* The static mesh of the button */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;

	/* Used for the widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		FText displayText;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* This will only be affected by the player */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isHighlighted = false;

	bool wasHighlighted = false;
};
