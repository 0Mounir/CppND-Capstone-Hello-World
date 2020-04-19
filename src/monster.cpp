#include "monster.h"
#include <iostream>

// move monster in maze from start point to end point
void Monster::GoMad(){
    while(running)
    {
        std::cout<<"Thread  "<<&monsterThread<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

}

Monster::~Monster(){
    //make sure monsters threads are joined
    monsterThread.join();
    std::cout<<&monsterThread<<" joined, destroying object !!\n";
}


