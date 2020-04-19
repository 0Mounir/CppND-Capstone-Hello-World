#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "pacman.h"

constexpr int MAZE_LENGTH = 20;

class Game {
 public:
  Game(std::size_t screen_width, std::size_t screen_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  Pacman pacman;
  std::vector<SDL_Point> wall;
  std::vector<SDL_Point> food;
  std::vector<std::unique_ptr<Monster>> monsters;


  std::atomic<bool> running;

  const char maze[MAZE_LENGTH][MAZE_LENGTH] = {
  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
  {'#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
  {' ',' ',' ',' ',' ','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#'},
  {' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' '},
  {'#',' ',' ','#','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' '},
  {'#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#','#'},
  {'#',' ',' ','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#'},
  {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#'},
  {'#','#','#','#','#','#','#','#','#','#','#',' ','#','#',' ',' ','#',' ',' ','#'},
  {'#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#'},
  {'#','#','#','#',' ','#','#','#',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#'},
  {'#',' ',' ','#',' ',' ','#','#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#'},
  {'#','#',' ','#',' ',' ',' ','#',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ','#'},
  {'#','#',' ','#','#','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
  {'#','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#','#',' ','#',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
  {'#','#','#','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#'},
  };

  int score{0};
  void Update();
};

#endif




