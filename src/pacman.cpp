#include "pacman.h"
#include <cmath>
#include <iostream>

bool Pacman::TryToMove(float x, float y){
    for(auto it=wall.begin(); it!=wall.end(); ++it){
        if(PacmanIntersect(x, width, it->x, 32) && PacmanIntersect(y, height, it->y, 32))
	    return false;
    }
    return true;
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

  update = TryToMove(new_x, new_y);
  if(update)
  {
      // Wrap the Pacman around to the beginning if going off of the screen.
  	  pos_x = fmod(new_x + screen_width/width, screen_width/width);
  	  pos_y = fmod(new_y + screen_height/height, screen_height/height);
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

