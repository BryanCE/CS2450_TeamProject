#pragma once
#include "Model.h"
#include <iostream>
using namespace std;
class View
{
public:
    View();
    //displays numbers
    void DisplayAllMemory(int* num);
    //displays strings
    void DisplayMessage(string context);
private:
    Model model;
};

