#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <stdexcept>

class Window
{
   public:
       Window();
      ~Window();

      void Init(const char* title, uint32_t width, uint32_t height),
           Cleanup();

      SDL_Window* GetSDLWindow() const;
      VkSurfaceKHR CreateSurface(VkInstance instance);


   private:
      SDL_Window* m_window;
};

