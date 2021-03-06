#ifndef RENDERER_H
#define RENDERER_H

#include "pacman.h"
#include "SDL.h"
#include "monster.h"
#include <vector>
#include <set>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Pacman const pacman, std::vector<SDL_Point> const &food,
          std::vector<SDL_Point> const &wall, std::vector<std::unique_ptr<Monster>> const &monsters);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif




