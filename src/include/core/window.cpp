#include "window.h"

Window::Window() : m_window(nullptr) {};

Window::~Window()
{
   Cleanup();
};

void Window::Init
(
   const char* title, 
   uint32_t width, 
   uint32_t height
)
{
   if (SDL_Init(SDL_INIT_VIDEO) != 0) 
   {
      throw std::runtime_error
         ("Failed to initialize SDL: "
         + std::string(SDL_GetError()));
   };
   
   m_window = SDL_CreateWindow
      (
         title, 
         SDL_WINDOWPOS_UNDEFINED,
         SDL_WINDOWPOS_UNDEFINED,
         width, height, 
         SDL_WINDOW_VULKAN
      );

   if (m_window == nullptr) 
   {
      throw std::runtime_error
      ("Failed to create an SDL window: "
      + std::string(SDL_GetError()));
   };

};

void Window::Cleanup()
{
   if (m_window != nullptr)
   {
      SDL_DestroyWindow(m_window);
      m_window = nullptr;
   }

   SDL_Quit();
};

SDL_Window* Window::GetSDLWindow() const 
{
   return m_window;
};

VkSurfaceKHR Window::CreateSurface(VkInstance instance)
{
   VkSurfaceKHR Surface;
   if (SDL_Vulkan_CreateSurface(m_window, instance, &Surface)
         != SDL_TRUE)
   {
      throw std::runtime_error
         ("Failed to create a Vulkan surface: "
          + std::string(SDL_GetError()));
   }
   return Surface;
}
