#ifndef PACMAN_H
#define PACMAN_H

#include "SDL.h"

class Pacman {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight, kStop };

  Pacman(int screen_width, int screen_height)
      : screen_width(screen_width),
        screen_height(screen_height),
        pos_x(0),
        pos_y(0) {}
  bool PacmanCell(int x, int y);
  void UpdatePosition();

  Direction direction = Direction::kUp;
  float speed{0.1f};
  bool alive{true};
  float pos_x;
  float pos_y;
  const float width = 20;
  const float height = 20; 

 private:

  int screen_width;
  int screen_height;
};

#endif

