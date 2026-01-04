#include "PPU.h"

void PPU::UpdatePPU(uint8_t TcyclesSinceLastUpdate) {
    TcyclesSinceLastScanline += TcyclesSinceLastUpdate;
    if (TcyclesSinceLastScanline > 456) {
        currentScanline++;
    }
}

void PPU::BeginNewFrame() {
    TcyclesSinceLastScanline = 0;
    currentScanline = 0;
    currentMode = 2;
    std::fill(std::begin(modesCompleted), std::end(modesCompleted), false);
}


