#include <cstdint>
#include <vector>
#include "Gameboy.h"

uint8_t Gameboy::read(uint8_t address) {
    if (address <= 0x3FFF) {
        return rom[address];
    }

    if (address <= 0x7FFF) {
        //return the rom at the current window. since the address is greater than 16KB, we subtract 1 from the window
        //this makes address basically equal to the local location inside of the bank
        return rom[((currentRomWindow-1) * 0x4000) + address];
    }

    if (address <= 0x9FFF) {
        //subtract 0x8000 for the vram offset
        return vram[address - 0x8000];
    }
}