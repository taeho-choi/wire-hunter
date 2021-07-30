// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WireHunter : ModuleRules
{
	public WireHunter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "CableComponent", "Paper2D"});
		PublicIncludePaths.AddRange(new string[] { "CableComponent/Public", "CableComponent/Classes", "Paper2D/Public", "Paper2D/Classes" });
	}
}
