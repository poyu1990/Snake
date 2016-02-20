#include <cstdlib>
#include <curses.h>
#include <vector>

#include "structure.h"
#include "misc.h"
#include "initialize.h"

#ifndef MOUSE
#define MOUSE

using namespace std;

bool collision(int x, int y, vector<location> mouse, int level);
void printMice(vector<location> &snake, int level);

#endif
