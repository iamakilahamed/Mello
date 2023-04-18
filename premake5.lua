workspace "Mello"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mello"
	location "Mello"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MELLO_PLATFORM_WINDOWS",
			"MELLO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MELLO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MELLO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MELLO_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Mello/vendor/spdlog/include",
		"Mello/src"
	}

	links
	{
		"Mello"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MELLO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MELLO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MELLO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MELLO_DIST"
		optimize "On"