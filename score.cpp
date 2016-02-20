#include "score.h" 

Score::Score()
{
     name = ""; 
     score = 0; 
}

Score::~Score()
{
                
}

Score::Score(string otherName, int otherScore)
{
      name = otherName;
      score = otherScore;
}

void Score::print(int y, int x)
{
     mvprintw(y,x,name.c_str());
     mvprintw(y,50,"%d", score);
}

Score& Score::operator=(const Score &other)
{
       name = other.name;
       score = other.score;
}

ostream& operator<<(ostream &out, Score &score)
{
    out<<' '<<score.name<<' '<<score.score;
    return out;

}

istream& operator>>(istream &in, Score &score)
{
    in>>score.name>>score.score;
    return in;
}

void writeScore(string name, int score1)
{
     vector<Score> score;
     readScore(score);
     score.push_back(Score(name,score1));
     
     if(score.size() > 10)
     { 
         int small = 0;
         for(int i = 0; i<score.size(); i++)
         {
            if (score[small].findScore()> score[i].findScore())
               small = i;
             score.erase(score.begin()+small);
         }
     } 
     ofstream fout; 
     
     fout.open("score.txt"); 
     
     for (int i = 0; i < score.size();i++)
         fout << score[i];
         
     fout.close();
}

void readScore(vector<Score> &score)
{
     Score temp;
     
     ifstream fin;
     fin.open("score.txt"); 
     while(!fin.eof())
     {
         fin>>temp;            
         score.push_back(temp);
     }
     fin.close();
      
     for (int i = 0; i < score.size()-1; i++)
         for (int j = i+1; j< score.size();  j++)
             if (score[i].findScore() < score[j].findScore())
                {
                    temp = score[i];
                    score[i] = score[j];
                    score[j] = temp;
                } 
}

void printScore()
{
     vector<Score> bleh;
     
     readScore(bleh);
     for (int i = 0; i < bleh.size(); i++)
     {    
         mvprintw(12+i,30,"%d", i+1); 
         bleh[i].print(12+i, 35);
     } 
}

