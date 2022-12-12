#include "app.h"


App::App() = default;

App::~App()
{
   Cleanup();
};

void App::Init
(  
   const char *title, 
   uint32_t width, 
   uint32_t height
) 
{
   m_instance.Init();
   m_window_.Init(title, width, height);
   m_surface = m_window_.CreateSurface(m_instance.GetVkInstance());
};

void App::Cleanup()
{
   m_instance.Cleanup();
   m_window_.Cleanup();
   SDL_Quit();
}

void App::Run()
{
 // Main application loop
   bool Running = true;
   while (Running)
   {
      // Poll for SDL events
      SDL_Event Event;
      while (SDL_PollEvent(&Event) != 0)
      {
         // Check for the SDL_QUIT event
         if (Event.type == SDL_QUIT)
         {
             // Set the running flag to false and exit the loop
             Running = false;
             break;
         }
      }

        // Update and render the application here...
   }
}
