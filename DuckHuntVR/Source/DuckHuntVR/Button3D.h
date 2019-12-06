// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Button3D.generated.h"

class UStaticMeshComponent;

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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Mesh Accessor */
	UFUNCTION(BlueprintCallable)
		UStaticMeshComponent* GetMesh();

	/* Sets the displayText variable */
	UFUNCTION(BlueprintCallable)
		void SetText(FText a_text);

	/* Gets the displayText variable */
	UFUNCTION(BlueprintCallable)
		FText GetText();
	
	bool Highlighted;
};
