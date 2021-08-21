#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "cell.h"
#include "constants.h"

#if __win32
#include <SDL.h>
#elif __unix__ || __APPLE__
//#include <SDL2/SDL.h>
#include <SDL.h> // on m1 uncomment this
#endif



struct World
{
    
};


void place_cells_vector(std::vector<Cell>& vec, const int max_cells, int chance);
void place_cells_array(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int max_cells, const int n_cells, int chance);
void fill_array_cells(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int n_cells);
int rand_range(int min_num, int max_num);
Uint32 tick_function(Uint32 interval, void* param);




#endif // GAME_H_INCLUDED
