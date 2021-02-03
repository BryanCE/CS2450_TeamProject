#pragma once
#include <iostream>
#include <iomanip>
#include "Memory.h"
#include "Accumulator.h"
#include <string>
#include <sstream>
class UVSim
{
public:
	UVSim();
	void StartProgram();

//Some generic functions to parse an integer from the string
//credit to stack overflow help
//does handle negative numbers
	template<typename T>
	std::string ToString(const T& v)
	{
		std::ostringstream ss;
		ss << v;
		return ss.str();
	}

	template<typename T>
	T FromString(const std::string& str)
	{
		std::istringstream ss(str);
		T ret;
		ss >> ret;
		return ret;
	}

protected:
	int currentAdress = 0;
	Memory mem;
	Accumulator acmltr = Accumulator(&mem);


};
