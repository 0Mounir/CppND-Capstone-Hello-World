#ifndef PACMAN_H
#define PACMAN_H

#include "SDL.h"
#include <vector>

class Pacman {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight, kStop };

  Pacman(int screen_width, int screen_height, std::vector<SDL_Point> &wall)
      : screen_width(screen_width),
        screen_height(screen_height),
        wall(wall),
        pos_x(0),
        pos_y(31) {}
  void UpdatePosition();

  Direction direction = Direction::kUp;
  float speed{0.1f};
  bool alive{true};
  float pos_x;
  float pos_y;
  const float width = 20;
  const float height = 20;
  std::vector<SDL_Point> const &wall;

 private:
  bool TryToMove(float x, float y);
  bool PacmanIntersect(float objectPos1, float objectLen1, float objectPos2, float objectLen2);

  int screen_width;
  int screen_height;
};

#endif


