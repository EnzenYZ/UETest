// Copyright Epic Games, Inc. All Rights Reserved.


#include "YZ_TestWeaponComponent.h"
#include "YZ_TestCharacter.h"
#include "YZ_TestProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstance.h"
#include "Components/SphereComponent.h"
#include "Engine/LocalPlayer.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "Framework/Application/AnalogCursor.h"

// Sets default values for this component's properties
UYZ_TestWeaponComponent::UYZ_TestWeaponComponent() 
{
	// Default offset from the character location for projectiles to spawn
	MuzzleOffset = FVector(300.0f, 0.0f, 30.0f);
	FiringForce = 1000.0f;
	PickUpRadius = 200.0f;
	SingleTarget = true;
	AttractionForce = 500.0f;
	
	OverlappingTargets.Empty();
	
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetSphereRadius(PickUpRadius);
	SphereCollider->SetCollisionResponseToAllChannels(ECR_Overlap);
}

FVector UYZ_TestWeaponComponent::GetTargetLocation()
{
	APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
	const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
	return GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);
}

// Attract a movable obj while Shoot Key is being held down
void UYZ_TestWeaponComponent::Attract()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;	
	}
	
	//Check if a movable object is within the pickup radius
	//Attract movable object in radius
	if (SingleTarget)
	{
		if (Target == nullptr)
		{
			SphereCollider->GetOverlappingActors(OverlappingTargets, AStaticMeshActor::StaticClass());
			if (OverlappingTargets.Num() > 0)
			{
				Target = OverlappingTargets[0];
			}
		}
		else if (Target != nullptr)
		{
			if (UWorld* const World = GetWorld(); World != nullptr)
			{
				UPrimitiveComponent* TargetComp = Target->FindComponentByClass<UPrimitiveComponent>();
				FVector DirectionToAttract = (GetTargetLocation() - TargetComp->GetComponentLocation() ).GetSafeNormal();

				TargetComp->SetSimulatePhysics(false);	

				FVector UpdatedLocation = TargetComp->GetComponentLocation() + DirectionToAttract * AttractionForce * FApp::GetDeltaTime();
				TargetComp->SetWorldLocation(UpdatedLocation);
			}
		}
	}
	else
	{	// Multi target gravity gun
		
		SphereCollider->GetOverlappingActors(OverlappingTargets, AStaticMeshActor::StaticClass());
		
		if (OverlappingTargets.Num() > 0)
		{
			if (UWorld* const World = GetWorld(); World != nullptr)
			{
				for(auto t : OverlappingTargets)
				{
					UPrimitiveComponent* TargetComp = t->FindComponentByClass<UPrimitiveComponent>();
					FVector DirectionToAttract = (GetTargetLocation() - TargetComp->GetComponentLocation() ).GetSafeNormal();

					TargetComp->SetSimulatePhysics(false);	

					FVector UpdatedLocation = TargetComp->GetComponentLocation() + DirectionToAttract * AttractionForce * FApp::GetDeltaTime();
					TargetComp->SetWorldLocation(UpdatedLocation);
				}
			}
		}
	}
}

// Mod to release the gravity afflicted obj
void UYZ_TestWeaponComponent::Fire()
{
	if (Character == nullptr || Character->GetController() == nullptr)
	{
		return;
	}

	if (SingleTarget)
	{
		if (Target == nullptr)
			return;
		else
		{
			UPrimitiveComponent* TargetComp = Target->FindComponentByClass<UPrimitiveComponent>();
			
			TargetComp-> SetSimulatePhysics(true);
			TargetComp-> AddImpulse(this->GetRightVector() * FiringForce, NAME_None, true);

			OverlappingTargets.Empty();	
			Target = nullptr;
		}
	}
	else
	{
		if (OverlappingTargets.Num() > 0)
		{
			for(auto t : OverlappingTargets)
			{
				UPrimitiveComponent* TargetComp = t->FindComponentByClass<UPrimitiveComponent>();

				TargetComp-> SetSimulatePhysics(true);
				TargetComp-> AddImpulse(this->GetRightVector() * FiringForce, NAME_None, true);
			}
			OverlappingTargets.Empty();
		}
	}
	
	// Try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, Character->GetActorLocation());
	}
	
	// Try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

bool UYZ_TestWeaponComponent::AttachWeapon(AYZ_TestCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	// Check that the character is valid, and has no weapon component yet
	if (Character == nullptr || Character->GetInstanceComponents().FindItemByClass<UYZ_TestWeaponComponent>())
	{
		return false;
	}

	// Attach the weapon to the First Person Character
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	AttachToComponent(Character->GetMesh1P(), AttachmentRules, FName(TEXT("GripPoint")));

	//Collider Y should be Radius + 60 to ensure it is always in front of the barrel
	SphereCollider->AttachToComponent(this, AttachmentRules);
	SphereCollider->SetSphereRadius(PickUpRadius);
	SphereCollider->AddRelativeLocation(FVector(0.0f, PickUpRadius + 60.f, 0.0f));
	// Set up action bindings
	if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Set the priority of the mapping to 1, so that it overrides the Jump action with the Fire action when using touch input
			Subsystem->AddMappingContext(FireMappingContext, 1);
		}

		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
		{
			// Fire
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &UYZ_TestWeaponComponent::Fire);
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &UYZ_TestWeaponComponent::Attract);
		}
	}
	
	return true;
}

void UYZ_TestWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// ensure we have a character owner
	if (Character != nullptr)
	{
		// remove the input mapping context from the Player Controller
		if (APlayerController* PlayerController = Cast<APlayerController>(Character->GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->RemoveMappingContext(FireMappingContext);
			}
		}
	}

	// maintain the EndPlay call chain
	Super::EndPlay(EndPlayReason);
}