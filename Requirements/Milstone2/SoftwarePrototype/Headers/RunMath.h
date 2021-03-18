#pragma once
#include "Model.h"
//coded by Bryan Edman
class RunMath
{
private:
	Model* mMemory;
public:

	void SetModel(Model* mdl);
	Model* GetModel();

	// Operation Code: 30	   Calls LoadFromMemory() in class Memory. 
	// Then takes that value and the value in the register and adds them. This new value OVERWRITES the register variable.
	int Add(int addr, int regVal);

	// Operation Code: 31	   Calls LoadFromMemory() in class Memory. Then takes that value and the 
	// value in the register and subtracts them. This new value OVERWRITES the register variable.
	int Subtract(int addr, int regVal);

	// Operation Code: 32	   Calls LoadFromMemory() in class Memory. Order here is important. 
	// Divide the value in the accumulator from the value from the memory. This new value OVERWRITES the register variable.
	int Divide(int addr, int regVal);

	// Operation Code: 33	   Calls LoadFromMemory() in class Memory. 
	// Then takes that value and the value in the register and multiplies them. This new value OVERWRITES the register variable.
	int Multiply(int addr, int regVal);
};
