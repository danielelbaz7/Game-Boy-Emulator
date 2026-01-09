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


public:

    Launcher();
    arguments Run();



private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    arguments romAndSave;


};