#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "cell.h"

void place_cells_vector(std::vector<Cell>& vec, const int max_cells, int chance);
void place_cells_array(Cell c_arr[60][60], const int max_cells, const int n_cells, int chance);
void fill_array_cells(Cell c_arr[60][60], const int n_cells);
int rand_range(int min_num, int max_num);
const int CELL_NUM_MAP_X = 60;
const int CELL_NUM_MAP_Y = 60;
const int CHANCE_OF_SPAWN = 50;

#endif // GAME_H_INCLUDED
