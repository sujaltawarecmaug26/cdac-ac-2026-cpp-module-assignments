#include <iostream>
#include <cmath>
using namespace std;



double computeRMS(double* signal, int n){
	double sum = 0;

	for(int i = 0; i < n; i++ ){
		sum += (*(signal+i)) * (*(signal+i));
	}

	return sqrt(sum/n);
}

void normalise(double* signal, int n){

	double max = abs(*signal); // 1.2

	for(int i = 0; i < n; i++ ){
		if(abs(*(signal+i)) > max){
			max = abs(*(signal+i));
		}
	}

	for(int i = 0; i < n; i++ ){
		*(signal+i) /= max;
		}

	cout << "max absolute value in the array : " << max <<endl;
}

int countZeroCrossings(double* signal, int n){
	int count = 0;
	for(int i = 0; i < n-1; i++ ){
			if((*(signal+i) > 0 && (*(signal+i+1)) < 0) || (*(signal+i) < 0 && (*(signal+i+1)) > 0)){
				count++;
			}

		}
	return count;
}
void applyGain(double* signal, int n, double gainFactor){
	for(int i = 0; i < n; i++ ){
			*(signal + i) *= gainFactor;
		}
	cout << "array after calling applyGain() "<<endl;

	for(int i = 0; i < 7; i++){
			cout << *(signal+i) << " ";
		}

}

int main() {

	double arr[7] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};


	cout << "Root Mean Square (RMS): " << computeRMS(arr, 7) << endl;

	cout << "array before calling normalise() "<<endl;

	for(int i = 0; i < 7; i++){
		cout << arr[i] << " ";
	}

	 cout <<endl;

	 normalise(arr, 7);

	 cout <<endl;

	cout << "array after calling normalise() "<<endl;
	for(int i = 0; i < 7; i++){
		cout << arr[i] << " ";
	}
	cout <<endl;

	cout << "Number of Zero Crossings: "
	     << countZeroCrossings(arr, 7) << endl;

	cout <<endl;

	applyGain(arr,7,2.0);

	return 0;
}
