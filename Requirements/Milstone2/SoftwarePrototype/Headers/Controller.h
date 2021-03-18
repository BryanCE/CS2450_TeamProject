#pragma once
#include <string>
#include "Model.h"

//coded by Bryan Edman
class Controller
{
public:
	Controller(Model* mdl);
	virtual void Run(int x, int y);
	Model* GetModel();
private:
	Model* model;
};
