// Fill out your copyright notice in the Description page of Project Settings.

#include "PathBox.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Duck.h"

// Sets default values
APathBox::APathBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NodeBox = CreateDefaultSubobject<UBoxComponent>("NodeBox");
}

// Called when the game starts or when spawned
void APathBox::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> outActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADuck::StaticClass(), outActors);

	for (auto actor : outActors)
		if(Cast<ADuck>(actor))
			ducks.Push(Cast<ADuck>(actor));
}

// Called every frame
void APathBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto duck : ducks)
		if (duck->NeedsNewLoc())
			duck->SetTarLoc(UKismetMathLibrary::RandomPointInBoundingBox(NodeBox->GetComponentLocation(), NodeBox->GetScaledBoxExtent()));
}

