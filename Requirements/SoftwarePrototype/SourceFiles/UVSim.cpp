#include "UVSim.h"
using namespace std;
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
		cout << std::setw(2) << setfill('0') << currentAdress << " :";
		cin >> usrInput;
		int instruction = FromString<int>(usrInput);
		if ((instruction < 4) || (instruction > 4))
		{
			cout << "Please Enter a Valid BasicML Instruction" << endl;
		}
		else
		{
			mem.StoreValue(currentAdress, instruction);
		}

		currentAdress++;
	}
	cout << "Program loaded. . ." << endl;
	acmltr.RunProgram();

}
