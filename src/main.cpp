#include <iostream>
#include "include/core/app.h"


const int 
   WindowWidth = 640, 
   WindowHeight = 360;

int main() 
{
   App App; 
   App.Init(
      "My Game", 
      WindowWidth,
      WindowHeight
      );
   App.Run();
   App.Cleanup();
}