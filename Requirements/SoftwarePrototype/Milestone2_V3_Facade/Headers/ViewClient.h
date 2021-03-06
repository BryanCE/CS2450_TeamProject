#pragma once
#include "View.h"
class ViewClient
{

public:
	//ViewClient();
	ViewClient(View* v_);//same as runview
	~ViewClient();
	void Run();
	// Displays the register, instructionCounter, instructionRegister, operationCode and operand variables. 
	void DisplayAccumulator();

	//displays all values stored in memory or 0 if empty in the form of a table
	void DisplayMemory();

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
	const int STOP_CODE = -99999;
	View* v;
};

