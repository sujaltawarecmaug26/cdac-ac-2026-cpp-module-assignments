#include <iostream>
using namespace std;

int main() {
	//print all elememts in an array
//	int arr[5];
//	cout << "Enter 5 integers:";
//	for(int i = 0; i < 5; i++){
//		cin >> arr[i];
//	}
//
//	int sum = 0;
//
//	for(int num : arr){
//		cout << num << " ";
//		sum += num;
//	}
//	cout <<endl;
//	cout << "The Sum Of All Elements is: " << sum;

	//Print All names in an array
/*
	string str[3];
	cout << "Enter 3 names: ";
	for(int i = 0; i < 3; i++){
			cin >> str[i];
		}

	for(string name : str){

		cout << name << " ";
	}
*/

	//Find Largest Number In An Array
/*
		int arr[5];

		cout << "Enter 5 integers:";

		for(int i = 0; i < 5; i++){
			cin >> arr[i];
		}

		for(int i = 0; i < 5; i++){
			cout << arr[i] << " ";
		}

		int max = arr[0];

		for(int i = 0; i < 5; i++ ){
			if(arr[i] >= max){
				max = arr[i];
			}
		}
		cout << endl;
		cout << "The Largest Element in an array is: " << max ;

*/
// Count Positive and Negative Numbers in an Array
		int arr[5];

				cout << "Enter 5 integers:";

				for(int i = 0; i < 5; i++){
					cin >> arr[i];
				}

				for(int i = 0; i < 5; i++){
					cout << arr[i] << " ";
				}

				int negativeCount = 0;
				int positiveCount = 0;


				for(int i = 0; i < 5; i++ ){
					if(arr[i] < 0){
						negativeCount++;
					}else{
						positiveCount++;
					}
				}
				cout << endl;
				cout << "There are " << positiveCount << " positive numbers in an array" <<endl ;
				cout << "There are " << negativeCount << " negative numbers in an array" ;


	return 0;
}
