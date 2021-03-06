#include "RunOperations.h"
#include <iostream>


using namespace std;
RunOperations::RunOperations()
{
	mRegister = 0;
	mInstructionCounter = 0;
	mInstructionRegister = 0;
	mOperationCode = 0;
	mOperand = 0;
	mInstructionMemoryAddress = 0;
}
void RunOperations::SetModel(Model* mdl)
{
	mMemory = mdl;
}

Model* RunOperations::GetModel()
{
	return mMemory;
}
int RunOperations::LoadInstruction(int addr)
{
	// Gets word from memory, store into seperate variable so it doesn't accidentally get changed below

	int num = mMemory->LoadFromMemory(addr);

	// Stores the number into Accumulator class
	mInstructionRegister = num;

	// Seperates the number into two parts, the first half and second half
	unsigned int divisor = 10;

	while (num / divisor > divisor)
		divisor *= 10;

	// First two numbers
	mOperationCode = num / divisor;
	// Last two numbers
	mOperand = num % divisor;

	return mOperationCode;
}

void RunOperations::ReadToMemory()
{
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	cout << endl;
	mMemory->StoreValue(mOperand, input);

	return;
}

void RunOperations::WriteToScreen()
{
	int num = mMemory->LoadFromMemory(mOperand);

	cout << "Contents of " << mOperand << " is " << num << endl;

	return;
}

void RunOperations::LoadFromMemoryToReg()
{
	mRegister = mMemory->LoadFromMemory(mOperand);

	return;
}

void RunOperations::StoreToMemory()
{
	mMemory->StoreValue(mOperand, mRegister);

	return;
}



void RunOperations::Branch()
{
	//in branch you move wherever regardless of accumulator so mInstructionMemoryAddress just gets assigned - Bryan
	mInstructionMemoryAddress = mOperand;
	return;
}

void RunOperations::BranchNeg()
{
	//either move mInstructionMemoryAddress because register is negative or increment to the next instruction - Bryan
	if (mRegister < 0)
	{
		mInstructionMemoryAddress = mOperand;
	}
	else
	{
		mInstructionMemoryAddress++;
	}


	return;
}

void RunOperations::BranchZero()
{
	//same concept as above - Bryan
	if (mRegister == 0)
	{
		mInstructionMemoryAddress = mOperand;
	}
	else
	{
		mInstructionMemoryAddress++;
	}


	return;
}

void RunOperations::DisplayAccumulator()
{
	// Displays the register, instructionCounter, instructionRegister, operationCode and operand variables. 
	cout << "\nREGISTERS: " << endl;

	cout << "Accumulator\t";
	//if accumulator value is 1 digit
	if (mRegister < 10) {
		cout << "000";
	}
	//if accumulator value is 2 digits
	else if (mRegister < 100 && mRegister > 9) {
		cout << "00";
	}
	//if accumulator value is 3 digits
	else if (mRegister <= 999 && mRegister > 99) {
		cout << "0";
	}
	//calls out accumulator value
	cout << mRegister << endl;

	cout << "InstructionCounter\t";
	//if instructionCounter is 1 digit
	if (mInstructionCounter < 10)
		cout << "0";
	//calling the value of instructionCounter
	cout << mInstructionCounter << endl;

	cout << "InstructionRegister\t";
	//if instructionRegister value is 1 digit
	if (mInstructionRegister < 10) {
		cout << "000";
	}
	//if instructionRegister value is 2 digits
	else if (mInstructionRegister < 100 && mInstructionRegister > 9) {
		cout << "00";
	}
	//if instructionRegister value is 3 digits
	else if (mInstructionRegister <= 999 && mInstructionRegister > 99) {
		cout << "0";
	}
	//calls out the value of instructionRegister
	cout << mInstructionRegister << endl;

	cout << "OperationCode \t";
	//if operationcode is in 1 digit
	if (mOperationCode < 10)
		cout << "0";
	//calls out operationcode
	cout << mOperationCode << endl;

	cout << "Operand \t";
	//if operand value is 1 digit
	if (mOperand < 10)
		cout << "0";
	//calls out operand value
	cout << mOperand << endl;
}
