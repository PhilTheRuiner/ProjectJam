// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JamProject : ModuleRules
{
	public JamProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
