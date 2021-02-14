#include <SDL.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "cell.h"
#include "game.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int generation = 0;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    SDL_Window* window = NULL;
    SDL_Surface* screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize" << std::endl;

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
    //exit(0);

    place_cells_array(cells_arr, MAX_CELLS_ON_SCREEN, 60, CHANCE_OF_SPAWN);

    //std::cout << cells_arr[2][2].is_alive << std::endl;
    //exit(0);

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                break;
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

        SDL_Rect rect;
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                Cell current_cell = cells_arr[i][j];

                if (current_cell.will_die)
                {
                    current_cell.is_alive = false;
                    current_cell.will_die = false;
                }

                if (current_cell.will_revive)
                {
                    current_cell.is_alive = true;
                    current_cell.will_revive = false;
                }

                if (current_cell.is_alive)
                {

                    rect.x = i * 10;
                    rect.y = j * 10;
                    rect.h = 10;
                    rect.w = 10;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }

        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                std::tuple<int, int> index(i, j);
                int neighbours = Cell_check_surroundings_array(cells_arr, index);

                if (neighbours < 2)
                    cells_arr[i][j].will_die = true;

                if (neighbours > 3)
                    cells_arr[i][j].will_die = true;

                if (neighbours == 3)
                    cells_arr[i][j].will_revive = true;
            }
        }


        //for (std::size_t i = 0; i < cells_vec.size(); ++i)
        //{
        //    int neighbours;
        //    neighbours = Cell_check_surroundings(cells_vec[i], cells_vec, i);

        //}

        //for (std::size_t i = 0; i < cells_vec.size(); ++i)
        //{
        //    Cell current_cell = cells_vec[i];
        //    if (current_cell.is_alive)
        //    {
        //        SDL_Rect rect;

        //        rect.x = current_cell.x;
        //        rect.y = current_cell.y;
        //        rect.h = 10;
        //        rect.w = 10;

        //        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        //        SDL_RenderFillRect(renderer, &rect);
        //    }

        //}

        //SDL_RenderPresent(renderer);
    //}

    SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
