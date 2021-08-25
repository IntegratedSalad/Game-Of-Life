//
//  app.hpp
//  gol
//
//  Created by Dev on 10/08/2021.
//

#pragma once

#ifndef app_hpp
#define app_hpp

#endif /* app_hpp */

#if __win32
#include <SDL.h>
#elif __unix__ || __APPLE__
//#include <SDL2/SDL.h>
#include <SDL.h> // on m1 uncomment this
#endif

#include <iostream>
#include "engine.hpp"

class App
{
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    
public:
    App(const int SCREEN_HEIGHT, const int SCREEN_WIDTH);
    ~App();
    
    void run();
    void quit();
};


