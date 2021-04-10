#include "ViewClient.h"
//refactored and coded by Bryan Edman
using namespace std;
const string STOPCODE = "-99999";
//ViewClient::ViewClient()
//{
//}
ViewClient::ViewClient(View* v_)
{
	v = v_;
}
ViewClient::~ViewClient()
{
	delete v;
}
void ViewClient::Run()
{

	
	//string to hold instruction given by the user
	//as of now no crazy verification, if the string is longer than it should be it will
	//ask user to retry
	string usrInput = "";
	
	//ask the controls to get model header and display it
	for (unsigned int x = 0; x < v->RnCntrl->GetModel()->GetHeader().size(); x++)
	{
		std::cout << v->RnCntrl->GetModel()->GetHeader().at(x);
	}

	//ask if they want to load from a file. if anything but a y/n is entered it will continue to loop
	char loadFileYN;
	do
	{
		cout << "Would you like to load a program from a file?\ty/n" << endl;
		cin >> loadFileYN;
	} while (!std::cin.fail() && loadFileYN != 'y' && loadFileYN != 'n');

	//The v is the facade object that the viewclient works with to get the controllers to do what it wants
	//whether from a file or entering 1 by 1 set the storecontroller
	v->StrCntl->SetModel(v->RnCntrl->GetModel());

	//if no program needs to be loaded from a file we do what we already have.
	if (loadFileYN == 'n')
	{
		//while loop to get and enter each instruction given by the user
		while (usrInput != STOPCODE)
		{
			//format output of address space in memory to be filled
			std::cout << std::setw(2) << setfill('0') << currentAdress << " :";
			cin >> usrInput;

			//parse the string for integers, negative and positive
			//functions in UVSim.h
			int instruction = FromString<int>(usrInput);

			//verify to some degree that the user's input is valid
			if ((usrInput.length() < 4) || (usrInput.length() > 4))
			{
				if (instruction == STOP_CODE)
				{
					break;
				}
				else
				{
					std::cout << "Please Enter a Valid BasicML Instruction" << endl;
				}
			}
			else
			{
				//store the instruction in memory then increment the memory location
				v->StrCntl->Run(currentAdress, instruction);
				currentAdress++;
			}
		}//end while loop gathering user's instructions

		//check if user wants to save to a file or not. 
		SaveToFile();

	}//end if checking for no file load
	else if (loadFileYN == 'y')    //if we do want to load a program from a file
	{
		//input file stream object
		ifstream usrFilestr;

		//make sure we get to opening a file successfully 
		do
		{
			cout << "What is the name of the file you would like to load?" << endl;
			cin >> usrInput;
			if (!std::cin.fail())
			{
				usrFilestr.open(usrInput);
				if (usrFilestr) 
				{
					cout << "Your file opened succesfully!" << endl;
				}
				else 
				{
					cout << "That file doesn't exist!" << endl;
				}

			}
		} while (!usrFilestr.is_open());

		// file exists and is open for reading
		//ask the store controller to load the program in the model
		v->StrCntl->Run(usrFilestr);
		//close up the file streams
		usrFilestr.close();
	}//end of dealing with a file input

	std::cout << "Program loaded. . .\n" << endl;

	//use facade to switch from the storeController to the RunController
	v->RnCntrl->SetModel(v->StrCntl->GetModel());
	//use facade to start up the RunController, making it ready to execute commands
	v->RnCntrl->Run();

	//final display actions needed before simulator ends execution
	v->RnCntrl->RO->DisplayAccumulator();
	
	//DisplayAccumulator();
	DisplayMemory();
}


void ViewClient::DisplayMemory()
{
	cout << "Memory:" << endl;
cout << "\t00      01      02      03      04      05      06      07      08      09" << std::endl;

//output value in each address location
for (int i = 0; i < 100; i++) {
	//every 10 values print 00 or 10 indicating table rows
	if ((i % 10 == 0) or (i % 10 == 10)) {
		cout << setw(2) << setfill('0') << endl << i << "\t";
	}
	//output negative number correctly with leading 0s
	//using facade to get proper controller to retrieve needed data to display it
	if (v->RnCntrl->GetModel()->LoadFromMemory(i) < 0) {
		cout << internal << setw(5) << setfill('0') << v->RnCntrl->GetModel()->LoadFromMemory(i) << "   ";
	}
	//output positive number with leading 0s for format
	else {
		cout << setw(5) << setfill('0') << v->RnCntrl->GetModel()->LoadFromMemory(i) << "   ";
	}
}
cout << '\n';
}

void ViewClient::SaveToFile()
{
	char saveFileYN;
	std::string usrInput;
	do
	{
		cout << "Would you like to save the program you've written to a file?\ty/n" << endl;
		cin >> saveFileYN;
	} while (!std::cin.fail() && saveFileYN != 'y' && saveFileYN != 'n');
	if (saveFileYN == 'y')
	{
		//output file stream
		ofstream saveFilestr;
		cout << "What is the name of the file you would like to save to?" << endl;
		cin >> usrInput;
		if (!std::cin.fail())
		{
			bool success = v->StrCntl->SaveProgToFile(saveFilestr, usrInput);
			if (success)
			{
				cout << "Program saved successfully. . . " << endl;
			}
			else
			{
				cout << "Sorry something went wrong while saving your program. . . " << endl;
			}
		}
		saveFilestr.close();
	}
}
