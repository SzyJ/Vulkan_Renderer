#pragma once

#include "Core.h"

class InstanceBuilder {
public:
    static VkResult Build(VkInstance& instance, const char** extensions = nullptr, uint32_t extensionCount = 0) {

        std::string test(*extensions);

        std::cout << test << "\n";

        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        if (extensions != nullptr && extensionCount > 0) {
            createInfo.enabledExtensionCount = extensionCount;
            createInfo.ppEnabledExtensionNames = extensions;
        }

        createInfo.enabledLayerCount = 0;

		return vkCreateInstance(&createInfo, nullptr, &instance);
    }
};
