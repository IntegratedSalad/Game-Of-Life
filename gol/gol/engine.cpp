//
//  engine.cpp
//  gol
//
//  Created by Dev on 11/08/2021.
//

#include "engine.hpp"
#include "game.h"

Engine::Engine()
{
    timer_tick = SDL_AddTimer(tick_interval_ms, tick_function, NULL);
    
}
