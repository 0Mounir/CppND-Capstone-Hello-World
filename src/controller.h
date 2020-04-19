#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "pacman.h"
#include <atomic>

class Controller {
 public:
  void HandleInput(std::atomic<bool> &running, Pacman &pacman) const;

};

#endif
