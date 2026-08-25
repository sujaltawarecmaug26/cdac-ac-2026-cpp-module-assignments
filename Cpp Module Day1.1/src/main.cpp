#include <iostream>
#include<cmath> // for use mathematical in-build functions

int main(){


	//add two numbers

	int num1;
	int num2;

	std::cout << "Enter a First Number: " ;
	std::cin >> num1;

	std::cout << "Enter a Second Number: ";
	std::cin >> num2;

	int sum = num1 + num2;

	std::cout<< "The Sum of "<< num1 << " and " << num2 <<  " is: " << sum;


	//Area of RectangleCalculation
/*
	int length;
	int breadth;

	std::cout << "Enter a Length: ";
	std::cin >> length;

	std::cout << "Enter a Breadth: ";
	std::cin >> breadth;

	int area = length * breadth;

	std::cout << "Area of Rectangle is: " << area;

	*/

	//swap two numbers

/*	int a = 12;
	int b = 10;

	std::cout << "The value of a & b before swap is :" << a << " & " << b << "\n";


	int c = a;
		a = b;
		b = c;

	std::cout << "The value of a & b after swap is :" << a << " & " << b;
 */

	//calculate Simple Interest

/*	int principal;
	int rate;
	int time;

	std::cout << "Enter Principal: ";
	std::cin >> principal;
	std::cout << "Enter a Rate: ";
	std::cin >> rate;
	std::cout << "Enter a time: ";
	std::cin >> time;

	int simpleInterest = (principal*rate*time) / 100;

	std::cout << "The Simple Interest is :" << simpleInterest;

*/
	// calculate power
/*
	int power, base;

	std::cout << "Enter a base of number: ";
	std::cin >> base;

	std::cout << "Enter a power of number: ";
	std::cin >> power;

	double powerOfNumber = pow(base,power);

	std::cout << "The power of number is :" << powerOfNumber;
*/

	//calculate Compound Interest

/*	double principal,rate,time,n;
	double totalAmount, compoundInterset;

		std::cout << "Enter Principal: ";
		std::cin >> principal;

		std::cout << "Enter a Rate: ";
		std::cin >> rate;

		std::cout << "Enter a time: ";
		std::cin >> time;

		std::cout << "Enter no. of times compounded year";
		std::cin >> n;

		double base = 1 + (rate / (100  * n));
		double power = n * time;

		totalAmount = principal * pow(base,power);
		compoundInterset = totalAmount - principal;

		std::cout << "Total Amount is :" << totalAmount << "\n";
		std::cout << "Total Compound Interset is :" << compoundInterset ;
*/

	return 0;
}
