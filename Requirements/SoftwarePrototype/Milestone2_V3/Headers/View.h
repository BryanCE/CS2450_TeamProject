#pragma once
#include "Controller.h"
#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "StoreCntrl.h"
#include "RunCntrl.h"

class View
{

public:
	View();
	View(StoreCntrl* sc_, RunCntrl* rc_);
	/*void RunView(View* v);*/
	StoreCntrl* StrCntl;
	RunCntrl* RnCntrl;

//// Displays the register, instructionCounter, instructionRegister, operationCode and operand variables. 
//	void DisplayAccumulator();
//
//	//displays all values stored in memory or 0 if empty in the form of a table
//	void DisplayMemory();
//
//	//Some generic functions to parse an integer from the string
////credit to stack overflow help
////does handle negative numbers
//	template<typename T>
//	std::string ToString(const T& v)
//	{
//		std::ostringstream ss;
//		ss << v;
//		return ss.str();
//	}
//
//	template<typename T>
//	T FromString(const std::string& str)
//	{
//		std::istringstream ss(str);
//		T ret;
//		ss >> ret;
//		return ret;
//	}


protected:
	//int currentAdress = 0;
	//const int STOP_CODE = -99999;
	//Controller* cntrl;


};

//Subsystem1* subsystem1 = new Subsystem1;
//Subsystem2* subsystem2 = new Subsystem2;
//Facade* facade = new Facade(subsystem1, subsystem2);
//ClientCode(facade);