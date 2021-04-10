#include "StoreCntrl.h"
//Coded by Bryan Edman
StoreCntrl::StoreCntrl()
	:Controller(&model)
{
	instruction = 0;
	instrctnCount = 0;
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

bool StoreCntrl::SaveProgToFile(std::ofstream& filestream, std::string _fileName)
{
	bool saveSuccess = false;
	filestream.open(_fileName);
	if (filestream)
	{
		for (int i = 0; i < instrctnCount; i++)
		{
			filestream << model.LoadFromMemory(i) << std::endl;
		}
		saveSuccess = true;
	}
	return saveSuccess;
}



void StoreCntrl::Store(int addr, int instrcn)
{
	model.StoreValue(addr, instrcn);
	instrctnCount++;
}

void StoreCntrl::SetModel(Model* mdl)
{
	model = *mdl;
}

Model* StoreCntrl::GetModel()
{
	return &model;
}
