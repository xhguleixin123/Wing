workspace "Wing"
    startproject "Sandbox"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Wing/vendor/GLFW/include"
IncludeDir["Glad"] = "Wing/vendor/Glad/include"
IncludeDir["ImGui"] = "Wing/vendor/imgui"

include "Wing/vendor/GLFW"
include "Wing/vendor/Glad"
include "Wing/vendor/imgui"



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
        "Wing/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "W_PLATFORM_WINDOWS",
            "W_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "W_DEBUG"
        buildoptions "/MD"
        symbols "On"

    filter "configurations:Release"
        defines "W_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "W_DIST"
        buildoptions "/MD"
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
        buildoptions "/MD"
        symbols "On"

    filter "configurations:Release"
        defines "W_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "W_DIST"
        buildoptions "/MD"
        optimize "On"

    