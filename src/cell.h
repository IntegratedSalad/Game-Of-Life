#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include <vector>
#include <tuple>
#include "constants.h"

struct Cell
{
    int x;
    int y;
    bool is_alive = false;
    bool will_die = false;
    bool will_revive = false;
};


int Cell_check_surroundings_vector(Cell cell, std::vector<Cell> cells_vec, int current_cell_index);
unsigned int Cell_check_surroundings_array(Cell c_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], std::tuple<int, int> current_cell_index);



#endif // CELL_H_INCLUDED
