//
//  app.cpp
//  gol
//
//  Created by Dev on 10/08/2021.
//

#include "app.hpp"


App::App(const int SCREEN_HEIGHT, const int SCREEN_WIDTH)
{
    window = NULL;
    renderer = NULL;
    
    srand(time(NULL));
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized" << std::endl;
    } else
    {
        window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created." << std::endl;
        }
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);
    
}

void App::run()
{
    /* Probably engine has to have a private field "world", where it has access to cell array and other data
       and then e.mainLoop() */
    Engine e = Engine(renderer);
    
}
// or pass window to the renderer. however, engine shouldn't handle exiting the program.
App::~App()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
