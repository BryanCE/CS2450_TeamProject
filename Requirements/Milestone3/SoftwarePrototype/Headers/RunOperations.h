#pragma once
#include "Model.h"
class RunOperations
{
public:
	int mRegister;
	int mInstructionCounter;
	int mInstructionRegister;
	int mOperationCode;
	int mOperand;
	int mInstructionMemoryAddress;
	Model* mMemory;
	int mOverFlowSixDigit;


	RunOperations();
	void SetModel(Model* mdl);
	Model* GetModel();

	// Calls LoadFromMemory in class Memory using the sent address. 
	// It stores this value in instructionRegister and fills operationCode and operand variables
	int LoadInstruction(int addr);

	// Operation Code: 10      Asks for input from the user. Then it calls the Memory class's function of StoreValue(). 
	// (The memory address will the the operand in the Accumulator's member)
	void ReadToMemory();

	// Operation Code: 11      Displays the memory address and the contents of that memory address to the screen by 
	// calling LoadFromMemory() in the class Memory
	void WriteToScreen();

	// Operation Code: 20      Calls LoadFromMemory() in Class Memory. It takes the returned value and stores it in 
	// register within this class Accumulator
	// ** Name change so it wasn't the same as memory's function name **
	void LoadFromMemoryToReg();

	// Operation Code: 21	   Calls StoreValue() in Class Memory sending the register value.
	void StoreToMemory();



	// Operation Code: 40	   Sets the variable instructionMemoryAdd to what the variable operand holds. 
	// (This will jump the program on the next loop of RunProgam())
	void Branch();

	// Operation Code: 41      First checks the register. If it is negative, sets the variable instructionMemoryAdd to 
	// what the variable operand holds. (This will jump the program on the next loop of RunProgam())
	void BranchNeg();

	// Operation Code: 42	   First checks the register. If it is zero, sets the variable instructionMemoryAdd to 
	// what the variable operand holds. (This will jump the program on the next loop of RunProgam()) 
	void BranchZero();

	// This will be called by UVSim. It should display what the test case shows. 
	// Displays the register, instructionCounter, instructionRegister, operationCode and operand variables. 
	void DisplayAccumulator();
};

