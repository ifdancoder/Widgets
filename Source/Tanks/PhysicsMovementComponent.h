// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UPhysicsMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPhysicsMovementComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gravity Params")
	FVector Gravity = FVector(0, 0, -9.8);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Gravity Params")
	FVector Velocity = FVector::ZeroVector;

protected:

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
