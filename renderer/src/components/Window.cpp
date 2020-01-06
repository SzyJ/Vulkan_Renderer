#include "Window.h"

Window::Window() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window = glfwCreateWindow(c_Width, c_Height, "Vulkan", nullptr, nullptr);
}

Window::~Window() {
    glfwDestroyWindow(m_Window);

    glfwTerminate();
}

void Window::Update() {
    glfwPollEvents();
}

bool Window::IsOpen() {
    return !glfwWindowShouldClose(m_Window);
}
