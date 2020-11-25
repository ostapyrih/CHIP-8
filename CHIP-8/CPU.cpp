#include "CPU.h"

CPU::CPU()
{
    pc = 0x200;
    opcode = 0;
    I = 0;
    sp = 0;
    memset(V, 0, 16);
    memset(stack, 0, 16);
    memset(key, 0, 16);
	memory = new Memory();
}

void CPU::cycle()
{
    opcode = memory->getData(pc) << 8 | memory->getData(pc + 1);

    switch (opcode & 0xF000)
    {
    case 0xA000: // ANNN: Sets I to the address NNN
    {
        I = opcode & 0x0FFF;
        pc += 2;
        break;
    }
    case 0x6000: // 6XNN Set V[X] to NN
    {
        unsigned char index = (opcode & 0x0F00) >> 8;
        V[index] = opcode & 0x00FF;
        pc += 2;
        break;
    }
    default:
        printf("Unknown opcode: 0x%X\n", opcode);
    }
}
