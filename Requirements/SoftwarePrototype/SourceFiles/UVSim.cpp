#include "UVSim.h"
using namespace std;

const int STOP_CODE = -99999;

UVSim::UVSim()
{
	//mem = new Memory();
	//acmltr = new Accumulator(mem);
}

void UVSim::StartProgram()
{
	//string to hold instruction given by the user
	//as of now no crazy verification, if the string is longer than it should be it will
	//ask user to retry
	string usrInput = "";
	//starting text to inform user of use 
	cout << "CS2450 C++ Group 1 \nUVSim Prototype1\nPlease enter your program instructions (data word)\none line at a time" << endl;
	cout << "For example instruction +1007 would be entered, then hit enter" << endl;
	cout << "The memory location this instruction will be stored in will be visible\nto the left of each entry. Followed by a :" << endl;
	cout << "Enter -99999 to stop the instruction entry.\nThis will load and execute your program.\n" << endl;

	//while loop to get and enter each instruction given by the user
	while (usrInput != "-99999")
	{
		//format output of address space in memory to be filled
		cout << std::setw(2) << setfill('0') << currentAdress << " :";
		cin >> usrInput;

		//parse the string for integers, negative and positive
		//functions in UVSim.h
		int instruction = FromString<int>(usrInput);

		//verify to some degree that the user's input is valid
		if ((usrInput.length() < 5) || (usrInput.length() > 5))
		{
			if (instruction == STOP_CODE)
			{
				break;
			}
			else
			{
				cout << "Please Enter a Valid BasicML Instruction" << endl;
			}
		}
		else
		{
			//store the instruction in memory then increment the memory location
			mem.StoreValue(currentAdress, instruction);
			currentAdress++;
		}
	}//end while loop gathering user's instructions
	cout << "Program loaded. . ." << endl;
	//call the accumulator to run the user's program
	acmltr.RunProgram();
	cout << "Simpletron execution terminated" << endl;
	acmltr.DisplayAccumulator();
	mem.DisplayMemory();
}//end StartProgram()
