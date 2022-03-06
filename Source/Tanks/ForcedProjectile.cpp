// Fill out your copyright notice in the Description page of Project Settings.


#include "ForcedProjectile.h"

AForcedProjectile::AForcedProjectile()
{
	Mesh->BodyInstance.SetInstanceSimulatePhysics(true);
	Mesh->BodyInstance.bLockZTranslation = true;
	Mesh->SetEnableGravity(false);
	Mesh->AddForce(GetActorForwardVector() * StartEngineThrust);
}

void AForcedProjectile::Tick(float DeltaSeconds)
{
	Mesh->AddForce(GetActorForwardVector() * EngineThrust);

	if (FVector::Dist(GetActorLocation(), StartPosition) > FireRange)
	{
		Stop();
	}
}

void AForcedProjectile::Start()
{
	Mesh->BodyInstance.SetInstanceSimulatePhysics(true);
	Super::Start();
}

void AForcedProjectile::Stop()
{
	Mesh->BodyInstance.SetInstanceSimulatePhysics(false);
	Super::Stop();
}
