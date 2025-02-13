// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Molotov.generated.h"

class UCapsuleComponent;

UCLASS()
class YZ_TEST_API AMolotov : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMolotov();

	virtual void BeginPlay() override;	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FlameSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

public:

	UPROPERTY(BlueprintReadOnly, Category="Gameplay")
	TArray<AActor*> OverlappingTargets;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Molotov")
	float AoeRadius;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Molotov")
	float AoeHeight;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category="Molotov")
	float Duration;
	
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category="Molotov")
	UCapsuleComponent* AoeCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Molotov", meta = (AllowPrivateAccess = "true"))
	UDecalComponent* MollyDecal;
};
