#pragma once
#include "window.h"
#include "instance.h"

class App
{
public:

   App();
   ~App();

   void 
      Init
      (
         const char* title, 
         uint32_t width, 
         uint32_t height
      ),
      Cleanup(),
      Run();

   [[nodiscard]] SDL_Window*  
      GetSDLWindow () const;
   
   [[nodiscard]] VkInstance   
      GetVkInstance() const;
   
   [[nodiscard]] VkSurfaceKHR 
      GetVkSurface () const;
   
   private:
      Window       m_window_;
      Instance     m_instance;
      VkSurfaceKHR m_surface;
};