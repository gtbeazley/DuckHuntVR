// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NodesAndDucks.generated.h"

class ADuck;
class UBoxComponent;

UCLASS()
class DUCKHUNTVR_API ANodesAndDucks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANodesAndDucks();
	
	/* box where random nodes will spawn */
	UPROPERTY(EditAnyhwere, BlueprintReadWrite)
		UBoxComponent* nodeBox;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//list of ducks
	TArray<AActor*> ducks;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
