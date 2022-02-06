workspace "tordle"
	configurations { "debug", "release" }

project "tordle"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	warnings "Extra"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "obj"

	files { "src/**.hpp", "src/**.cpp" }

	filter { "configurations:debug" }
		symbols "On"
		defines { "DEBUG" }

	filter { "configurations:release" }
		optimize "On"
