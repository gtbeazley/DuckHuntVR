// Fill out your copyright notice in the Description page of Project Settings.

#include "QuitButton.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"


// Sets default values
AQuitButton::AQuitButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshObject(TEXT("StaticMesh'/Game/Assets/Cube_Asset.Cube_Asset'"));
	Mesh->SetStaticMesh(meshObject.Object);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> UHLMat(TEXT("Material'/Game/Materials/Black.Black'"));
	UnhighlightedMaterial = UHLMat.Object;
	Mesh->SetMaterial(0, UnhighlightedMaterial);


	static ConstructorHelpers::FObjectFinder<UMaterialInterface> HLMat(TEXT("Material'/Game/Materials/Green.Green'"));
	HighlightedMaterial = HLMat.Object;
}

// Called when the game starts or when spawned
void AQuitButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuitButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!wasHighlighted && isHighlighted)
		Mesh->SetMaterial(0, HighlightedMaterial);
	else if (wasHighlighted && !isHighlighted)
		Mesh->SetMaterial(0, UnhighlightedMaterial);

	wasHighlighted = isHighlighted;
}

