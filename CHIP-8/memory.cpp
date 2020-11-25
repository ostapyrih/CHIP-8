#include "memory.h"

Memory::Memory()
{
    for (int i = 0; i < 4096; i++)
        RAM[i] = 0;
}

unsigned char Memory::getData(int index)
{
    return RAM[index];
}

void Memory::setData(int index, unsigned char data)
{
    RAM[index] = data;
}
