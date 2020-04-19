#include "pacman.h"
#include <cmath>
#include <iostream>

// try to move if there is no wall
bool Pacman::TryToMove(float x, float y){
    for(auto it=wall.begin(); it!=wall.end(); ++it){
        if(PacmanIntersect(x, width, it->x, 32) && PacmanIntersect(y, height, it->y, 32))
	    return false;
    }
    return true;
}

// function to check if pacman hit an object
bool Pacman::HitObject(float x, float y){
    if(PacmanIntersect(pos_x, width, x, 32) && PacmanIntersect(pos_y, height, y, 32))
        return true;
    else
        return false;
}

void Pacman::UpdatePosition() {
    bool update = false;
    float new_y = pos_y;
    float new_x = pos_x;
  switch (direction) {
    case Direction::kUp:
        new_y -= speed;
      break;

    case Direction::kDown:
        new_y += speed;
      break;

    case Direction::kLeft:
        new_x -= speed;
      break;

    case Direction::kRight:
        new_x += speed;
      break;
    default:
        break;
  }

  // Wrap the Pacman around to the beginning if going off of the screen.
  new_x = fmod(new_x + screen_width/width, screen_width/width);
  new_y = fmod(new_y + screen_height/height, screen_height/height);
  update = TryToMove(new_x, new_y);

  if(update)
  {
      pos_x = new_x;
      pos_y = new_y;
  }
}

// Check if a certain object intersects with pacman at certain cooardinate
bool Pacman::PacmanIntersect(float objectPos1, float objectLen1, float objectPos2, float objectLen2) {
  float objectStart1 = objectPos1 * objectLen1;
  float objectEnd1 = (objectPos1+1) * objectLen1;
  float objectStart2 = objectPos2 * objectLen2;
  float objectEnd2 = (objectPos2+1) * objectLen2;
  if((objectStart1>=objectStart2 && objectStart1<=objectEnd2) || (objectEnd1>=objectStart2 && objectEnd1<=objectEnd2)
        || (objectStart2>=objectStart1 && objectEnd2<=objectEnd1))
      return true;
  else
      return false;
}



