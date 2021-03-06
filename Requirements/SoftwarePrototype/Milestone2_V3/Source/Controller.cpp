#include "Controller.h"

Controller::Controller(Model* mdl)
{
    model = mdl;
}

void Controller::Run(int x, int y)
{
}

Model* Controller::GetModel()
{
    return model;
}
