#pragma once
#include <string>
#include "Model.h"
class Controller
{
public:
	Controller(Model* mdl);
	virtual void Run(int x, int y);
	Model* GetModel();
private:
	Model* model;
};

