#include "Application.h"
#include "utils/InstanceBuilder.h"

void Application::Init() {
    SetupInstance();

    //PrintAvailableExtensions();
}

void Application::SetupInstance() {
    const char** extensions;
    uint32_t extensionCount;

    extensions = m_Window.GetRequiredExtentions(extensionCount);

    if (InstanceBuilder::Build(m_Instance, extensions, extensionCount) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create instance!");
    }
}

void Application::PrintAvailableExtensions() {
    uint32_t allExtensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &allExtensionCount, nullptr);
    std::vector<VkExtensionProperties> allExtensions(allExtensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &allExtensionCount, allExtensions.data());

    std::cout << "available extensions [" << allExtensionCount << "]:" << std::endl;

    for (const auto& extension : allExtensions) {
        std::cout << "\t" << extension.extensionName << std::endl;
    }
}

void Application::CleanUp() {
    vkDestroyInstance(m_Instance, nullptr);
}

void Application::MainLoop() {
    while (m_Window.IsOpen()) {
        m_Window.Update();


    }
}
