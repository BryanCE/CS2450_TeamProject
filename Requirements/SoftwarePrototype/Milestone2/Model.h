#pragma once
#include "Memory.h"
#include <string>
#include <vector>
using namespace std;
class Model
{

public:
	Model();
	vector<string> GetHeader();
	Memory GetMemory();
private:
	vector<string> header;
	Memory memory;
	//string header;
	
};

