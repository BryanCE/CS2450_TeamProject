#include "RunMath.h"
#include <stdlib.h>
#include <iostream>
//RunMath::RunMath()
//{
//	
//}
void RunMath::SetModel(Model* mdl)
{
	mMemory = mdl;
}

Model* RunMath::GetModel()
{
	return mMemory;
}

int RunMath::Add(int addr, int regVal)
{
	//get actual number from memory
	int number = mMemory->LoadFromMemory(addr);
	//add whats in the register to the operands data and keep it in the accumulator register
	return regVal + number;
}

int RunMath::Subtract(int addr, int regVal)
{
	//get actual number from memory
	int number = mMemory->LoadFromMemory(addr);
	//mRegister -= mMemory->LoadFromMemory(mOperand);
	return number - regVal;
}

int RunMath::Divide(int addr, int regVal)
{
	// If Operand is 0, if statement will catch it
	int num = mMemory->LoadFromMemory(addr);
	if (num == 0)
	{
		std::cout << "Attempt to divide by zero";
		exit(1);
	}
	//mRegister = mRegister / mMemory->LoadFromMemory(mOperand);
	return regVal/num;
}

int RunMath::Multiply(int addr, int regVal)
{
	int num = mMemory->LoadFromMemory(addr);
	//mRegister *= mMemory->LoadFromMemory(addr);
	return num * regVal;
}
