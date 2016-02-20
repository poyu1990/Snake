#include "snake.h"


int kbinput()
{
   int data = getch();
   static int prev = KEY_RIGHT;
   switch(data)
   {
      case    KEY_UP:
      case  KEY_DOWN:
      case  KEY_LEFT:
      case KEY_RIGHT:
      case        27: prev = data;
                      return data;
      default:        return prev;
   }
}
             
             
void moveSnake(vector<location> &snake, int &length, int direction, int &kill, int &level, int &score1, int &live)
{
     location newLocation;
     switch(direction)
     {
          case KEY_UP:   newLocation.x = snake[snake.size()-1].x;
                         newLocation.y = snake[snake.size()-1].y-1;
                         placeSnake(snake, length, newLocation, kill, level, score1, live, direction);
                         break; 
                           
        case KEY_DOWN:   newLocation.x = snake[snake.size()-1].x;
                         newLocation.y = snake[snake.size()-1].y+1;
                         placeSnake(snake, length, newLocation, kill, level, score1, live, direction);
                         break; 
             
        case KEY_LEFT:   newLocation.x = snake[snake.size()-1].x-1;
                         newLocation.y = snake[snake.size()-1].y;
                         placeSnake(snake, length, newLocation, kill, level, score1, live, direction);
                         break; 
             
       case KEY_RIGHT:   newLocation.x = snake[snake.size()-1].x+1;
                         newLocation.y = snake[snake.size()-1].y;
                         placeSnake(snake, length, newLocation, kill, level, score1, live, direction);
                         break;
                          
              case 27:   myExit();
     }
     
     refresh();
              
}

void placeSnake(vector<location> &snake, int &length, location newLocation, int &kill, int &level, int &score1, int &lives, int direction)
{  
     int snakeHead = mvinch(newLocation.y, newLocation.x);
     if((snakeHead & A_COLOR) == COLOR_PAIR(COLOR1))
     {
          goodBye(1, score1, lives, level);
          if(lives>=0)
          {
            printMice(snake, level);
            cleanSnake(snake);
            snake.clear();
            kill = 0;
            newLocation.x = 40;
            newLocation.y = 12;
            snake.push_back(newLocation);
            length = 5; 
          }
          if (lives < 0) 
            goodBye(1, score1, lives, level); 
     }
     if((snakeHead & A_COLOR) == COLOR_PAIR(COLOR3))
     {
          goodBye(1, score1, lives, level);
          if(lives>=0)
          {
            printMice(snake, level);
            cleanSnake(snake);
            snake.clear();
            kill = 0;
            newLocation.x = 40;
            newLocation.y = 12;
            snake.push_back(newLocation);
            length = 5; 
          }
          if (lives < 0) 
          goodBye(1, score1, lives, level);
     }  
     if ((snakeHead & A_CHARTEXT) == 'M')
     {
        score1 += 10;
        printMice(snake,level);
        growSnake(snake, length, 1);
        kill++; 
     }
     if((snakeHead & A_CHARTEXT) == 'T' )
     { 
         if( newLocation.x == 10 )
             newLocation.x += 60;
         else if (newLocation.x == 70) 
            newLocation.x -= 60; 
     
         switch(direction)
         {
            case KEY_UP:     newLocation.y-=1;
                             break; 
                               
            case KEY_DOWN:   newLocation.y+=1;
                             break; 
                 
            case KEY_LEFT:   newLocation.x-=1;                                
                             break; 
                 
            case KEY_RIGHT:  newLocation.x+=1;
                             break;
            default:         break; 
         }
     } 
     
     
     
     
     snake.push_back(newLocation); 
     attron (COLOR_PAIR( COLOR1 ));
     for(int i=0 ; i<snake.size(); i++)
         mvprintw(snake[i].y, snake[i].x,"%c", ' ');
     attroff (COLOR_PAIR( COLOR3 ));
     attron(COLOR_PAIR(COLOR2));
     if(snake.size() >= length)
     {
        mvprintw(snake[0].y, snake[0].x,"%c", ' ');
        snake.erase(snake.begin());
     }
     attroff(COLOR_PAIR(COLOR2));
     attroff(COLOR_PAIR(COLOR1));  
     placeWall();
     refresh();
     mvprintw(0,60,"Score: %08d",score1);
     mvprintw(0,0,"Level: %02d  Live: %d", level, lives);
}

void growSnake(vector<location> &snake, int &length, int amount)
{
   length += amount;    
}

void cleanSnake(vector<location> &snake)
{
     attron(COLOR_PAIR(COLOR2)); 
     for (int i = 0; i < snake.size(); i++)
         mvprintw(snake[i].y, snake[i].x, "%c" , ' '); 
     attroff(COLOR_PAIR(COLOR2)); 
} 
