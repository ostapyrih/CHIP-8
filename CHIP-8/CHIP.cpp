#include "CHIP.h"
#include <iostream>
#include <fstream>

void CHIP::initialize()
{
	cpu = new CPU();
	for (int i = 0; i < 80; ++i)
		cpu->memory->setData(i, chip8_fontset[i]);


}

void CHIP::loadRom(const char* filename)
{
	FILE* file;
	fopen_s(&file, filename, "rb");
	fseek(file, 0, SEEK_END);
	unsigned long length = ftell(file);
	unsigned char* data = new unsigned char[length + 1];
	memset(data, 0, length + 1);
	fseek(file, 0, SEEK_SET);
	fread(data, 1, length, file);
	fclose(file);

	for (int i = 0; i < length; i++)
	{
		cpu->memory->setData(i + 512, data[i]);
	}
}

void CHIP::emulate()
{

	for (;;)
		cpu->cycle();

}
