#pragma once
#include "Core.h"
#include <optional>

struct QueueFamilyIndices {
    std::optional<uint32_t> GraphicsFamily;
};

class QueueFamilies {
public:
    static QueueFamilyIndices FindQueueFamilies(const VkPhysicalDevice& device) {
        QueueFamilyIndices indices;

        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

        int indexStepper = 0;
        for (const auto& queueFamily : queueFamilies) {
            if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                indices.GraphicsFamily = indexStepper;
            }

            ++indexStepper;
        }

        return indices;
    }
};
