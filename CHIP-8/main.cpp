#include <iostream>
#include "CHIP.h"

int main()
{
    CHIP* chip = new CHIP();
    chip->initialize();
    chip->loadRom("C:\\Users\\ostap\\source\\repos\\CHIP-8\\Debug\\pong.ch8");
    chip->emulate();
}