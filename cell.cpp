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



             //   )
        }
    }

    return neighbours;
}

int Cell_check_surroundings_array(Cell c_array[60][60], std::tuple<int, int> current_cell_index)
{
    unsigned int neighbours;
    int x, y;

    std::tie(x, y) = current_cell_index;

    if (x < 59)
    {
        if (c_array[x+1][y].is_alive)
            neighbours++;
    }
    if (x > 0)
    {
        if (c_array[x-1][y].is_alive)
            neighbours++;
    }
    if (y < 59)
    {
        if (c_array[x][y+1].is_alive)
            neighbours++;
    }
    if (y > 0)
    {
        if (c_array[x][y-1].is_alive)
            neighbours++;
    }
    if (x < 59 && y < 59)
    {
        if (c_array[x+1][y+1].is_alive)
            neighbours++;
    }
    if (x > 0 && y > 0)
    {
        if (c_array[x-1][y-1].is_alive)
            neighbours++;
    }
    if (x < 59 && y > 0)
    {
        if (c_array[x+1][y-1].is_alive)
            neighbours++;
    }
    if (x > 0 && y < 59)
    {
        if (c_array[x-1][y+1].is_alive)
            neighbours++;
    }

    //if (c_array[x+1][y].is_alive && x < 59)
    //    neighbours++;
    //if (c_array[x-1][y].is_alive && x > 0)
    //    neighbours++;
    //if (c_array[x][y+1].is_alive && y < 59)
    //    neighbours++;
    //if (c_array[x][y-1].is_alive && y > 0)
    //    neighbours++;
    //if (c_array[x+1][y+1].is_alive && (x < 59 && y > 0))
    //    neighbours++;
    //if (c_array[x-1][y-1].is_alive && (x > 0 && y < 59))
    //    neighbours++;
    //if (c_array[x+1][y-1].is_alive && (x < 59 && y < 59))
    //    neighbours++;
    //if (c_array[x-1][y+1].is_alive && (x > 0 && y > 0))
    //    neighbours++;

    return neighbours;
}
