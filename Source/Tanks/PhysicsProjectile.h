// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "PhysicsMovementComponent.h"
#include "PhysicsProjectile.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API APhysicsProjectile : public AProjectile
{
	GENERATED_BODY()
	
public:
	APhysicsProjectile();

	virtual void Start() override;
	virtual void Stop() override;
	virtual void Tick(float DeltaTime) override;
	float GetGravity();
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UPhysicsMovementComponent* MovementComponent;
};
