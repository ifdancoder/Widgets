// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Tanks.h"
#include "ActorPoolSubsystem.h"
#include "Damageable.h"
#include "GameStructs.h"
#include "Scorable.h"
#include "TankPawn.h"
#include <Components/AudioComponent.h>

// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.TickInterval = 0.005f;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->OnComponentHit.AddDynamic(this, &AProjectile::OnMeshHit);
	Mesh->SetHiddenInGame(true);
	RootComponent = Mesh;

	HitVisualEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Hit Visual Effect"));
	HitVisualEffect->SetupAttachment(Mesh);

	HitAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("Hit Audio Effect"));
	HitAudioEffect->SetupAttachment(Mesh);
}


void AProjectile::Start()
{
	HitVisualEffect->DeactivateSystem();
	PrimaryActorTick.SetTickFunctionEnable(true);
	StartPosition = GetActorLocation();
	Mesh->SetHiddenInGame(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void AProjectile::Stop()
{
	GetScoreOnKill.Clear();
	PrimaryActorTick.SetTickFunctionEnable(false);
	Mesh->SetHiddenInGame(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	UActorPoolSubsystem* Pool = GetWorld()->GetSubsystem<UActorPoolSubsystem>();
	if (Pool->IsActorInPool(this))
	{
		Pool->ReturnActor(this);
	}
	else
	{
		Destroy();
	}

	GetWorld()->GetTimerManager().SetTimer(DestroyingEffectsTimerHandle, this, &AProjectile::StoppingEffects, DestroyingEffectsTimer, false);
}

void AProjectile::StoppingEffects()
{
	HitVisualEffect->DeactivateSystem();
}

void AProjectile::SetMoveSpeed(float InMoveSpeed)
{
	MoveSpeed = InMoveSpeed;
}

float AProjectile::GetMoveSpeed()
{
	return MoveSpeed;
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NextPosition = GetActorLocation() + GetActorForwardVector() * MoveSpeed * DeltaTime;
	SetActorLocation(NextPosition, true);

	if (FVector::Dist(GetActorLocation(), StartPosition) > FireRange)
	{
		Stop();
	}
}

void AProjectile::OnMeshHit(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult)
{
	//UE_LOG(LogTanks, Warning, TEXT("Projectile %s collided with %s. "), *GetName(), *OtherActor->GetName());

	if (OtherActor == GetInstigator())
	{
		Stop();
		return;
	}

	if (bIsExpansiveProjectile)
	{
		FVector StartPos = GetActorLocation();
		FVector EndPos = StartPos + FVector(0.1f);

		FCollisionShape Shape = FCollisionShape::MakeSphere(ExplosionRange);
		FCollisionQueryParams Params = FCollisionQueryParams::DefaultQueryParam;
		Params.AddIgnoredActor(this);
		Params.bTraceComplex = true;
		Params.TraceTag = "Explode Trace";
		TArray<FHitResult> AttackHit;

		FQuat Rotation = FQuat::Identity;

		GetWorld()->DebugDrawTraceTag = "Explode Trace";

		bool bSweepResult = GetWorld()->SweepMultiByChannel
		(
			AttackHit,
			StartPos,
			EndPos,
			Rotation,
			ECollisionChannel::ECC_Visibility,
			Shape,
			Params
		);

		if (bSweepResult)
		{
			for (FHitResult HitResult : AttackHit)
			{
				AActor* HitActor = HitResult.GetActor();
				if (!HitActor)
					continue;

				DamageDealing(OtherActor, OtherComp, HitResult, (HitActor->GetActorLocation() - GetActorLocation()) * ExplosionImpulse);
			}
		}
	}
	else
	{
		DamageDealing(OtherActor, OtherComp, HitResult, Mass * MoveSpeed * GetActorForwardVector());
	}

	Stop();
}

void AProjectile::DamageDealing(AActor* OtherActor, UPrimitiveComponent* OtherComp, const FHitResult& HitResult, const FVector& Impulse)
{
	if (OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(Impulse, HitResult.ImpactPoint);
	}

	if (OtherActor && OtherComp && OtherComp->GetCollisionObjectType() == ECC_Destructible)
	{
		OtherActor->Destroy();
	}
	else if (IDamageable* Damageable = Cast<IDamageable>(OtherActor))
	{
		HitAudioEffect->Play();
		HitVisualEffect->ActivateSystem();

		FDamageData DamageData;
		DamageData.DamageValue = Damage;
		DamageData.Instigator = GetInstigator();
		DamageData.DamageMaker = this;
		Damageable->TakeDamage(DamageData);

		if (IScorable* Scorable = Cast<IScorable>(OtherActor))
		{
			if (OtherActor->IsActorBeingDestroyed())
			{
				UE_LOG(LogTanks, Verbose, TEXT("Destroyed: %s"), *(OtherActor->GetName()));
				if (GetScoreOnKill.IsBound())
				{
					GetScoreOnKill.Broadcast(Scorable->GetScoreForKill());
				}
			}
		}
	}
}
