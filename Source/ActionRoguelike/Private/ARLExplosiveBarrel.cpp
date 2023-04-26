// Fill out your copyright notice in the Description page of Project Settings.


#include "ARLExplosiveBarrel.h"

#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AARLExplosiveBarrel::AARLExplosiveBarrel()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetSimulatePhysics(true);
	// StaticMeshComponent->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	RootComponent = StaticMeshComponent;

	ImpulseComponent = CreateDefaultSubobject<URadialForceComponent>("ImpulseComponent");
	ImpulseComponent->SetupAttachment(StaticMeshComponent);


	ImpulseComponent->SetAutoActivate(false);
	ImpulseComponent->Radius = 750.0f;
	ImpulseComponent->ImpulseStrength = 2500.0f;
	ImpulseComponent->bImpulseVelChange = true;

	ImpulseComponent->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void AARLExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
}

void AARLExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AARLExplosiveBarrel::OnActorHit);
}

void AARLExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	ImpulseComponent->FireImpulse();

	UE_LOG(LogTemp, Log, TEXT("OnActorHit in Explosive Barrel"));
	
	// %s = string
	// %f = float
	// logs: "OtherActor: MyActor_1, at gametime: 124.4" 
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CombinedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
}

// Called every frame
void AARLExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

