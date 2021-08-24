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

class Engine
{
private:
    bool running;
    SDL_TimerID timerTick;
    Uint32 tickIntervalms;
    
public:
    Engine();
    ~Engine();
    
    void mainLoop(Cell cellsArray[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE]);
    std::string handleEvents(SDL_Event* event, bool paused);
    void initCellsArray(Cell arr[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], const int MAX_CELLS, const int N_START_CELLS, int chance);
    
    void render_all(Cell cells_array[BOARD_SIZE_SQUARE][BOARD_SIZE_SQUARE], SDL_Renderer* renderer);
    
    
};

//enum Timers
//{
//    tick = 0
//};
