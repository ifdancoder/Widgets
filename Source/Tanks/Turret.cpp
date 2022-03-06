// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "Components/ArrowComponent.h"
#include "Cannon.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Tanks.h"
#include "HealthComponent.h"
#include "Logging/LogMacros.h"
#include <DrawDebugHelpers.h>

// Sets default values
ATurret::ATurret()
{
	PrimaryActorTick.TickInterval = 0.005f;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

}

void ATurret::Destroyed()
{
	Super::Destroyed();

	if (Cannons.Num())
	{
		Cannons[CurrentCannonIndex]->Destroy();
	}
}

void ATurret::Targeting()
{
	if (IsPlayerInRange())
	{
		RotateToPlayer();
	}

	if (CanFire() && Cannons[CurrentCannonIndex] && Cannons[CurrentCannonIndex]->IsReadyToFire() && IsPlayerInRange())
	{
		Fire();
	}
}

void ATurret::RotateToPlayer()
{
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), PlayerPawn->GetActorLocation());
	FRotator CurrRotation = TurretMesh->GetComponentRotation();

	/*UE_LOG(LogTanks, Verbose, TEXT("T: (%f, %f, %f), C: (%f, %f, %f)"), TargetRotation.Roll, TargetRotation.Pitch, TargetRotation.Yaw,
																		CurrRotation.Roll, CurrRotation.Pitch, CurrRotation.Yaw);*/
	TargetRotation.Pitch = CurrRotation.Pitch;
	TargetRotation.Roll = CurrRotation.Roll;
	TurretMesh->SetWorldRotation(FMath::RInterpConstantTo(CurrRotation, TargetRotation, GetWorld()->GetDeltaSeconds(), TargetingSpeed));
}

bool ATurret::IsPlayerInRange()
{
	FHitResult HitResult;
	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = PlayerPawn->GetActorLocation();
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("AI Vission Trace")), true, this);
	TraceParams.bReturnPhysicalMaterial = false;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, TraceParams))
	{
		//DrawDebugLine(GetWorld(), TraceStart, HitResult.Location, FColor::Red, false, 0.1f, 0, 5);
		if (HitResult.Actor != PlayerPawn)
		{
			return false;
		}
	}
	/*else
	{
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 0.1f, 0, 5);
	}*/

	return FVector::DistSquared(PlayerPawn->GetActorLocation(), GetActorLocation()) <= FMath::Square(TargetingRange);
}

bool ATurret::CanFire()
{
	FVector TargetingDir = TurretMesh->GetForwardVector();
	FVector DirToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
	DirToPlayer.Normalize();
	float AimAngle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(TargetingDir, DirToPlayer)));

	return AimAngle <= Accuracy;
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		Targeting();
	}
}

void ATurret::TakeDamage(const FDamageData& DamageData)
{
	HealthComponent->TakeDamage(DamageData);
}

float ATurret::GetScoreForKill()
{
	return ScoreForKill;
}
