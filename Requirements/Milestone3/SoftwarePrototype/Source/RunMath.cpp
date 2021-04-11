#include "RunMath.h"
#include <stdlib.h>
#include <iostream>

void RunMath::SetModel(Model* mdl)
{
	mMemory = mdl;
}

Model* RunMath::GetModel()
{
	return mMemory;
}

int RunMath::Add(int addr, int regVal, int& regOverflow)
{
	int regSndHalf = regOverflow;
	int memSndHalf = 0;
	if (mMemory->isSixDigits[addr])
		memSndHalf = mMemory->LoadFromMemory(addr + 1);


	int regFstHalf = regVal;
	int memFstHalf = mMemory->LoadFromMemory(addr);
	
	int regTotal = regFstHalf;
	if(regOverflow != 0)
		regTotal = (regFstHalf * 1000) + regSndHalf;

	int memTotal = memFstHalf;
	if(mMemory->isSixDigits[addr])
		memTotal = (memFstHalf * 1000) + memSndHalf;

	int total = regTotal + memTotal;

	// Check if its overflow
	if (total > 999999)
	{
		cout << "Error. Overflow on register addition with address " << addr << endl;
		total = total - 1000000;
	}

	// Now have to resplit the number if its over 4 digits
	if (total > 9999)
	{
		int secondHalf = total % 1000;
		int firstHalf = total / 1000;
		// Store the value back into the reg
		regOverflow = secondHalf;
		return firstHalf;
	}
	else
		return total;
	
}

int RunMath::Subtract(int addr, int regVal, int &regOverflow)
{
	int regSndHalf = regOverflow;
	int memSndHalf = 0;
	if (mMemory->isSixDigits[addr])
		memSndHalf = mMemory->LoadFromMemory(addr + 1);

	// Now the first half
	int regFstHalf = regVal;
	int memFstHalf = mMemory->LoadFromMemory(addr);
	
	int regTotal = regFstHalf;
	if (regOverflow != 0)
		regTotal = (regFstHalf * 1000) + regSndHalf;

	int memTotal = memFstHalf;
	if (mMemory->isSixDigits[addr])
		memTotal = (memFstHalf * 1000) + memSndHalf;

	int total = memTotal - regTotal;

	// Now have to resplit the number if its over 4 digits
	if (total > 9999)
	{
		int secondHalf = total % 1000;
		int firstHalf = total / 1000;
		// Store the value back into the reg
		regOverflow = secondHalf;
		return firstHalf;
	}
	else
		return total;
	
}

int RunMath::Divide(int addr, int regVal, int &regOverflow)
{
	int memFstHalf = mMemory->LoadFromMemory(addr);
	int regFstHalf = regVal;

	int memSndHalf = 0;
	int regSndHalf = regOverflow;
	if (mMemory->isSixDigits[addr])
		memSndHalf = mMemory->LoadFromMemory(addr + 1);

	if (memFstHalf == 0)
	{
		cout << "Attempt to divide by zero";
		exit(1);
	}

	int regTotal = regFstHalf;
	if (regOverflow != 0)
		regTotal = (regFstHalf * 1000) + regSndHalf;

	int memTotal = memFstHalf;
	if (mMemory->isSixDigits[addr])
		memTotal = (memFstHalf * 1000) + memSndHalf;

	int total = regTotal / memTotal;

	// Now have to resplit the number if its over 4 digits
	if (total > 9999)
	{
		int secondHalf = total % 1000;
		int firstHalf = total / 1000;
		// Store the value back into the reg
		regOverflow = secondHalf;
		return firstHalf;
	}
	else
		return total;
}

int RunMath::Multiply(int addr, int regVal, int &regOverflow)
{
	int memFstHalf = mMemory->LoadFromMemory(addr);
	int regFstHalf = regVal;

	int memSndHalf = 0;
	int regSndHalf = regOverflow;
	if (mMemory->isSixDigits[addr])
		memSndHalf = mMemory->LoadFromMemory(addr + 1);

	int regTotal = regFstHalf;
	if (regOverflow != 0)
		regTotal = (regFstHalf * 1000) + regSndHalf;

	int memTotal = memFstHalf;
	if (mMemory->isSixDigits[addr])
		memTotal = (memFstHalf * 1000) + memSndHalf;

	int total = regTotal * memTotal;

	// Check if its overflow
	if (total > 999999)
	{
		cout << "Error. Overflow on register multiplication with address " << addr << endl;
		int reduction = total / 1000000;
		int correctedNum = total - (reduction * 1000000);

		total = correctedNum;
	}

	// Resplit if above 4 digits
	if (total > 9999)
	{
		int secondHalf = total % 1000;
		int firstHalf = total / 1000;

		regOverflow = secondHalf;
		return firstHalf;
	}
	else
		return total;
}
