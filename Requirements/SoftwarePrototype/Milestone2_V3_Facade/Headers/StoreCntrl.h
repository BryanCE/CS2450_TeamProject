#pragma once
#include "Controller.h"
#include "Model.h"
class StoreCntrl : public Controller
{
public:
	StoreCntrl();
	void Run(int addr, int instrcn);
	void Store(int addr, int instrcn);
	void SetModel(Model* mdl);
	Model* GetModel();
private:
	int instruction;
	Model model;

};

