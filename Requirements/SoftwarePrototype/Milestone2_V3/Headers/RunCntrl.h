#pragma once
#include "Controller.h"
#include "Model.h"
#include "RunOperations.h"
#include "RunMath.h"

class RunCntrl : public Controller
{
public:
	RunCntrl();
	void Run(int x, int y);
	void Store();
	void SetModel(Model* mdl);
	Model* GetModel();
private:
	Model model;
	RunOperations* RO;
	RunMath* math;
	//int mRegister;
	//int mInstructionCounter;
	//int mInstructionRegister;
	int mOperationCode;
	//int mOperand;
	int mInstructionMemoryAddress;
	//Model* mMemory;
};

