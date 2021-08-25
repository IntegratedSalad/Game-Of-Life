//
//  engine.hpp
//  gol
//
//  Created by Dev on 11/08/2021.
//

#ifndef engine_hpp
#define engine_hpp

#endif /* engine_hpp */

#if __win32
#include <SDL.h>
#elif __unix__ || __APPLE__
//#include <SDL2/SDL.h>
#include <SDL.h> // on m1 uncomment this
#endif

#include <iostream>
#include <vector>

#include "cell.h"
#include "constants.h"
#include "game.h"

class Engine
{
private:
    bool running;
    SDL_TimerID timerTick;
    Uint32 tickIntervalms;
    
    SDL_Renderer* renderer;
    
    enum Events
    {
        E_RESET,
        E_PAUSE,
        E_QUIT,
        E_APPLY_RULES,
        E_NO_EVENT
        
    };
    

    
public:
    Engine(SDL_Renderer* r);
    ~Engine();
    
    void mainLoop(Cell cellsArray[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE]);
    int handleEvents(SDL_Event* event, bool paused);
    void initCellsArray(Cell arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int MAX_CELLS, const int N_START_CELLS, int chance);
    
    void renderAll(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], SDL_Renderer* renderer);
    void apply_rules(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE]);
    
};

//enum Timers
//{
//    tick = 0
//};
