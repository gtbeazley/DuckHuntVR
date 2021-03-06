// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Button3D.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class DUCKHUNTVR_API AButton3D : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButton3D();

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

	/* Sets the displayText variable */
	UFUNCTION(BlueprintCallable)
		void SetText(FText a_text);

	/* Gets the displayText variable */
	UFUNCTION(BlueprintCallable)
		FText GetText();
	
	/* This will only be affected by the player */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool isHighlighted = false;

	//the previous state of being highlighted
	bool wasHighlighted = false;
};
