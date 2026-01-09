#include <iostream>
#include "Platform.h"
#include "Launcher.h"



int main(int argc, char* argv[]) {
    // change to just accept the executable name or just run executable
    // uses sdl 'start' window to prompt for rom file and optional save file
    // on button press, builds platform with given data


    // less than 2 args means executable and that's all
    if (argc < 2) {
        // std::cerr << "You have the wrong number of arguments!";
        // // change to call launcher
        Launcher launcher;
        launcher.Run();
        //return 1;

    }
    const char* ROMFilename = argv[1];
    const char* saveFilename = nullptr;
    //at least 3 args means executable, rom, savefile
    if(argc >= 3) {saveFilename = argv[2]; }
    Platform platform(ROMFilename, saveFilename);
    platform.Run();
    return 0;
}
