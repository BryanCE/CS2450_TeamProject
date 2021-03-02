#include "View.h"
#include <iomanip>

View::View()
{

}
//sent a pointer to the memory from the controller
//the view formats and displays everything
void View::DisplayAllMemory(int* num)
{
	cout << "Memory:" << endl;
	cout << "\t00      01      02      03      04      05      06      07      08      09" << std::endl;

	//output value in each address location
	for (int i = 0; i < 100; i++) {
		//every 10 values print 00 or 10 indicating table rows
		if ((i % 10 == 0) or (i % 10 == 10)) {
			cout << setw(2) << setfill('0') << endl << i << "\t";
		}
		//output negative number correctly with leading 0s
		if (num[i] < 0) {
			cout << internal << setw(5) << setfill('0') << num[i] << "   ";
		}
		//output positive number with leading 0s for format
		else {
			cout << setw(5) << setfill('0') << num[i] << "   ";
		}
	}
	cout << '\n';
}

void View::DisplayMessage(string context)
{
	cout << context;
}
