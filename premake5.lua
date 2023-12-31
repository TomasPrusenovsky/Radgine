workspace "Radgine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Radgine/vendor/GLFW/include"
IncludeDir["Glad"] = "Radgine/vendor/Glad/include"

group "Dependemcies"
	include "Radgine/vendor/GLFW"
	include "Radgine/vendor/Glad"

group ""

project "Radgine"
	location "Radgine"
	kind "StaticLib"
	language "C++"
	staticruntime "on"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "rpch.h"
	pchsource "Radgine/src/rpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

		-- postbuildcommands
		-- {
		-- 	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		-- }

	filter "configurations:Debug"
		defines "R_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "R_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "R_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Radgine/src",
        "%{IncludeDir.Glad}",
	}

	links
	{
		"Radgine"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

		defines
		{
			"R_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "R_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "R_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "R_DIST"
		runtime "Release"
		optimize "On"
