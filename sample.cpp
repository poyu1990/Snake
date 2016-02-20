#include <cstdlib>`
#include <iostream>
#include <cstring>
#include <time.h>


#include "initialize.h"

void sleep(unsigned int mseconds);

using namespace std;

int main(int argc, char *argv[])
{
    char *str = "Hello World!!!";
    chtype data;
    initialize();
    attron(A_REVERSE);
    mvprintw(10,10,"%s",str);
    attroff(A_REVERSE);
    int len = strlen(str), begin = 1, end = 79;
    refresh();
       for(int i = begin; i<end; i++)
       {
           move(11,1);
           clrtoeol();
           attron(A_REVERSE);
           mvprintw(11,i,"%c",'*');
           attroff(A_REVERSE);
           refresh();
           data = mvinch(10,i);
           bool isReverse = data & A_REVERSE;
           move(1,1);
           clrtoeol();
           /*
           if(data & A_CHARTEXT)
             mvprintw(1,1,"A character is at position %i",i);
           else
             mvprintw(1,1,"A character is not at position %i",i);
           */
           move(12,i);
           if(isReverse)
           {
              attroff(A_REVERSE);
              mvprintw(12, i, "%c",data);
              attron(A_REVERSE);
           }
           else
           {
              attron(A_REVERSE);
              mvprintw(12, i, "%c",data);
              attroff(A_REVERSE);
           }
           sleep(100);
           refresh();
       } 
    system("PAUSE");
    myExit();
    return EXIT_SUCCESS;
}

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/*

Extra Credit is to fix this!

void sleep(int amount, WINDOW *mainwnd)
{
  time_t now = time(NULL);
  tm *now_tm;
  now_tm = localtime(&now);
  int now_sec = now_tm->tm_sec;
  int then_sec = (now_sec + amount)%60;
  while(then_sec != now_sec)
  {
     now_tm = localtime(&now);
     now_sec = now_tm->tm_sec;
     char nowsec[20];
     itoa(now_sec,nowsec,10);
     mvwprintw(mainwnd, 2,4, nowsec);
   }
}
*/
