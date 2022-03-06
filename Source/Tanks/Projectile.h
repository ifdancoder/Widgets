// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Particles/ParticleSystemComponent.h>
#include "Projectile.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetScoreOnKill, float, Amount);

UCLASS()
class TANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UParticleSystemComponent* HitVisualEffect;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UAudioComponent* HitAudioEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float FireRange = 1000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
	float Damage = 1.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Physics")
	float Mass = 1.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Scoring")
	float Score = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Effects")
	float DestroyingEffectsTimer = 0.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Expansive")
	bool bIsExpansiveProjectile = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Expansive")
	float ExplosionRange = 1000.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Expansive")
	float ExplosionImpulse = 100.f;

public:
	AProjectile();

	virtual void Start();
	virtual void Stop();
	void StoppingEffects();
	void SetMoveSpeed(float InMoveSpeed);
	float GetMoveSpeed();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	FGetScoreOnKill GetScoreOnKill;

protected:
	UFUNCTION()
	virtual void OnMeshHit(class UPrimitiveComponent* HittedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);
	void DamageDealing(AActor* OtherActor, UPrimitiveComponent* OtherComponent, const FHitResult& HitResult, const FVector& Impulse);
protected:
	FVector StartPosition;
	FTimerHandle DestroyingEffectsTimerHandle;
};