#include "Controller.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>


Controller::Controller(Model* mod)
	:model(mod)
{
}

Controller::~Controller()
{
}

//begin controlling
void Controller::Launch()
{
	//view.StartView();
	////get model's header message then loop through vector and send to the view for display
	//vector<string> header = model.GetHeader();
	//for (string x : header)
	//{
	//	view.DisplayMessage(x);
	//}

	////while loop to get and enter each instruction given by the user
	//string usrInput;
	////ostringtream for formatting ad sending messages to view
	//ostringstream sendString;
	//while ((usrInput = view.GetUserInput()) != "-99999")
	//{
	//	sendString  << std::setw(2) << setfill('0') << currentAdress << " :";
	//	view.DisplayMessage(sendString.str());
	//	usrInput = view.GetUserInput();

	//	//parse the string for integers, negative and positive
	//	//functions in UVSim.h
	//	int instruction = FromString<int>(usrInput);

	//	//verify to some degree that the user's input is valid
	//	if ((usrInput.length() < 4) || (usrInput.length() > 4))
	//	{
	//		if (instruction == STOP_CODE)
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			view.DisplayMessage("Please Enter a Valid BasicML Instruction\n");
	//		}
	//	}
	//	else
	//	{
	//		model.GetMemory().StoreValue(currentAdress, instruction);
	//		currentAdress++;
	//	}
	//}//end while loop gathering user's instructions
	//view.DisplayMessage("Program loaded. . .\n");
	////call the accumulator to run the user's program
	//model.GetAccumlator().RunProgram();

	//model.GetAccumlator().DisplayAccumulator();
	////send view the array of memory stored in Memory Class
	////access through the model which gets memory class and accesses the GetMemArray function
	//view.DisplayAllMemory(model.GetMemory().GetMemArray());

	//dumpMemory();
}

Model Controller::GetModel()
{
	return *model;
}

