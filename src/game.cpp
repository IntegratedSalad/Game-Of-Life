#include "game.h"
//#include "cell.h"


/* This is an utility */
int rand_range(int min_num, int max_num)
{
    return rand() % (max_num - min_num + 1) + min_num;
    //return (rand() / (RAND_MAX + 1) * (max_num - min_num) + min_num);
}


/* This function belongs to cell.h */
void fill_array_cells(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int n_cells)
{
    for (int i = 0; i < n_cells; i++)
    {
        for (int j = 0; j < n_cells; j++)
        {
            Cell new_cell;
            c_arr[i][j] = new_cell;
        }
    }
}

/* This function belongs to cell.h */
void place_cells_array(Cell c_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int max_cells, const int n_cells, int chance)
{
    /* Placing is just setting the is_alive member to true. */

    for (int i = 0; i < n_cells; i++)
    {
        for (int j = 0; j < n_cells; j++)
        {
            int dice_throw = rand_range(0, 100);
            //std::cout << dice_throw << " " << chance << std::endl;

            if (dice_throw < chance)
            {
                int rand_x = rand_range(0, CELL_NUM_MAP_X - 1);
                int rand_y = rand_range(0, CELL_NUM_MAP_Y - 1);

                c_arr[rand_x][rand_y].is_alive = true;
            }
        }
    }

}

/* This function belongs to cell.h */
void place_cells_vector(std::vector<Cell>& vec, const int max_cells, int chance)
{

    for (int i = 0; i <= max_cells; i++)
    {
        int dice_throw = rand_range(0, chance);

        if (dice_throw < chance)
        {
            Cell new_cell;
            int rand_x = rand_range(0, CELL_NUM_MAP_X);
            int rand_y = rand_range(0, CELL_NUM_MAP_Y);

            new_cell.x = rand_x * 10;
            new_cell.y = rand_y * 10;

            vec.push_back(new_cell);
            std::cout << "Cell at: " << rand_x << " " << rand_y << " " << "created." << std::endl;
        }

    }
}

Uint32 tick_function(Uint32 interval, void* param)
{
    SDL_Event event;

    event.type = SDL_USEREVENT;
    event.user.code = 0;
    event.user.data1 = NULL;
    event.user.data2 = NULL;

    SDL_PushEvent(&event);

    return interval;
}
