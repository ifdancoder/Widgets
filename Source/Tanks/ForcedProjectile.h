#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "ForcedProjectile.generated.h"

/**
 *
 */
UCLASS()
class TANKS_API AForcedProjectile : public AProjectile
{
	GENERATED_BODY()

public:
	AForcedProjectile();

	virtual void Tick(float DeltaSeconds) override;
	virtual void Start() override;
	virtual void Stop() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float EngineThrust = 1.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float StartEngineThrust = 1.f;
};