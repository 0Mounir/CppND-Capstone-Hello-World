#include <iostream>
#include "SDL.h"

int main() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
    std::cout << "Hello World!" << "\n";
    return 0;
}
