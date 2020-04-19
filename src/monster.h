#ifndef MONSTER_H
#define MONSTER_H

#include "SDL.h"
#include <thread>
#include <atomic>

class Monster {
 public:

  Monster(SDL_Point start, SDL_Point end, std::atomic<bool> &running)
      : start(start),
        end(end),
        running(running) {monsterThread = std::thread(&Monster::GoMad, this);}
  ~Monster();
  void GoMad();

 private:
  SDL_Point start;
  SDL_Point end;
  std::thread monsterThread;
  std::atomic<bool> &running;
};

#endif

