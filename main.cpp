#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "initialize.h"
#include "mouse.h"
#include "snake.h"
#include "misc.h"
#include "score.h" 
#include "structure.h" 

using namespace std;

int main(int argc, char *argv[])
{
    int level = 1, lives = 3;
    vector<location> snake;
    int length = 6, move1 = 0;
    int score1 = 0;
    int kill = 0;
    location start;
    start.x = 40;
    start.y = 12; 
    initialize();
    welcome(); 
    while(true)
    { 
        while(level<=20)
        {
            timeout(1000);
            if (level == 5)
               timeout(250); 
            if (level == 10)
            {
               timeout(200);
               length = 6;
            }
            if (level == 15)
               timeout(200);      
            move(0,0);
            clrtobot(); 
            cleanSnake(snake);
            snake.clear();
            if (lives > 0)
            {
                nextLevel(level); 
                kill = 0;
                placeWall(level);
                placeSnake(snake, length, start, kill, level, score1, lives, 0);
                printMice(snake, level);
                refresh();
                while(kill<level+4)
                   moveSnake(snake, length, (move1=kbinput()), kill, level, score1, lives);
                level++;
            } 
        } 
        goodBye(2, score1, lives, level); 
    } 
    return EXIT_SUCCESS;
}

      //if all mice are gone, move to next level
      //if at level 5, put a wall
      //if at level 10, put two walls
      //if at level 15, make a teleporter
      //if at level 20, end game.
      //You can die 3 times. If you die, you start from level 1
      //update score
      //update time
