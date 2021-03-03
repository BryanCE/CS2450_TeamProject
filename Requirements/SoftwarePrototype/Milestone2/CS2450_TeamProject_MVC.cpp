// CS2450_TeamProject_MVC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "View.h"
#include "Model.h"
#include "Controller.h"
using namespace std;

int main()
{
	Model model;
	Controller controller = Controller(&model);
	View view = View(&model, &controller);

	view.StartView();
	system("PAUSE");
	return 0;
}


