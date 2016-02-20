#include <cstdlib>
#include <iostream>
#include <curses.h>
#include <vector>
#include <fstream>
#include <string>

#include "initialize.h"
#include "structure.h"
#include "score.h" 
 

using namespace std;

void placeWall(int);
void placeWall();
void goodBye(int x, int score, int &lives, int &level);
void nextLevel(int level);
void endGame(int score);
void welcome(); 
