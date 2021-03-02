#include "Model.h"
Model::Model()
{
	memory = Memory();

	//starting text to inform user of use 
	header.push_back("CS2450 C++ Group 1 \nUVSim Prototype1 Milestone 2\nPlease enter your program instructions (data word) one line at a time\n");
	header.push_back("For example instruction +1007 would be entered, then hit enter.\n");
	header.push_back("The memory location this instruction will be stored in will be visible\nto the left of each entry. Followed by a :\n");
	header.push_back("Enter -99999 to stop the instruction entry.\nThis will load and execute your program.\n");
}

vector<string> Model::GetHeader()
{
	return header;
}

Memory Model::GetMemory()
{
	return memory;
}
