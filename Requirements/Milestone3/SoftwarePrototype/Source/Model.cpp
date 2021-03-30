#include "Model.h"

Model::Model()
{
	header.push_back("CS2450 C++ Group 1 \nUVSim Prototype3\nPlease enter your program instructions (data word)\none line at a time\n");
	header.push_back("Or provide the name of a file you would like to load instructions from.\n");
	header.push_back("Instructions entered one at a time e.g. +1007 would be typed,\npress enter after each instruction.\n");
	header.push_back("The memory location this instruction will be stored in will be visible\nto the left of each entry. Followed by a :\n");
	header.push_back("Enter -99999 to stop the instruction entry.\nThis will load and execute your program.\n\n");
}

std::vector<std::string> Model::GetHeader()
{
	return header;
}

void Model::StoreValue(int address, int value)
{
	memory[address] = value;
}

int Model::LoadFromMemory(int address)
{
	return memory[address];
}
