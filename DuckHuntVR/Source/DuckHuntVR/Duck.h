// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Duck.generated.h"

UCLASS()
class DUCKHUNTVR_API ADuck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADuck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/* location for duck to spawn at */
	FVector StartLoc;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* location for duck to move towards */
	FVector nodeLoc;
	
};
