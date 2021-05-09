#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class MINECPPRAFT_API ABlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* SM_Block;

	uint8 MinimumMaterial;

	UPROPERTY(EditDefaultsOnly)
	float Resistance;

	UPROPERTY(BlueprintReadWrite)
	float BreakingStage; // when gets to 6th stage the block gets destroyed completely, starts at 0

	// When we want to break to another stage
	void Break();

	// Reset breaking stage
	void ResetBlock();

	// When we fully broke down the block
	void OnBroken(bool HasRequiredPickaxe); // some materials require certain lvl of pickaxe to be broken down

};
