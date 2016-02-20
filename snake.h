#include <cstdlib>
#include <curses.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "initialize.h"
#include "structure.h"
#include "misc.h"
#include "mouse.h"
#include "score.h" 

using namespace std;
#ifndef SNAKE
#define SNAKE

int kbinput();
void moveSnake(vector<location> &snake, int &length, int direction, int &kill, int &level, int &score1, int &live);
void growSnake(vector<location> &snake, int &length, int amount = 1);
void placeSnake(vector<location> &snake, int &length, location newLocation, int &kill, int &level, int &score1, int &lives, int direction);
void cleanSnake(vector<location> &snake); 

#endif
