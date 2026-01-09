//
// Created by Jackson Johannessen on 1/9/26.
//

#include "Launcher.h"



Launcher::Launcher() {
    SDL_Init(SDL_INIT_VIDEO);
    //create window & renderer
    window = SDL_CreateWindow("GameBoy Emulator - Launcher", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        160 * 3, 144 * 3, SDL_WINDOW_SHOWN);
    renderer =  (SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED ));
}

arguments Launcher::Run() {
    bool quit = false;
    SDL_Event e;
    
    // button positions (x | y | width | height)
    SDL_Rect romButton = {90, 100, 300, 50};
    SDL_Rect saveButton = {90, 210, 300, 50};
    SDL_Rect startButton = {90, 350, 300, 50};

    while(!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            SDL_SetRenderDrawColor(renderer, 0, 11, 29, 0xFF);  // medium blue
            SDL_RenderClear(renderer);

            SDL_SetRenderDrawColor(renderer, 0, 242, 251, 0xFF);  // very light blue
            SDL_RenderFillRect(renderer, &romButton);

            SDL_SetRenderDrawColor(renderer, 0, 242, 251, 0xFF);
            SDL_RenderFillRect(renderer, &saveButton);

            SDL_SetRenderDrawColor(renderer, 100, 200, 100, 255);  // Green
            SDL_RenderFillRect(renderer, &startButton);
            





            SDL_RenderPresent(renderer);
        }   
    
    }

    return romAndSave;
}

