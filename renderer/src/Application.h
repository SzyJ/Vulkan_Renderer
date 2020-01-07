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

    void Init();
    void MainLoop();
    void CleanUp();
};