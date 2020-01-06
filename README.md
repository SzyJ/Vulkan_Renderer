# Vulkan Tutorial Renderer
🔥 | Simple Vulkan renderer built with Vulkan Tutorial

This project setup assumes that the Vulkan SDK is installed and therefore ```VULKAN_SDK``` environment variable is defined.

If you wish to clone this project, make sure to clone all the submodules too:
```
git clone --recursive https://github.com/SzyJ/Vulkan_Renderer
```
... or ...
```
git clone https://github.com/SzyJ/Vulkan_Renderer
cd Vulkan_Renderer
git submodule init
git submodule update
```

## Premake
This project uses [premake](https://github.com/premake/premake-core) to generate desired project files.

```generate_vs2017.bat``` or ```generate_vs2019.bat``` scripts can be used to generate a Visual Studio solution.
