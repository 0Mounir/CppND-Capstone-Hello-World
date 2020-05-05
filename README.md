# CPPND: Capstone Option 2: Pacman game

This repo is for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This is a simple Pacman game implemented in C++.

In this game you (Pacman, the yellow block) shall only use keyboard arrows (Up, Down, Left and Rgiht) and your mission is to try to eat all food (purple blocks) without getting caught by any of game monsters (red blocks).

The game will end if Pacman gets caught by a monster of it Pacman eats all food.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Pacman`.

## Code Files Structure
* controller.cpp - controller class soruce code.
* controller.h - controller class header file.
* game.cpp - game class soruce code.
* game.h - game class header file.
* main.cpp - file containing entry point of this application.
* monster.cpp - monster class soruce code.
* monster.h - monster class header file.
* pacman.cpp - pacman class soruce code.
* pacman.h - pacman class header file.
* renderer.cpp - renderer class soruce code.
* renderer.h - renderer class header file.

## Rubric Points Met
## Loops, Functions, I/O
1- The project demonstrates an understanding of C++ functions and control structures. Location: Almost in all code files.
## Object Oriented Programming
2- The project uses Object Oriented Programming techniques. Location: Each cpp and header file encapsulate a certain class for example (monster.cpp and monster.h for monster class)

3- Classes use appropriate access specifiers for class members. Location: Same as above.

4- Class constructors utilize member initialization lists. Location: For example renderer.cpp(line 5).
## Memory Management
5- The project makes use of references in function declarations. Location: for example in void Game::Run in controller.cpp(line 6).

6- The project uses smart pointers instead of raw pointers. Location: game.h(line 24).
## Concurrency
7- The project uses multithreading. Location: monster.h(line 18).

8- A mutex or lock is used in the project. Location: monster.cpp(line 10), renderer.cpp(line 88).
