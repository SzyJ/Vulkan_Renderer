#pragma once

#include "Core.h"

class Window {
public:
    Window();
    ~Window();

    void Update();
    bool IsOpen();

    const char** GetRequiredExtentions(uint32_t& extensionCount);

private:
    const int c_Width = 800;
    const int c_Height = 600;

    GLFWwindow* m_Window;
};