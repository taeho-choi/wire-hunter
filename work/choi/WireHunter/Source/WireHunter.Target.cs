// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class WireHunterTarget : TargetRules
{
	public WireHunterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("WireHunter");
		// Ensure that we compile with the Steam OSS
		bUsesSteam = true;
	}
}
