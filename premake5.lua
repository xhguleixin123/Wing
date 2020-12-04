workspace "Wing"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wing"
    location "Wing"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "wpch.h"
    pchsource "Wing/src/wpch.cpp"

    includedirs
    {
        "Wing/vendor/spdlog/include",
        "Wing/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "W_PLATFORM_WINDOWS",
            "W_BUILD_DLL",
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "W_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "W_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "W_DIST"
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
        "Wing/vendor/spdlog/include",
        "Wing/src"
    }

    links
    {
        "Wing"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "W_PLATFORM_WINDOWS",
        }
        
    filter "configurations:Debug"
        defines "W_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "W_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "W_DIST"
        optimize "On"

    