#pragma once
#include "memory.h"
#include <iostream>

class CPU
{
public:
	CPU();
	void cycle();
	unsigned short I;
	unsigned short pc;
	unsigned short opcode;
	unsigned char V[16];
	unsigned char delay_timer;
	unsigned char sound_timer;
	unsigned short stack[16];
	unsigned short sp;
	unsigned char key[16];
	Memory* memory;

private:
	
};