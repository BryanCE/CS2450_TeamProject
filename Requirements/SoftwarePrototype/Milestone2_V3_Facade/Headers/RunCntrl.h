#pragma once
#include "Controller.h"
#include "Model.h"
#include "RunOperations.h"
#include "RunMath.h"



//setting up the facade design pattern
//RunOperations* RunOps = new RunOperations;
//RunMath* Math = new RunMath;
//RunCntrl* facade = new RunCntrl(RunOps, Math);
//Subsystem1* subsystem1 = new Subsystem1;
//Subsystem2* subsystem2 = new Subsystem2;
//Facade* facade = new Facade(subsystem1, subsystem2);
//ClientCode(facade);


//class Facade {
//protected:
//	Subsystem1* subsystem1_;
//	Subsystem2* subsystem2_;
//	/**
//	 * Depending on your application's needs, you can provide the Facade with
//	 * existing subsystem objects or force the Facade to create them on its own.
//	 */
//public:
//	/**
//	 * In this case we will delegate the memory ownership to Facade Class
//	 */
//	Facade(
//		Subsystem1* subsystem1 = nullptr,
//		Subsystem2* subsystem2 = nullptr) {
//		this->subsystem1_ = subsystem1 ? : new Subsystem1;
//		this->subsystem2_ = subsystem2 ? : new Subsystem2;
//	}
//	~Facade() {
//		delete subsystem1_;
//		delete subsystem2_;
//	}

class RunCntrl : public Controller
{
public:
	RunCntrl();
	~RunCntrl();
	void Run(int x, int y);
	void Store();
	void SetModel(Model* mdl);
	Model* GetModel();
protected:
	Model model;
	RunOperations* RO;
	RunMath* math;
	int mOperationCode;
	int mInstructionMemoryAddress;
	//Model* mMemory;
};

