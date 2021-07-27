// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WireHunter : ModuleRules
{
	public WireHunter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Paper2D", "AdvancedSessions", "AdvancedSteamSessions" });
		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CableComponent" });
		//PrivateDependencyModuleNames.AddRange(new string[] { "CableComponent" });

		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "CableComponent" });

		//PrivateDependencyModuleNames.AddRange(new string[] { "CableComponent" });
		//PrivateIncludePathModuleNames.AddRange(new string[] { "CableComponent" });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "CableComponent", "Paper2D", "AdvancedSessions", "OnlineSubsystem", "OnlineSubsystemUtils", "Networking", "Sockets", "OnlineSubsystemSteam", "OnlineSubsystemNull", "MoviePlayer", "AdvancedSteamSessions" });
		PublicIncludePaths.AddRange(new string[] { "CableComponent/Public", "CableComponent/Classes", "Paper2D/Public", "Paper2D/Classes" });

		//PrivateDependencyModuleNames.Add("OnlineSubsystem");
		//PrivateDependencyModuleNames.Add("OnlineSubsystemNull");
		//if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Linux))
		//{
		//	if (Target.bCompileSteamOSS == true)
		//	{
		//		DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//	}
		//}

		AddEngineThirdPartyPrivateStaticDependencies(Target, "Steamworks");
	}
}
