#pragma once
#include "Model.h"
using namespace std;
class Controller
{
	const int STOP_CODE = -99999;
public:

	Controller(class Model* mod);
	~Controller();

	void Launch();
	Model GetModel();

protected:
	Model* model;
	int currentAdress = 0;

};

