#include "StoreCntrl.h"
//Coded by Bryan Edman
StoreCntrl::StoreCntrl()
	:Controller(&model)
{
	instruction = 0;
	//model = *this->GetModel();
}

void StoreCntrl::Run(int addr, int instrcn)
{
	StoreCntrl::Store(addr, instrcn);
}

void StoreCntrl::Run(std::ifstream &fileStream)
{
	int adress = 0;
	std::string line;
	while (std::getline(fileStream, line) && line != STOPCODE)
	{
		//parse the string for integers, negative and positive
		int instruction = FromString<int>(line);
		StoreCntrl::Store(adress++, instruction);
	}
}

void StoreCntrl::Store(int addr, int instrcn)
{
	model.StoreValue(addr, instrcn);
}

void StoreCntrl::SetModel(Model* mdl)
{
	model = *mdl;
}

Model* StoreCntrl::GetModel()
{
	return &model;
}
