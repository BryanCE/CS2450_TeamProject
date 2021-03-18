#include "ViewClient.h"
//refactored and coded by Bryan Edman
using namespace std;
//ViewClient::ViewClient()
//{
//}
ViewClient::ViewClient(View* v_)
{
	v = v_;
}
ViewClient::~ViewClient()
{
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

	//The v is the facade object that the viewclient works with to get the controllers to do what it wants
	v->StrCntl->SetModel(v->RnCntrl->GetModel());

	//while loop to get and enter each instruction given by the user
	while (usrInput != "-99999")
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
	std::cout << "Program loaded. . ." << endl;

	//use facade to switch from the storeController to the RunController
	v->RnCntrl->SetModel(v->StrCntl->GetModel());
	//use facade to start up the RunController, making it ready to execute commands
	v->RnCntrl->Run(0, 0);

	//final display actions needed before simulator ends execution
	DisplayAccumulator();
	DisplayMemory();
}

void ViewClient::DisplayAccumulator()
{
	// Displays the register, instructionCounter, instructionRegister, operationCode and operand variables. 
cout << "\nREGISTERS: " << endl;

cout << "Accumulator\t";
//if accumulator value is 1 digit
//using facade to access controllers and ask for needed info
if (v->RnCntrl->RO->mRegister < 10) {
	cout << "000";
}
//if accumulator value is 2 digits
else if (v->RnCntrl->RO->mRegister < 100 && v->RnCntrl->RO->mRegister > 9) {
	cout << "00";
}
//if accumulator value is 3 digits
else if (v->RnCntrl->RO->mRegister <= 999 && v->RnCntrl->RO->mRegister > 99) {
	cout << "0";
}
//calls out accumulator value
cout << v->RnCntrl->RO->mRegister << endl;

cout << "InstructionCounter\t";
//if instructionCounter is 1 digit
if (v->RnCntrl->RO->mInstructionCounter < 10)
	cout << "0";
//calling the value of instructionCounter
cout << v->RnCntrl->RO->mInstructionCounter << endl;

cout << "InstructionRegister\t";
//if instructionRegister value is 1 digit
if (v->RnCntrl->RO->mInstructionRegister < 10) {
	cout << "000";
}
//if instructionRegister value is 2 digits
else if (v->RnCntrl->RO->mInstructionRegister < 100 && v->RnCntrl->RO->mInstructionRegister > 9) {
	cout << "00";
}
//if instructionRegister value is 3 digits
else if (v->RnCntrl->RO->mInstructionRegister <= 999 && v->RnCntrl->RO->mInstructionRegister > 99) {
	cout << "0";
}
//calls out the value of instructionRegister
cout << v->RnCntrl->RO->mInstructionRegister << endl;

cout << "OperationCode \t";
//if operationcode is in 1 digit
if (v->RnCntrl->RO->mOperationCode < 10)
	cout << "0";
//calls out operationcode
cout << v->RnCntrl->RO->mOperationCode << endl;

cout << "Operand \t";
//if operand value is 1 digit
if (v->RnCntrl->RO->mOperand < 10)
	cout << "0";
//calls out operand value
cout << v->RnCntrl->RO->mOperand << endl;
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
