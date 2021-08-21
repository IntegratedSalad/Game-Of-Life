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

class Engine
{
private:
    bool running;
    SDL_TimerID timer_tick;
    Uint32 tick_interval_ms;
    
public:
    Engine();
    ~Engine();
    
    void main_loop();
    
};

//enum Timers
//{
//    tick = 0
//};
