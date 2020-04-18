#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Pacman Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Pacman const pacman, std::vector<SDL_Point> const &food, std::vector<SDL_Point> const &wall) {
    SDL_Rect wallBlock;
    SDL_Rect foodBlock;
    SDL_Rect pacmanBlock;
    wallBlock.w = grid_width;
    wallBlock.h = grid_height;
    pacmanBlock.w = pacman.width;
    pacmanBlock.h = pacman.height;
    foodBlock.w = screen_width / (grid_width*2);
    foodBlock.h = screen_height / (grid_height*2);

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);

    //render maze walls
    SDL_SetRenderDrawColor(sdl_renderer, 0xDC, 0x50, 0x00, 0xFF);
    for(auto it=wall.begin(); it!=wall.end(); ++it)
    {
        wallBlock.x = (*it).x * grid_width;
        wallBlock.y = (*it).y * grid_height;
        SDL_RenderFillRect(sdl_renderer, &wallBlock);
    }

    //render food
    SDL_SetRenderDrawColor(sdl_renderer, 0x50, 0x50, 0xFF, 0xFF);
    for(auto it=food.begin(); it!=food.end(); ++it)
    {
        foodBlock.x = (*it).x * grid_width + grid_width/4;
        foodBlock.y = (*it).y * grid_height + grid_height/4;
        SDL_RenderFillRect(sdl_renderer, &foodBlock);
    }

    //render pacman
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0x00, 0xFF);
    pacmanBlock.x = pacman.pos_x * pacmanBlock.w;
    pacmanBlock.y = pacman.pos_y * pacmanBlock.h;

    SDL_RenderFillRect(sdl_renderer, &pacmanBlock);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}



