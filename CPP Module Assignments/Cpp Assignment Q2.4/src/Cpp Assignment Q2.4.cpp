#include <iostream>
using namespace std;


bool parsePacket(const int* rawData, int size,
const int** outMin, const int** outMax){

	if(size <= 0){
		return false;
	}
		const int* min = rawData; //45 address //*rawdata = 45 value, rawdata 45add;
		const int* max = rawData; //45 add

		for(int i =0; i < size; i++) {
			if(*(rawData + i) < *min){
				min =  (rawData+i);
			}

			if(*(rawData + i) > *max){
				max =  (rawData+i);
			}
		}

		*outMin = min;
		*outMax = max;


	return true;
}

int main() {
	int packet[] = {45, 12, 67, 8, 55, 31};
	const int* minPtr = nullptr;
	const int* maxPtr = nullptr;


	if (parsePacket(packet, 6, &minPtr, &maxPtr)) {
	cout << "Calibration Min : " << *minPtr << endl;
	cout << "Calibration Max : " << *maxPtr << endl;
	}



	return 0;
}
