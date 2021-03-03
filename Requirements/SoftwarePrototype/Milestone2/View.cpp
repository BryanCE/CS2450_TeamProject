#include "View.h"
#include <iomanip>




View::View(Model* mod, Controller* cntrl)
	:model(mod), controller(cntrl)
{
}

void View::StartView()
{
	//get model's header message then loop through vector and send to the view for display
	//view accesses data from the model
	vector<string> header = model->GetHeader();
	for (string x : header)
	{
		cout << x;
	}

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
		if ((usrInput.length() < 4) || (usrInput.length() > 4))
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
			//use controller to execute the change to the model
			controller->GetModel().GetMemory().StoreValue(currentAdress, instruction);
			currentAdress++;
		}
	}//end while loop gathering user's instructions
	cout << "Program loaded. . ." << endl;

	//now we need to push a notification to the controller that the model has been changed
	//basically tell contoller to start the program
	controller->GetModel().GetAccumlator().RunProgram();

	//tell controller to execute a command to accumulator to display itself
	controller->GetModel().GetAccumlator().DisplayAccumulator();
	//access the memory in model and send to display function
	DisplayAllMemory(model->GetMemory().GetMemArray());
}

//memory format funciton
void View::DisplayAllMemory(int* num)
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
		if (num[i] < 0) {
			cout << internal << setw(5) << setfill('0') << num[i] << "   ";
		}
		//output positive number with leading 0s for format
		else {
			cout << setw(5) << setfill('0') << num[i] << "   ";
		}
	}
	cout << '\n';
}

