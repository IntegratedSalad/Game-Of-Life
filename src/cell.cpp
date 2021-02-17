#include "cell.h"

int Cell_check_surroundings_vector(Cell cell, std::vector<Cell> cells_vec, int current_cell_index)
{
    int neighbours = 0;

    for (std::size_t i = 0; i < cells_vec.size(); ++i)
    {
        if (i != current_cell_index)
        {
            Cell cell_to_check = cells_vec[i];
            //    cell.x - 10 == cell_to_check            //if ((cell.x + 10 == cell_to_check.x) && cell.y ||
        }
    }

    return neighbours;
}

unsigned int Cell_check_surroundings_array(Cell c_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], std::tuple<int, int> current_cell_index)
{
    unsigned int neighbours = 0;
    int x, y;

    std::tie(x, y) = current_cell_index;

    if (x < BOARD_SIZE_SQUARE - 1)
    {
        if (c_array[x+1][y].is_alive)
            neighbours++;
    }
    if (x > 0)
    {
        if (c_array[x-1][y].is_alive)
            neighbours++;
    }
    if (y < BOARD_SIZE_SQUARE - 1)
    {
        if (c_array[x][y+1].is_alive)
            neighbours++;
    }
    if (y > 0)
    {
        if (c_array[x][y-1].is_alive)
            neighbours++;
    }
    if (x < BOARD_SIZE_SQUARE - 1 && y < BOARD_SIZE_SQUARE - 1)
    {
        if (c_array[x+1][y+1].is_alive)
            neighbours++;
    }
    if (x > 0 && y > 0)
    {
        if (c_array[x-1][y-1].is_alive)
            neighbours++;
    }
    if (x < BOARD_SIZE_SQUARE - 1 && y > 0)
    {
        if (c_array[x+1][y-1].is_alive)
            neighbours++;
    }
    if (x > 0 && y < BOARD_SIZE_SQUARE - 1)
    {
        if (c_array[x-1][y+1].is_alive)
            neighbours++;
    }

    return neighbours;
}
