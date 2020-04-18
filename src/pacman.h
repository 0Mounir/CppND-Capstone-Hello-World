#ifndef PACMAN_H
#define PACMAN_H

#include "SDL.h"

class Pacman {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  bool PacmanCell(int x, int y);

  Direction direction = Direction::kUp;
  float speed{0.1f};
  bool alive{true};
  float pos_x;
  float pos_y;

 private:
  void UpdatePosition();

  int grid_width;
  int grid_height;
};

#endif
