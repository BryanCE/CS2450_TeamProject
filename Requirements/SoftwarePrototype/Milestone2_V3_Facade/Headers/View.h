#pragma once
#include "Controller.h"
#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "StoreCntrl.h"
#include "RunCntrl.h"

class View
{

public:
	View() {StrCntl = nullptr; RnCntrl = nullptr; };
	View(StoreCntrl* sc_, RunCntrl* rc_) { StrCntl = sc_; RnCntrl = rc_; };
	~View() { delete StrCntl; delete RnCntrl; }
	StoreCntrl* StrCntl;
	RunCntrl* RnCntrl;
};
