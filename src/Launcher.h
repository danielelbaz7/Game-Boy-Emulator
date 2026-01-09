#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <SDL2/SDL.h>

struct arguments {
    std::string romPath;
    std::string savePath;
};

class Launcher {

    bool IsClickInRect(int x, int y, SDL_Rect& rect);

    std::string OpenFileDialog(const char* filter);

public:

    Launcher();
    arguments Run();



private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    arguments romAndSave;


};