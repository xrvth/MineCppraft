// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MineCppraft : ModuleRules
{
	public MineCppraft(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
