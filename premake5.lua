workspace "Macarons"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Macarons"
    location "Macarons"
    kind "Staticlib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mrpch.h"
    pchsource "Macarons/src/mrpch.cpp"

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
		defines "MR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MR_DIST"
		runtime "Release"
        optimize "on"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "Macarons/vendor/spdlog/include",
		"Macarons/src",
		"Macarons/vendor"
    }

    links
	{
		"Macarons"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "MR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MR_DIST"
		runtime "Release"
		optimize "on"
