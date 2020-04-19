#include "monster.h"
#include <iostream>

// move monster in maze between start point and end point
void Monster::GoMad(){
    bool goBack = false;
    while(running)
    {
        //protect shared data with renderer class
        std::unique_lock<std::mutex> lck(mtx);
        if(!goBack)
        {
            pos_y += speed;
            if(pos_y >= end.y)
                goBack = true;
        }
        else
        {
            pos_y -= speed;
            if(pos_y <= start.y)
                goBack = false;
        }
	lck.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

}

Monster::~Monster(){
    //make sure monsters threads are joined
    monsterThread.join();
    std::cout<<&monsterThread<<" joined, destroying object !!\n";
}

