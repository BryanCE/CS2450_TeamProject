#include "Model.h"

Model::Model()
{
	header.push_back("CS2450 C++ Group 1 \nUVSim Prototype1\nPlease enter your program instructions (data word)\none line at a time");
	header.push_back("For example instruction +1007 would be entered, then hit enter");
	header.push_back("The memory location this instruction will be stored in will be visible\nto the left of each entry. Followed by a :");
	header.push_back("Enter -99999 to stop the instruction entry.\nThis will load and execute your program.\n");
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
