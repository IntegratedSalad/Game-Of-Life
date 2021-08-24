//
//  engine.cpp
//  gol
//
//  Created by Dev on 11/08/2021.
//

#include "engine.hpp"
#include "game.h"
#include "constants.h"

/* Instead of using arrays, use vectors */

Engine::Engine()
{
    timerTick = SDL_AddTimer(tickIntervalms, tickFunction, NULL);
    Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE];
    
    initCellsArray(cells_array, MAX_CELLS_ON_SCREEN, NUM_CELLS_START, CHANCE_OF_SPAWN);
    
    mainLoop(cells_array);
    
}

void Engine::mainLoop(Cell cellsArray[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE])
{
    SDL_Event e;
    running = true;
    bool paused = false;
    
    while (running)
    {
        std::string event_status = handleEvents(&e, paused);
    }
}

std::string Engine::handleEvents(SDL_Event* event, bool paused)
{
    
    if (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            return "quit";
        } else if (event->type == SDL_KEYDOWN)
        {
            switch (event->key.keysym.sym)
            {
                case SDLK_r:
                    return "reset";
                    break;

                case SDLK_SPACE:
                    return "pause";
                    break;
            }
        } else
        {
            if (event->type == SDL_USEREVENT && !paused)
            {
                return "apply_rules";
            }
        }
        
    }
    
    return "no_event";
}

void Engine::initCellsArray(Cell arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int MAX_CELLS, const int N_START_CELLS, int chance)
{
    
    fill_array_cells(arr, N_START_CELLS);
    place_cells_array(arr, MAX_CELLS, N_START_CELLS, chance);
    
    
}

void Engine::render_all(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], SDL_Renderer* renderer)
{
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

    for (int i = 0; i < BOARD_SIZE_SQUARE; i++)
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
    for (int i = 0; i < BOARD_SIZE_SQUARE; i++)
    {
        for (int j = 0; j < BOARD_SIZE_SQUARE; j++)
        {
            Cell* current_cell = &cells_array[j][i];

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
