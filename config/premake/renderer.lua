project "renderer"
    location (root_dir)
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs {
        "%{prj.location}/src",
        "$(VULKAN_SDK)/include",
        "%{includes.spdlog}",
        "%{includes.glfw}",
        "%{includes.glm}"
    }

    links {
        "$(VULKAN_SDK)/Lib/vulkan-1.lib",
        "glfw"
    }

    defines {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "VR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "VR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "VR_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "VR_DIST"
        runtime "Release"
        optimize "On"
