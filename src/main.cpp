#include <iostream>

#include "Gameboy.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "You have the wrong number of arguments!";
        return 1;
    }
    Gameboy gb{};
    gb.LoadRom(argv[1]);
    std::cout << gb.read(0x0001);
    return 0;
}
