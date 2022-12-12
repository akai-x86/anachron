#include "instance.h"
#include <vulkan/vulkan_core.h>
#include <array>
#include <vector>

Instance::Instance() : m_instance(VK_NULL_HANDLE){};

Instance::~Instance()
{
   Cleanup();
}

void Instance::Init() 
{
   // This evil-looking boilerplate
   // handles how Vulkan creates the app
   // Nothing can be done about it


   // First, get the number of available extensions
   uint32_t ExtensionCount;
   vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionCount, nullptr);
   
   // Allocate an array to hold the extension properties
   std::vector<VkExtensionProperties> Extensions(ExtensionCount);
   
   // Now get the actual extension properties
   vkEnumerateInstanceExtensionProperties(nullptr, &ExtensionCount, Extensions.data());
   
   // Check if the VK_KHR_xlib_surface extension is available
   bool HasSurfaceExtension = false;
   for (const auto& Extension : Extensions)
   {
       if (strcmp(Extension.extensionName, VK_KHR_SURFACE_EXTENSION_NAME) == 0)
       {
           HasSurfaceExtension = true;
           break;
       }
   }
   
   if (!HasSurfaceExtension)
   {
       throw std::runtime_error("VK_KHR_surface extension is not available");
   }

   std::array<const char*, 3> EnabledExtensionNames = {
      "VK_KHR_get_physical_device_properties2", 
      "VK_KHR_surface",
      "VK_KHR_xlib_surface"
   };

   VkApplicationInfo AppInfo          = {};
   AppInfo.sType                      = VK_STRUCTURE_TYPE_APPLICATION_INFO;
   AppInfo.pNext                      = nullptr;
   AppInfo.pApplicationName           = "Achron Game";
   AppInfo.applicationVersion         = VK_MAKE_VERSION(1, 0, 0);
   AppInfo.pEngineName                = "Vulkan Engine";
   AppInfo.engineVersion              = VK_MAKE_VERSION(1, 0, 0);
   AppInfo.apiVersion                 = VK_API_VERSION_1_0;

   VkInstanceCreateInfo CreateInfo    = {};
   CreateInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
   CreateInfo.pApplicationInfo        = &AppInfo;
   CreateInfo.enabledExtensionCount   = EnabledExtensionNames.size();
   CreateInfo.ppEnabledExtensionNames = EnabledExtensionNames.data();

   VkResult Result = vkCreateInstance(
         &CreateInfo,
         nullptr,
         &m_instance
         );

   if (Result != VK_SUCCESS)
   {
      throw std::runtime_error
      ("Failed to create a Vulkan instance");
   }
};

void Instance::Cleanup()
{
   if (m_instance != VK_NULL_HANDLE)
   {
      vkDestroyInstance(m_instance, nullptr);
   }
};

VkInstance Instance::GetVkInstance() const
{
   return m_instance;
};
