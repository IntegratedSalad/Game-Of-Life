//
//  app.cpp
//  gol
//
//  Created by Dev on 10/08/2021.
//

#include "app.hpp"


App::App(int height, int width)
{
    window = NULL;
    renderer = NULL;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized" << std::endl;
    } else
    {
        window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created." << std::endl;
        }
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);

    
}
