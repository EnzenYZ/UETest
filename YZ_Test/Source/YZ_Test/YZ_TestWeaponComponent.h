// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "YZ_TestWeaponComponent.generated.h"

class USphereComponent;
class AYZ_TestCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YZ_TEST_API UYZ_TestWeaponComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()

public:
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class AYZ_TestProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;
	
	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector MuzzleOffset;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* FireMappingContext;

	/** Fire Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* FireAction;

	/** Sets default values for this component's properties */
	UYZ_TestWeaponComponent();

	/** Attaches the actor to a FirstPersonCharacter */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	bool AttachWeapon(AYZ_TestCharacter* TargetCharacter);
	
	/** Make the weapon Fire a Projectile */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();

	/** Trigger gravity gun effect */
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Attract();
protected:
	/** Ends gameplay for this component. */
	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	/** The Character holding this weapon*/
	AYZ_TestCharacter* Character;
	TArray<AActor*> OverlappingTargets;
	FVector GetTargetLocation();
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Gravity Gun")
	float FiringForce;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Gravity Gun")
	float PickUpRadius;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Gravity Gun")
	float AttractionForce;
	
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category="Components")
	USphereComponent* SphereCollider;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere, Category = "Gravity Gun")
	AActor* Target;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Gravity Gun")
	bool SingleTarget;
};
