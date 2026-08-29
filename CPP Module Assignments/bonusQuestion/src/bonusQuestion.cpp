#include <iostream>
using namespace std;

int main() {
	struct Layout1 { char c1; int i; char c2; }; //1+4+4 = 9 --> 12
	struct Layout2 { int i; char c1; char c2; }; // 4+1+1 = 6 --> 8

	cout <<"Size of Layout1: " <<sizeof(Layout1) << endl;
	cout << "Size of Layout2: "<<sizeof(Layout2);

	/*

	 The sizes differ because the compiler may add padding bytes between members.

	 Padding is extra unused memory added to align data members properly in memory.
	   This helps the CPU access data efficiently.

	3 Member order matters because different ordering can change padding and struct size.
	   In network packet headers and hardware register maps, the exact memory layout
	   is important, so unexpected padding can cause incorrect data interpretation.
	   */

	return 0;
}
