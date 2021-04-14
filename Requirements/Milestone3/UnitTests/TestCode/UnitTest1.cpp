#include "stdafx.h"
#include "CppUnitTest.h"
#include "Model.h"
#include "RunMath.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(ModelTest)
	{
	public:
		Model* model = new Model;
		TEST_METHOD(TestMemory)
		{
			// TODO: Your test code here
			model->StoreValue(10, 100);
			Assert::AreEqual(100, model->LoadFromMemory(10));
			//Assert::AreEqual(1, 1);
		}

	};
	TEST_CLASS(RunMathTest)
	{
	public:
		Model* model = new Model;
		RunMath* math = new RunMath;

		TEST_METHOD(TestAdd)
		{
			
			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(100, math->Add(1, 50, memory[4]));
		}

		TEST_METHOD(TestAddNeg)
		{

			// TODO: Your test code here
			model->StoreValue(0, -2);
			model->StoreValue(1, -50);
			model->StoreValue(2, -25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = -2;
			memory[1] = -50;
			memory[2] = -25;

			Assert::AreEqual(-100, math->Add(1, -50, memory[4]));
		}

		TEST_METHOD(TestSubtract)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(25, math->Subtract(1, 25, memory[4]));

		}

		TEST_METHOD(TestSubtractNeg)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(-9550, math->Subtract(1, 9600, memory[4]));

		}


		TEST_METHOD(TestMultiply)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(100, math->Multiply(0, 50, memory[4]));
		}

		TEST_METHOD(TestMultiplyBig)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(250000, (math->Multiply(1, 5000, memory[4])*1000 + memory[4]));
		}

		TEST_METHOD(TestDivide)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(2, math->Divide(2, 50, memory[4]));
		}

		TEST_METHOD(TestDivideNeg)
		{

			// TODO: Your test code here
			model->StoreValue(0, 2);
			model->StoreValue(1, 50);
			model->StoreValue(2, 25);
			math->SetModel(model);
			int memory[100] = { 0 };
			memory[0] = 2;
			memory[1] = 50;
			memory[2] = 25;

			Assert::AreEqual(-2, math->Divide(2, -50, memory[4]));
		}
	};
}
