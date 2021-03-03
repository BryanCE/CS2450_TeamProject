#pragma once
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <sstream>

using namespace std;
class View
{
	const int STOP_CODE = -99999;
public:
	//// CONSTRUCTOR. Takes a pointer to class memory from UVSim and stores it in the Class Memory member variable.
	//Accumulator(class Memory* mem);

    View(class Model* mod, class Controller* cntrl);
    void StartView();
    //displays numbers
    void DisplayAllMemory(int* num);

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

private:
    string usrInput = "";
    Model* model;
	Controller* controller;// = Controller(model);
	int currentAdress = 0;
};

