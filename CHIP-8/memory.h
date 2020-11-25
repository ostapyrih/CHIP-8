#pragma once

class Memory
{
private:
	unsigned char RAM[4096];
public:
	Memory();
	unsigned char getData(int index);
	void setData(int index, unsigned char data);
};
