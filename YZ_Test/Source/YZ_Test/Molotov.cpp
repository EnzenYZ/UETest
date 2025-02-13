// Fill out your copyright notice in the Description page of Project Settings.


#include "Molotov.h"

#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMolotov::AMolotov()
{
	AoeRadius = 100.f;
	AoeHeight = 10.f;
	AoeCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	AoeCollider->SetCapsuleSize(AoeRadius,AoeHeight	);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AMolotov::BeginPlay()
{
	Super::BeginPlay();
	
	
	SetLifeSpan(Duration);
}

// Called every frame
void AMolotov::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

