#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include <vector>
#include <tuple>

struct Cell
{
    int x;
    int y;
    bool is_alive = false;
    bool will_die = false;
    bool will_revive = false;
};

int Cell_check_surroundings_vector(Cell cell, std::vector<Cell> cells_vec, int current_cell_index);
int Cell_check_surroundings_array(Cell c_array[60][60], std::tuple<int, int> current_cell_index);

const int MAX_CELLS_ON_SCREEN = 30;

#endif // CELL_H_INCLUDED
