// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARLProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API AARLProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARLProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* EffectComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
