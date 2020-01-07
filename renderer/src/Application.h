#pragma once
#include "Core.h"

#include "components/Window.h"

class Application {
public:
    void Run() {
        Init();
        MainLoop();
        CleanUp();
    }

private:
    Window m_Window;
    VkInstance m_Instance;
    VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;

    void Init();
    void SetupInstance();
    void PickPhysicalDevice();
    void PrintAvailableExtensions();



    void MainLoop();
    void CleanUp();
};