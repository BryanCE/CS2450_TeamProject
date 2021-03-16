// CS2450_TeamProj_V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "View.h"
#include "ViewClient.h"
int main()
{
	//View* view = new View();
	//view->RunView();

	//Subsystem1* subsystem1 = new Subsystem1;
	//Subsystem2* subsystem2 = new Subsystem2;
	//Facade* facade = new Facade(subsystem1, subsystem2);
	//ClientCode(facade);

	RunCntrl* rc = new RunCntrl; //subsystem 1
	StoreCntrl* sc = new StoreCntrl; //subsystem 2
	View* view = new View(sc,rc); //facade
	ViewClient* vc = new ViewClient(view); // client code
	vc->Run();
	//view->RunView(view);
	system("PAUSE");
}

