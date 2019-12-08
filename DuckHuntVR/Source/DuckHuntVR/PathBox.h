// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathBox.generated.h"

class UBoxComponent; 
class ADuck;

UCLASS()
class DUCKHUNTVR_API APathBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Where the path nodes for the ducks will spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* NodeBox;

	TArray<ADuck*> ducks;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
