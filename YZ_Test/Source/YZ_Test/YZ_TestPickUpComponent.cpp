// Copyright Epic Games, Inc. All Rights Reserved.

#include "YZ_TestPickUpComponent.h"

UYZ_TestPickUpComponent::UYZ_TestPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UYZ_TestPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UYZ_TestPickUpComponent::OnSphereBeginOverlap);
}

void UYZ_TestPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AYZ_TestCharacter* Character = Cast<AYZ_TestCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
