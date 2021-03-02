#include "Controller.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

Controller::Controller()
{
	//Controller has access to both the View and the Model
	view = View::View();
	model = Model();
}

//begin controlling
void Controller::Launch()
{
	vector<string> header = model.GetHeader();
	for (string x : header)
	{
		view.DisplayMessage(x);
	}

	dumpMemory();
}

void Controller::dumpMemory()
{
	//get access to memory and call to display the memory
	int* CurrentMem = model.GetMemory().GetMemory();
	view.DisplayAllMemory(CurrentMem);
}
