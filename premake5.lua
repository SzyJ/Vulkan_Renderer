workspace "Vulkan_Renderer"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "renderer"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Include dependencies --
    if not root_dir then
        root_dir = "%{wks.location}/renderer"
    end

    includes = {}
    includes["spdlog"] = (root_dir .. "/libs/spdLog/include")
    includes["glfw"] = (root_dir .. "/libs/glfw/include")
    includes["glm"] = (root_dir .. "/libs/glm")

    -- Dependency projects --
    include "config/premake/glfw.lua"

    -- Main project --
    include "config/premake/renderer.lua"
