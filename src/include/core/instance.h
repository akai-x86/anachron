#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL_vulkan.h>
#include <stdexcept>

class Instance
{
   public:
       Instance();
      ~Instance();

      void Init(),
         Cleanup();

      [[nodiscard]] VkInstance GetVkInstance() const;

   private:
      VkInstance m_instance;

};
