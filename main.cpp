#include <SDL.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "cell.h"
#include "game.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int generation = 0;
Uint32 TICK_INTERVAL_MS = 50;

Uint32 tick(Uint32 interval, void* param);
void apply_rules(Cell cells_array[60][60]);
int main(int argc, char* argv[])
{
    srand(time(NULL));

    SDL_Window* window = NULL;
    SDL_Surface* screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized" << std::endl;

    } else
    {
        window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created." << std::endl;
        } else
        {
            screen_surface = SDL_GetWindowSurface(window);

            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(window);

            // SDL_Delay(2000);
        }
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);
    //std::vector<Cell> cells_vec;

    Cell cells_arr[60][60];
    fill_array_cells(cells_arr, 60);

    place_cells_array(cells_arr, MAX_CELLS_ON_SCREEN, 60, CHANCE_OF_SPAWN);

    /* BLOCK */

    //cells_arr[25][25].is_alive = true;
    //cells_arr[25][26].is_alive = true;
    //cells_arr[26][25].is_alive = true;
    //cells_arr[26][26].is_alive = true;

    /*       */

    /* Blinker */

    //cells_arr[31][30].is_alive = true;
    //cells_arr[32][30].is_alive = true;
    //cells_arr[33][30].is_alive = true;

    //cells_arr[36][31].is_alive = true;
    //cells_arr[36][32].is_alive = true;
    //cells_arr[36][33].is_alive = true;

    /*         */

    //std::cout << cells_arr[2][2].is_alive << std::endl;
    //exit(0);

    SDL_TimerID timer;
    timer = SDL_AddTimer(TICK_INTERVAL_MS, tick, NULL);

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        if (SDL_WaitEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                break;
            }

            if (e.type == SDL_USEREVENT)
            {
                apply_rules(cells_arr);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        /* GRID */
        int x1v_grid = 0; // start
        int y1v_grid = 0;
        int x2v_grid = 0; // end
        int y2v_grid = 600;

        int x1h_grid = 0; // start
        int y1h_grid = 0;
        int x2h_grid = 600; // end
        int y2h_grid = 600;

        for (int i = 0; i < 60; i++)
        {
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

            SDL_RenderDrawLine(renderer, x1v_grid, y1v_grid, x2v_grid, y2v_grid);
            x1v_grid += 10;
            x2v_grid = x1v_grid;

            y1h_grid += 10;
            y2h_grid = y1h_grid;
            SDL_RenderDrawLine(renderer, x1h_grid, y1h_grid, x2h_grid, y2h_grid);

        }

        //apply_rules(cells_arr);
        SDL_Rect rect;
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                Cell* current_cell = &cells_arr[j][i];

                if (current_cell->will_die)
                {
                    current_cell->is_alive = false;
                    current_cell->will_die = false;
                }

                if (current_cell->will_revive)
                {
                    current_cell->is_alive = true;
                    current_cell->will_revive = false;
                }

                if (current_cell->is_alive)
                {
                    rect.x = j * 10;
                    rect.y = i * 10;
                    rect.h = 10;
                    rect.w = 10;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rect);

                }

            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_RemoveTimer(timer);
    SDL_Quit();

    return 0;
}

Uint32 tick(Uint32 interval, void* param)
{
    SDL_Event event;

    event.type = SDL_USEREVENT;
    event.user.code = 0;
    event.user.data1 = NULL;
    event.user.data2 = NULL;

    SDL_PushEvent(&event);

    return interval;
}

void apply_rules(Cell cells_array[60][60])
{
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            std::tuple<int, int> index(j, i);
            unsigned int neighbours = Cell_check_surroundings_array(cells_array, index);
            //if (cells_array[i][j].is_alive)
            //    std::cout << neighbours << std::endl;

            //std::cout << i << j << ": " << neighbours << std::endl;
            //exit(0);

            if (cells_array[j][i].is_alive)
            {
                if (neighbours < 2)
                {
                    cells_array[j][i].will_die = true;
                }

                if (neighbours > 3)
                    cells_array[j][i].will_die = true;

            } else
            {
                if (neighbours == 3)
                    cells_array[j][i].will_revive = true;
            }

        }
    }
}
