#include "Block.h"

// Sets default values
ABlock::ABlock()
{
	SM_Block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));

	Resistance = 20.f; // 20.f is a low resistance, the block will be broken very fast
	BreakingStage = 0.f; // always 0 by default
	MinimumMaterial = 0; // 0 for now
}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

void ABlock::Break()
{
	BreakingStage++;

	float CrackingValue = 1.0f - (BreakingStage / 5.f); // 5 stages

	UMaterialInstanceDynamic* MatInstance = SM_Block->CreateDynamicMaterialInstance(0); // first material

	if (MatInstance != nullptr)
	{
		MatInstance->SetScalarParameterValue(FName("CrackingValue"), CrackingValue);
	}

	if (BreakingStage == 5.f)
	{
		OnBroken(true); // now we always have the right tool to destroy blocks, in the future this has to be changed
	}
}

void ABlock::ResetBlock()
{
	BreakingStage = 0.f;

	UMaterialInstanceDynamic* MatInstance = SM_Block->CreateDynamicMaterialInstance(0); // reset breaking stage

	if (MatInstance != nullptr)
	{
		MatInstance->SetScalarParameterValue(FName("CrackingValue"), 1.0f);
	}
}

void ABlock::OnBroken(bool HasRequiredPickaxe)
{
	Destroy();
}

