#include <cstdint>
#include <vector>
#include <Gameboy.h>


class Gameboy {
    // All addresses/memory available to the Gameboy, 16-bit addresses
    // Video Memory (VRAM): 8000-9FFF (8KB)
    // Work ram bank 0: C000-CFFF (4KB)
    // Work ram bank 1: D000-DFFF (4KB)
    // High ram: FF80-FFFE (127B)
    // Sprite Attribute Table: FE00-FE9F (160B)
    // I/O Registers: FF00-FF7F (128B)
    uint8_t vram[0x2000]{};
    //work ram (combined), split it into 2
    uint8_t wram0[0x1000]{};
    uint8_t wram1[0x1000]{};
    

    // co-author my commit twin!
    uint8_t oam[0xA0]{};
    uint8_t unusable[0x60]{};
    uint8_t io[0x80]{};
    uint8_t hram[0x7F]{};
    uint8_t ieReg{0};

    // External RAM, can be a lot but we can only see (8KB) at a time, used for save files (.sav)
    std::vector<uint8_t> eRam;
    
    // Memory banks for ROM (16KB each)
    //0000-3FFF
    //4000-7FFF
    // Entire ROM data
    std::vector<uint8_t> rom;


};