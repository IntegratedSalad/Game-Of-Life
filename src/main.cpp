#if __win32
#include <SDL.h>
#elif __unix__ || __APPLE__
//#include <SDL2/SDL.h>
#include <SDL.h> // on m1 uncomment this
#endif


#include "app.hpp"


//#include <iostream>
//#include <vector>
//#include <time.h>
//
//#include "cell.h"
//#include "game.h"
//#include "constants.h"
//
//int generation = 0; belongs elsewhere - maybe in the world struct
//Uint32 tick_interval_ms = 50;

//Uint32 tick(Uint32 interval, void* param);
//void apply_rules(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE]);
//void render_all(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], SDL_Renderer* renderer);
int main(int argc, char* argv[])
{
    
    
    App app = App(SCREEN_WIDTH, SCREEN_HEIGHT);
    app.run();
    std::cout << "Ended" << std::endl;
    
    
//
//    /* INIT */
//    srand(time(NULL));
//
//    SDL_Window* window = NULL;
////    SDL_Surface* screen_surface = NULL;
//
//    if (SDL_Init(SDL_INIT_VIDEO) < 0)
//    {
//        std::cout << "SDL could not be initialized" << std::endl;
//
//    } else
//    {
//        window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//        if (window == NULL)
//        {
//            std::cout << "Window could not be created." << std::endl;
//        } else
//        {
//
//            /*
//            screen_surface = SDL_GetWindowSurface(window);
//
//            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
//
//            SDL_UpdateWindowSurface(window);
//
//
//             This initialises the window to be used in blit mode.
//             */
//
//
//
//        }
//    }
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//    SDL_RenderClear(renderer);
//
//    Cell cells_arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE];
//    fill_array_cells(cells_arr, BOARD_SIZE_SQUARE);
//
//    place_cells_array(cells_arr, MAX_CELLS_ON_SCREEN, 60, CHANCE_OF_SPAWN);
//
//    SDL_TimerID timer;
//    timer = SDL_AddTimer(tick_interval_ms, tick, NULL);
//
//    SDL_Event e;
//    /* Main Loop */
    
//
//    bool quit = false;
//    bool pause = false;
//    while (!quit)
//    {
//        if (SDL_PollEvent(&e))
//        {
//            if (e.type == SDL_QUIT)
//            {
//                break;
//
//            }
//            else if (e.type == SDL_KEYDOWN)
//            {
//                switch (e.key.keysym.sym)
//                {
//                    case SDLK_r:
//                        fill_array_cells(cells_arr, BOARD_SIZE_SQUARE);
//                        place_cells_array(cells_arr, MAX_CELLS_ON_SCREEN, 60, CHANCE_OF_SPAWN);
//                        break;
//
//                    case SDLK_SPACE:
//                        pause = !pause;
//                        break;
//
//                }
//            }
//            else {
//
//                if (e.type == SDL_USEREVENT && !pause)
//                {
//                    apply_rules(cells_arr);
//                }
//            }
//        }
//
//        render_all(cells_arr, renderer);
//
//    }
//
//    SDL_DestroyWindow(window);
//    SDL_DestroyRenderer(renderer);
//    SDL_RemoveTimer(timer);
//    SDL_Quit();

    return 0;
}

//Uint32 tick(Uint32 interval, void* param)
//{
//    SDL_Event event;
//
//    event.type = SDL_USEREVENT;
//    event.user.code = 0;
//    event.user.data1 = NULL;
//    event.user.data2 = NULL;
//
//    SDL_PushEvent(&event);
//
//    return interval;
//}


/* Belongs to engine.h */
//void apply_rules(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE])
//{
//    for (int i = 0; i < BOARD_SIZE_SQUARE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE_SQUARE; j++)
//        {
//            std::tuple<int, int> index(j, i);
//            unsigned int neighbours = Cell_check_surroundings_array(cells_array, index);
//
//            if (cells_array[j][i].is_alive)
//            {
//                if (neighbours < 2)
//                {
//                    cells_array[j][i].will_die = true;
//                }
//
//                if (neighbours > 3)
//                    cells_array[j][i].will_die = true;
//
//            } else
//            {
//                if (neighbours == 3)
//                    cells_array[j][i].will_revive = true;
//            }
//
//        }
//    }
//}
//
//void render_all(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], SDL_Renderer* renderer)
//{
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    SDL_RenderClear(renderer);
//
//    /* GRID */
//    int x1v_grid = 0; // start
//    int y1v_grid = 0;
//    int x2v_grid = 0; // end
//    int y2v_grid = 600;
//
//    int x1h_grid = 0; // start
//    int y1h_grid = 0;
//    int x2h_grid = 600; // end
//    int y2h_grid = 600;
//
//    for (int i = 0; i < BOARD_SIZE_SQUARE; i++)
//    {
//        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
//
//        SDL_RenderDrawLine(renderer, x1v_grid, y1v_grid, x2v_grid, y2v_grid);
//        x1v_grid += 10;
//        x2v_grid = x1v_grid;
//
//        y1h_grid += 10;
//        y2h_grid = y1h_grid;
//        SDL_RenderDrawLine(renderer, x1h_grid, y1h_grid, x2h_grid, y2h_grid);
//
//    }
//
//    SDL_Rect rect;
//    for (int i = 0; i < BOARD_SIZE_SQUARE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE_SQUARE; j++)
//        {
//            Cell* current_cell = &cells_array[j][i];
//
//            if (current_cell->will_die)
//            {
//                current_cell->is_alive = false;
//                current_cell->will_die = false;
//            }
//
//            if (current_cell->will_revive)
//            {
//                current_cell->is_alive = true;
//                current_cell->will_revive = false;
//            }
//
//            if (current_cell->is_alive)
//            {
//                rect.x = j * 10;
//                rect.y = i * 10;
//                rect.h = 10;
//                rect.w = 10;
//                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//                SDL_RenderFillRect(renderer, &rect);
//            }
//        }
//    }
//
//    SDL_RenderPresent(renderer);
//}
