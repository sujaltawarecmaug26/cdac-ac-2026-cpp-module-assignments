#include <iostream>
using namespace std;

int main() {
	int statusReg  = 0b10110001;
	int controlReg = 0b00000000;
	int dataReg    = 0b11001010;


	int* regptr1 = &statusReg;
	 cout << "regPtr1 value: " << *regptr1 << endl;

	 // regptr1 = 10;
	 //edit the value of regptr1 is not allowed
	 //error :invalid conversion from 'int' to 'int*'

	 regptr1 = &dataReg; // it allowed because the pointer itself is not constant

	int* const regptr2 = &controlReg;
	cout << "regPtr2 value: "<< *regptr2 << endl;

	// Writing through regPtr2 is allowed
	*regptr2 = 12;

	cout << "controlReg after write: " << controlReg << endl;

	// Repointing is NOT allowed
	// regPtr2 = &dataReg;
	// ERROR: regPtr2 is a const pointer and cannot point to another address;

	const int* const regPtr3 = &dataReg;

	//reading is allowed
	cout << "regPtr3 value: "<< *regPtr3 << endl;

	 // Writing is NOT allowed
	 // *regPtr3 = 10;
	// ERROR: Cannot modify the value because regPtr3 points to const int

	// Repointing is NOT allowed
	// regPtr3 = &dataReg;
	// ERROR: regPtr3 itself is a const pointer


 	return 0;
}
