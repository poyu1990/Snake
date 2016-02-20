#include <cstdlib>
#include <iostream>
#include <curses.h>
#include <fstream>
#include <string>
#include <vector>

#include "initialize.h"

using namespace std;

#ifndef SCORE
#define SCORE 

class Score
{
  public:
    Score();
    ~Score();
    Score(string otherName, int otherScore);
      
    void print(int y, int x);
        
    Score& operator=(const Score &other);
    
    int findScore() {return score;}
             
    friend
      ostream& operator<<(ostream &out, Score &score);    
    friend
      istream& operator>>(istream &in, Score &score);
     
  private:
    string name;
    int score;       
};

void writeScore(string name, int score);
void readScore(vector<Score> &score);
void printScore();

#endif 
