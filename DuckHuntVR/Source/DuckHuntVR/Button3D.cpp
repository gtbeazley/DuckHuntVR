// Fill out your copyright notice in the Description page of Project Settings.

#include "Button3D.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AButton3D::AButton3D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshObject(TEXT("StaticMesh'/Game/Assets/Cube_Asset.Cube_Asset'"));
	Mesh->SetStaticMesh(meshObject.Object);

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> meshMat(TEXT("Material'/Game/Materials/Black.Black'"));
	Mesh->SetMaterial(0, meshMat.Object);
}

// Called when the game starts or when spawned
void AButton3D::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AButton3D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AButton3D::SetText(FText a_text)
{
	displayText = a_text;
}

FText AButton3D::GetText()
{
	return displayText;
}

