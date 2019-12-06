// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "NodesAndDucks.h"
#include "Duck.h"

// Sets default values
ANodesAndDucks::ANodesAndDucks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	nodeBox = CreateDefaultSubobject<UBoxComponent>("nodeBox");
	SetRootComponent(nodeBox);

}

// Called when the game starts or when spawned
void ANodesAndDucks::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADuck::StaticClass(), ducks);
	for (auto duck : ducks)
	{
		if (Cast<ADuck>(duck))
			Cast<ADuck>(duck)->nodeLoc = UKismetMathLibrary::RandomPointInBoundingBox(nodeBox->GetComponentLocation(), nodeBox->GetScaledBoxExtent());

	}
	
}

// Called every frame
void ANodesAndDucks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

