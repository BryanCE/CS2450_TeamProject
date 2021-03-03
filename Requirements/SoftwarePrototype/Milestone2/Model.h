#pragma once
#include "Memory.h"
#include "Accumulator.h"
#include <string>
#include <vector>
using namespace std;
class Model
{

public:
	Model();
	vector<string> GetHeader();
	Memory GetMemory();
	int* GetMemoryArray();
	Accumulator GetAccumlator();

private:
	vector<string> header;
	Memory memory;// = Memory();
	Accumulator acmltr = Accumulator(&memory);
	//string header;
	
};

