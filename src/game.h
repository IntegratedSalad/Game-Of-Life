#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "cell.h"
#include "constants.h"




void place_cells_vector(std::vector<Cell>& vec, const int max_cells, int chance);
void place_cells_array(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int max_cells, const int n_cells, int chance);
void fill_array_cells(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int n_cells);
int rand_range(int min_num, int max_num);




#endif // GAME_H_INCLUDED
