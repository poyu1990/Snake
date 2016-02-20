#include "mouse.h"

bool collision(int y, int x, vector<location> snake, int level)
{
     int px, py;
     px = x;
     py = y;
     bool ans = false;
     for(int i=0; (i<snake.size() && !ans); i++)
     {
        ans = (x == snake[i].x) && (y == snake[i].y);   
        if ((x == 40) && (y == 12))
        ans = true;
     }
     if (x == 0 || x == 79)
        ans = true;
     if (y == 1 || y == 24)
        ans = true;
     if ((level >= 5 && level < 10) && x == 25 && (y >= 7 && y < 18))
        ans = true;
     if (level >= 10 && x == 25 && x == 55 && (y >= 7 && y < 18))
        ans = true;
     return ans;
}

void printMice(vector<location> &snake, int level)
{
     int row = 0, col = 0;
     do
      {
           row=rand()%23+1;
           col=rand()%79+1;
      }while(collision(row, col, snake, level));
     mvprintw(row, col , "M");
     refresh();
}














