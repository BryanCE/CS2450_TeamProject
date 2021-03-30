// CS2450_TeamProj_V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "View.h"
#include "ViewClient.h"
int main()
{

	//coded by Bryan Edman
	//setting up the needed controllers here in main
	//this could be done in a controller factory later on but for this project this works
	//the controllers will be made into  a facad named view
	//The true View of this MVC design pattern is the ViewClient which takes the facade object
	//and uses it to ask multiple controllers to do things depending on what it needs done. 
	//once the facade is initialized we make a view and start it. 
	//the program returns when the view is no longer needed
	RunCntrl* rc = new RunCntrl; //subsystem 1
	StoreCntrl* sc = new StoreCntrl; //subsystem 2
	View* view = new View(sc,rc); //facade
	ViewClient* vc = new ViewClient(view); // client code
	vc->Run();
	system("PAUSE");
}

