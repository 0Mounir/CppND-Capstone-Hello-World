#ifndef MONSTER_H
#define MONSTER_H

#include "SDL.h"
#include <thread>
#include <atomic>
#include <mutex>

class Monster {
 public:

  Monster(SDL_Point start, SDL_Point end, std::atomic<bool> &running)
      : start(start),
        end(end),
        running(running) {pos_x = start.x; pos_y=start.y;}
  ~Monster();
  void GoMad();
  void Release(){monsterThread = std::thread(&Monster::GoMad, this);};
  float pos_x;
  float pos_y;
  std::mutex mtx;

 private:
  SDL_Point start;
  SDL_Point end;
  float speed{0.1f};
  std::thread monsterThread;
  std::atomic<bool> &running;
};

#endif

