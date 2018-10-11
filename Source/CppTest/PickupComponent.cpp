// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupComponent.h"


// Sets default values for this component's properties
UPickupComponent::UPickupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickupComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPickupComponent::Pickup(AActor* targetObj)
{
	EAttachmentRule *erule = new EAttachmentRule();

	FAttachmentTransformRules* rules = new FAttachmentTransformRules(*erule,true);
	rules->ScaleRule =EAttachmentRule::KeepWorld;
	rules->LocationRule = EAttachmentRule::KeepWorld;

	targetObj->AttachToActor(m_owner, *rules);

	FVector ParentPos = m_owner->GetActorTransform().GetLocation();
	targetObj->SetActorLocation(ParentPos + Offset);
}

void UPickupComponent::DisEquip(AActor* targetObj)
{
	targetObj->DetachRootComponentFromParent();
}
