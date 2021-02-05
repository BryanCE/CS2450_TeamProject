#include "Accumulator.h"

Accumulator::Accumulator(Memory* mem)
	:mMemory(mem)
{
	mRegister = 0;
	mInstructionCounter = 0;
	mInstructionRegister = 0;
	mOperationCode = 0;
	mOperand = 0;
	mInstructionMemoryAddress = -1;
}

Accumulator::~Accumulator()
{
}

void Accumulator::RunProgram()
{
	cout << "*** Program execution begins ***" << endl;

	while (mOperationCode != 43)
	{
		LoadInstruction(mInstructionMemoryAddress++);
		switch (mOperationCode)
		{
		case 10:
			ReadToMemory();
			break;
		case 11:
			WriteToScreen();
			break;
		case 20:
			LoadFromMemoryToReg();
			break;
		case 21:
			StoreToMemory();
			break;
		case 30:
			Add(mOperand);
			break;
		case 31:
			Subtract();
			break;
		case 32:
			Divide();
			break;
		case 33:
			Multiply();
			break;
		case 40:
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
}

void Accumulator::Divide()
{
}

void Accumulator::Multiply()
{
}

void Accumulator::Branch()
{
}

void Accumulator::BranchNeg()
{
}

void Accumulator::BranchZero()
{
}

void Accumulator::DisplayAccumulator()
{
}
