//
//  app.hpp
//  gol
//
//  Created by Dev on 10/08/2021.
//

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

class App
{
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    
public:
    App(int height, int width);
    ~App();
    
    void run();
};


