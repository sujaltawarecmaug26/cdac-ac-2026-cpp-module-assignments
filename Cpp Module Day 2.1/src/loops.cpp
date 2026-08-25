#include <iostream>
using namespace std;

//while loop
void printEvenNumber(){
	int i = 1;
	while(i <= 50){
		if(i % 2 == 0){
			cout << i << " " ;
		}

		i++;
	}
}

//do-while loop
void askForPositiveNumber(int num){
	do{
		cout << "Enter a Positive Number: ";
		cin >> num;
	}while(num <= 0);
}

//for loop
void multiplicationTable(int num){
	cout << "Multiplication Table of " << num <<endl;

	for(int i = 1; i <= 10 ; i++){
		cout << num <<" X " << i <<" = " << num*i << endl;
	}
}
//switch case + do while loop
void functionsMenu(){
	int choice;
	do{
		cout<<"Welcome to Development Cafe"<<endl;
		cout<<"Here are special functions......."<<endl;
		cout<<"Function 1: Print Event Numbers(1 to 50)"<<endl;
		cout<<"Function 2: Print Multiplication Table "<<endl;
		cout<<"Function 3: Ask for Positive Numbers "<<endl;
		cout<<"Enter 4 to Exit"<<endl;
		cout<<"Enter a number to excute functions: ";
		cin >> choice;
		cout<<"===============================================" << endl;

		switch(choice){
			case 1:
				printEvenNumber();
				break;
			case 2:
				int num;
				cout <<"Enter a number: ";
				cin >> num;
				multiplicationTable(num);
				break;
			case 3:
				int num1;
				cout << "Enter a number: ";
				cin >> num1;
				askForPositiveNumber(num1);
				break;
			case 4:
				cout<<"Exiting the Development Cafe......";
				break;
			default:
				cout<<"Invalid Choice";
			}
		cout<<"============================================" <<endl;

	} while(choice != 4);

}

int main() {

	functionsMenu();

	return 0;
}
