#include "misc.h"




void placeWall(int level)
{
     attron( COLOR_PAIR(COLOR3));
     for (int i = 0; i<81; i++)
     {
         mvprintw(1, i, "%c", ' ');
         mvprintw(24, i, "%c", ' ');
     }
     for(int j = 1; j<24; j++)
     {
         mvprintw(j, 0, "%c", ' ');
         mvprintw(j, 79, "%c", ' ');
     }
     if (level>=5)
        for (int k = 7; k<18;k++)
          mvprintw(k, 25, "%c",' ');
     if (level >=10)
        for (int l = 7; l<18;l++)
            mvprintw(l,55,"%c",' ');
        
     if (level >= 15)
     {
        attron(COLOR_PAIR(2));
        mvprintw(12,10,"T");
        mvprintw(12,70,"T");
        attroff(COLOR_PAIR(2));
     }
     attroff(COLOR_PAIR(COLOR3));
     refresh();
     
     
}

void placeWall()
{
     attron( COLOR_PAIR(COLOR3));
     for (int i = 0; i<81; i++)
     {
         mvprintw(1, i, "%c", ' ');
         mvprintw(24, i, "%c", ' ');
     }
     for(int j = 1; j<24; j++)
     {
         mvprintw(j, 0, "%c", ' ');
         mvprintw(j, 79, "%c", ' ');
     }
     attroff(COLOR_PAIR(COLOR3));
     refresh();
}

void score(int x)
{
     move (0,0);
     clrtoeol();
     mvprintw(0,0,"Score: %08d", x);
}

void goodBye(int x, int score, int &lives, int &level)
{
     attroff (COLOR_PAIR(COLOR1));
     attroff (COLOR_PAIR(COLOR3));
     move(0,0);
     clrtoeol();
     clrtobot();
     if(lives>0 && level < 21)
     {
       --lives;
       if (lives > 0)
       { 
       level = 1;
       nextLevel(level);
       } 
     }
     if(lives <= 0)
     { 
       if (x == 1)//run into self or wall
         {
           mvprintw(12, 34, "Game Over");
           mvprintw(14, 31, "Score: %08d", score);
           mvprintw(20, 29, "press enter to exit");
           endGame(score);
           myExit();
         }
     } 
       if (x == 2) // game cleared
          {
           mvprintw(12, 34, "Congradulattion you have beaten the game"); 
           endGame(score);
           myExit();  
          } 
          
}

void nextLevel(int level)
{
     attroff (COLOR_PAIR(COLOR1));
     attroff (COLOR_PAIR(COLOR3));
     move(0,0);
     clrtoeol();
     clrtobot();
     mvprintw(12, 30, "Welcome to level %d", level);
     mvprintw(20, 29, "press enter to continue");
     refresh();
     fflush(stdin);
     while(true)
       if(getch() == '\n')
         break;
     move(0,0);
     clrtoeol();
     clrtobot(); 
     refresh(); 
}

void endGame(int score)
{
     string name; 
     timeout(-1); 
     attroff (COLOR_PAIR(COLOR1));
     attroff (COLOR_PAIR(COLOR3));
     move(0,0);
     clrtoeol();
     clrtobot();
     refresh(); 
     mvprintw(20, 15, "Please enter in your name : ") ;
     
     char input = 0;
     
     while (true)
     { 
           input = getch();
           
            if (input == 27)//escape 
               myExit();
            else if (input == 10 && name.size()) // enter 
            {
                 writeScore(name, score);
                 return;
            } 
            else if (input == 8) // backspace 
             {    
                 if (name.size())
                    name.erase(name.size()-1);
             } 
            else if (input != ' ' && isalpha(input) || isdigit(input))
                 name += input; 
           
            mvprintw(20,44, "                                                                          "); 
            mvprintw(20, 44, name.c_str());
            refresh(); 
     }
} 
void welcome()
{ 
    char* title[5] = {
        "ssssssss    nn          nn          aa           kk      kk    eeeeeee",
        "ss          nn  n       nn        aa   aa        kk  kk        ee",
        "ssssssss    nn     n    nn       aaaaaaaaa       kkkk          eeee",
        "      ss    nn       n  nn      aa       aa      kk   kk       ee",
        "ssssssss    nn          nn    aa           aa    kk      kk    eeeeeee",
        };
    move(0,0);
    clrtoeol(); 
    clrtobot();
        
    for(int a=0;a<5;a++)
       mvprintw(2+a,5,title[a]);
    
    printScore();
    mvprintw(23,28,"Press Enter start");
    
    while(true)
         if (getch() == '\n')
            break;  



     
} 
