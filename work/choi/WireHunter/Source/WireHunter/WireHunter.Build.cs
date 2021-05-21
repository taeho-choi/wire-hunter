// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WireHunter : ModuleRules
{
	public WireHunter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CableComponent" });
		//PrivateDependencyModuleNames.AddRange(new string[] { "CableComponent" });

		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CableComponent" });

		//PrivateDependencyModuleNames.AddRange(new string[] { "CableComponent" });
		//PrivateIncludePathModuleNames.AddRange(new string[] { "CableComponent" });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CableComponent", "Paper2D"});
		PublicIncludePaths.AddRange(new string[] { "CableComponent/Public", "CableComponent/Classes" });

	}
}
