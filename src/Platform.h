//
// Created by Daniel Elbaz on 1/1/26.
//

#ifndef GAMEBOYEMULATOR_PLATFORM_H
#define GAMEBOYEMULATOR_PLATFORM_H
#include "Gameboy.h"

//the platform class holds the actual entire computer's logic, pulling from gameboy, ppu, etc.
class Platform {
    Gameboy gb{};
    void Run();

};


#endif //GAMEBOYEMULATOR_PLATFORM_H