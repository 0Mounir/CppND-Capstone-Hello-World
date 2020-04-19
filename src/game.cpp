#include "game.h"
#include <iostream>
#include "SDL.h"
#include "monster.h"

Game::Game(std::size_t screen_width, std::size_t screen_height) : running(true), pacman(screen_width, screen_height, wall)
{
    SDL_Point point;
    point.y = 0;
    for(int i=0; i<MAZE_LENGTH; ++i)
    {
        point.x=0;
        for(int j=0; j<MAZE_LENGTH; ++j)
        {
            if('#' == maze[i][j])
                wall.push_back(point);
            else
                food.push_back(point);
            ++point.x;
        }
        ++point.y;
    }

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  //intialize monsters
  SDL_Point start;
  SDL_Point end;
  start.x = 18;
  start.y = 7;
  end.x = 18;
  end.y = 17;
  monsters.emplace_back(std::make_unique<Monster>(start, end, running));

  start.x = 2;
  start. y = 2;
  end.x = 2;
  end.y = 7;
  monsters.emplace_back(std::make_unique<Monster>(start, end, running));

  //release monsters
  for(auto it = monsters.begin(); it!=monsters.end(); ++it){
      it->get()->Release();
}

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, pacman);
    Update();
    renderer.Render(pacman, food, wall, monsters);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
    if (!pacman.alive) return;

    // if you eat all food end game
    if (food.empty())
    {
	std::cout<<"Wow you won, congratulations !!\n";
	running = false;
    }

    pacman.UpdatePosition();

    // if you hit any monster end game
    for(auto it=monsters.begin(); it!=monsters.end(); ++it){
        if(pacman.HitObject(it->get()->pos_x, it->get()->pos_y))
        {
	    std::cout<<"Monster caught pacman, pray for him :(\n";
            pacman.alive=false;
	    running = false;
            break;
        }
    }
    // if you hit any food eat it
    for(auto it=food.begin(); it!=food.end(); ++it)
    {
        if(pacman.HitObject(it->x, it->y))
        {
            ++score;
            food.erase(it);
            break;
        }
    }

}

int Game::GetScore() const { return score; }




