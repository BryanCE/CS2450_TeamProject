#pragma once
#include "View.h"
#include "Model.h"
using namespace std;
class Controller
{
public:
	Controller();
	void Launch();
	void dumpMemory();

protected:
	View view;
	Model model;

};

