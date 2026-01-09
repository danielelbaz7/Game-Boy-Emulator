#include <iostream>

#include "Platform.h"

int main(int argc, char* argv[]) {
    // less than 2 args means executable and that's all
    if (argc < 2) {
        std::cerr << "You have the wrong number of arguments!";
        return 1;
    }
    const char* ROMFilename = argv[1];
    const char* saveFilename = nullptr;
    //at least 3 args means executable, rom, savefile
    if(argc >= 3) {saveFilename = argv[2]; }
    Platform platform(ROMFilename, saveFilename);
    platform.Run();
    return 0;
}
