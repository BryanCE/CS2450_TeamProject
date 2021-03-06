#include "Accumulator.h"


Accumulator::Accumulator(Memory* mem)
	:mMemory(mem)
{
	mRegister = 0;
	mInstructionCounter = 0;
	mInstructionRegister = 0;
	mOperationCode = 0;
	mOperand = 0;
	mInstructionMemoryAddress = 0;
}

Accumulator::~Accumulator()
{
}

void Accumulator::RunProgram()
{
	cout << "*** Program execution begins ***" << endl;

	while (mOperationCode != 43)
	{
		//used to increment mInstructionMemoryAddress here but that was incorrect for branching -Bryan
		LoadInstruction(mInstructionMemoryAddress);
		switch (mOperationCode)
		{
			//mInstructionMemoryAddress does or does not need to be incremented based on what operation is performed
			//so I've moved it into the cases where needed. -Bryan
		case 10:
			ReadToMemory();
			mInstructionMemoryAddress++;
			break;
		case 11:
			WriteToScreen();
			mInstructionMemoryAddress++;
			break;
		case 20:
			LoadFromMemoryToReg();
			mInstructionMemoryAddress++;
			break;
		case 21:
			StoreToMemory();
			mInstructionMemoryAddress++;
			break;
		case 30:
			Add(mOperand);
			mInstructionMemoryAddress++;
			break;
		case 31:
			Subtract();
			mInstructionMemoryAddress++;
			break;
		case 32:
			Divide();
			mInstructionMemoryAddress++;
			break;
		case 33:
			Multiply();
			mInstructionMemoryAddress++;
			break;
		case 40:
			//in a branch we may or may not need mInstructionMemoryAddress to move forward or somewhere else 
			//so the increment or movement is done within the branch() branchneg() or branchzero() functions - Bryan
			Branch();
			break;
		case 41:
			BranchNeg();
			break;
		case 42:
			BranchZero();
			break;
		case 43:
			cout << "Simpletron execution terminated" << endl;
			break;
		default:
			cout << "ERROR: Reached default on switch statement in RunProgram() in Accumulator class." << endl;
		}

	};

	return;
}

void Accumulator::LoadInstruction(int addr)
{
	// Gets word from memory, store into seperate variable so it doesn't accidentally get changed below

	int num = mMemory->LoadFromMemory(mInstructionMemoryAddress);

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

	return;
}

void Accumulator::ReadToMemory()
{
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	cout << endl;
	mMemory->StoreValue(mOperand, input);

	return;
}

void Accumulator::WriteToScreen()
{
	int num = mMemory->LoadFromMemory(mOperand);

	cout << "Contents of " << mOperand << " is " << num << endl;

	return;
}

void Accumulator::LoadFromMemoryToReg()
{
	mRegister = mMemory->LoadFromMemory(mOperand);

	return;
}

void Accumulator::StoreToMemory()
{
	mMemory->StoreValue(mOperand, mRegister);

	return;
}

void Accumulator::Add(int addr)
{
	//get actual number from memory
	int number = mMemory->LoadFromMemory(addr);
	//add whats in the register to the operands data and keep it in the accumulator register
	mRegister = mRegister + number;
}

void Accumulator::Subtract()
{
	mRegister -= mMemory->LoadFromMemory(mOperand);
	return;
}

void Accumulator::Divide()
{
	// If Operand is 0, if statement will catch it
	if (mMemory->LoadFromMemory(mOperand) == 0)
	{
		cout << "Attempt to divide by zero";
		exit(1);
	}
	mRegister = mRegister / mMemory->LoadFromMemory(mOperand);
	return;
}

void Accumulator::Multiply()
{
	mRegister *= mMemory->LoadFromMemory(mOperand);
	return;
}

void Accumulator::Branch()
{
	//in branch you move wherever regardless of accumulator so mInstructionMemoryAddress just gets assigned - Bryan
	mInstructionMemoryAddress = mOperand;
	return;
}

void Accumulator::BranchNeg()
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

void Accumulator::BranchZero()
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

void Accumulator::DisplayAccumulator()
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