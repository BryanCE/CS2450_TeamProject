#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Model
{
	private:
		int memory[100] = { 0 };
		std::vector<std::string> header;
		
	public:
		Model();
		std::vector<std::string> GetHeader();
		//takes an integer in range 0-100 (excluding 100) for the address, uses it as the index in array at which to store value
		void StoreValue(int address, int value);

		//takes an integer in range 0-100 for the address and returns value at that index of array
		int LoadFromMemory(int address);
	
		bool isSixDigits[100] = { false };

		////displays all values stored in memory or 0 if empty in the form of a table
		//void DisplayMemory();	
};

