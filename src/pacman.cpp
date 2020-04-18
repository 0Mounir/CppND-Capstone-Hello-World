#include "snake.h"
#include <cmath>
#include <iostream>

void Pacman::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      pos_y -= speed;
      break;

    case Direction::kDown:
        pos_y += speed;
      break;

    case Direction::kLeft:
      pos_x -= speed;
      break;

    case Direction::kRight:
        pos_x += speed;
      break;
  }

  // Wrap the Pacman around to the beginning if going off of the screen.
  pos_x = fmod(pos_x + grid_width, grid_width);
  pos_y = fmod(pos_y + grid_height, grid_height);
}

// Inefficient method to check if cell is occupied by pacman.
bool Pacman::PacmanCell(int x, int y) {
  if (x == static_cast<int>(pos_x) && y == static_cast<int>(pos_y)) {
    return true;
  }
  return false;
}
