//
// Created by Jackson Johannessen on 1/9/26.
//

#include "Launcher.h"
#include <windows.h>
#include <commdlg.h>


Launcher::Launcher() {
    SDL_Init(SDL_INIT_VIDEO);
    //create window & renderer
    window = SDL_CreateWindow("GameBoy Emulator - Launcher", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        160 * 3, 144 * 3, SDL_WINDOW_SHOWN);
    renderer =  (SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED ));
}

bool Launcher::IsClickInRect(int x, int y, SDL_Rect& rect) {
    return (x >= rect.x && x <= rect.x + rect.w &&
            y >= rect.y && y <= rect.y + rect.h);
}

std::string Launcher::OpenFileDialog(const char* filter) {
    OPENFILENAMEA ofn;
    char szFile[260]{};
    
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    
    if (GetOpenFileNameA(&ofn)) {
        return std::string(szFile);
    }
    return "";  // cancelled
}

arguments Launcher::Run() {
    bool quit = false;
    SDL_Event e;
    int mouseX = 0;
    int mouseY = 0;
    
    // button positions (x | y | width | height)
    SDL_Rect romButton = {90, 100, 300, 50};
    SDL_Rect saveButton = {90, 210, 300, 50};
    SDL_Rect startButton = {90, 350, 300, 50};

    while(!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = e.button.x;
                    int mouseY = e.button.y;
                    
                    if (IsClickInRect(mouseX, mouseY, romButton)) {
                        // prompt user to choose rom | update struct
                        std::string path = OpenFileDialog("Game Boy ROMs\0*.gb;");
                        romAndSave.romPath = path;
                    }
                    else if (IsClickInRect(mouseX, mouseY, saveButton)) {
                        // prompt user to choose sav | update struct
                        std::string path = OpenFileDialog("Save Files\0*.sav\0All Files\0*.*\0");
                        romAndSave.savePath = path;
                    }
                    else if (IsClickInRect(mouseX, mouseY, startButton)) {
                        // exit loop
                        quit = true;

                    }
                }
            }
        }
        
        // Render
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

    return romAndSave;
}

