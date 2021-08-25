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
    
    return 0;
}
