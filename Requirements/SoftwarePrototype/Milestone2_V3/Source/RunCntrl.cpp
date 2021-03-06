#include "RunCntrl.h"
#include <iostream>

using namespace std;
RunCntrl::RunCntrl() : Controller(&model)
{
	//mRegister = 0;
	//mInstructionCounter = 0;
	//mInstructionRegister = 0;
	mOperationCode = 0;
	//mOperand = 0;
	mInstructionMemoryAddress = 0;
	RO = new RunOperations();
	math = new RunMath();
}

void RunCntrl::Run(int x, int y)
{
	std::cout << "*** Program execution begins ***" << std::endl;
	RO->SetModel(&model);
	math->SetModel(&model);
	while (mOperationCode != 43)
	{
		//used to increment mInstructionMemoryAddress here but that was incorrect for branching -Bryan
		//LoadInstruction(mInstructionMemoryAddress);
		mOperationCode = RO->LoadInstruction(mInstructionMemoryAddress);
		switch (mOperationCode)
		{
			//mInstructionMemoryAddress does or does not need to be incremented based on what operation is performed
			//so I've moved it into the cases where needed. -Bryan
		case 10:
			RO->ReadToMemory();
			mInstructionMemoryAddress++;
			break;
		case 11:
			RO->WriteToScreen();
			mInstructionMemoryAddress++;
			break;
		case 20:
			RO->LoadFromMemoryToReg();
			mInstructionMemoryAddress++;
			break;
		case 21:
			//------------------------NEEDS WORK---------------------------
			RO->StoreToMemory();
			mInstructionMemoryAddress++;
			break;
		case 30:
			RO->mRegister = math->Add(RO->mOperand, RO->mRegister);
			mInstructionMemoryAddress++;
			break;
		case 31:
			RO->mRegister = math->Subtract(RO->mOperand, RO->mRegister);
			mInstructionMemoryAddress++;
			break;
		case 32:
			RO->mRegister = math->Divide(RO->mOperand, RO->mRegister);
			mInstructionMemoryAddress++;
			break;
		case 33:
			RO->mRegister = math->Multiply(RO->mOperand, RO->mRegister);
			mInstructionMemoryAddress++;
			break;
		case 40:
			//in a branch we may or may not need mInstructionMemoryAddress to move forward or somewhere else 
			//so the increment or movement is done within the branch() branchneg() or branchzero() functions - Bryan
			RO->Branch();
			break;
		case 41:
			RO->BranchNeg();
			break;
		case 42:
			RO->BranchZero();
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

void RunCntrl::Store()
{
}

void RunCntrl::SetModel(Model* mdl)
{
	model = *mdl;
}

Model* RunCntrl::GetModel()
{
	return &model;
}
