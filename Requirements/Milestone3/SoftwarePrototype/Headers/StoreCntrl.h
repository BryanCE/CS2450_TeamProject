#pragma once
#include "Controller.h"
#include "Model.h"
#include <fstream>
#include <sstream>
//Coded by Bryan Edman
class StoreCntrl : public Controller
{
public:
	const std::string STOPCODE = "-99999";
	StoreCntrl();
	void Run(int addr, int instrcn);
	void Run(std::ifstream &fileStream);
	void Store(int addr, int instrcn);
	void SetModel(Model* mdl);
	Model* GetModel();

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
	int instruction;
	Model model;
};

