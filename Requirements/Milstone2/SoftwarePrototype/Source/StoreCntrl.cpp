#include "StoreCntrl.h"

StoreCntrl::StoreCntrl()
	:Controller(&model)
{
	instruction = 0;
	//model = *this->GetModel();
}

void StoreCntrl::Run(int addr, int instrcn)
{
	Store(addr, instrcn);
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
