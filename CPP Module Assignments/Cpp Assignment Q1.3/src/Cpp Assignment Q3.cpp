#include <iostream>
using namespace std;

int main() {
	int N;
	cout <<"Enter a size of array: ";
	cin>> N;

	float arr[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}

	cout << "        ";

	for (int j = 0; j < N; j++) {
	    cout << "Room " << j + 1 << " ";
	}

	cout << endl;

	for(int i = 0; i < N; i++){
		cout << "Floor " <<i+1 << " ";

		for(int j = 0; j < N; j++){

			cout << arr[i][j]<<" ";
		}

		cout << endl;
	}

	float hottestRoom = arr[0][0];//1
	int floorNo = 0;
	int roomNo = 0;
	double highestAvg = 0;
	int highestFloor = 0;
	int warningRooms = 0;


	for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(arr[i][j] > hottestRoom){
					hottestRoom = arr[i][j];
					floorNo = i+1;
					roomNo = j+1;
				}
				if(arr[i][j] >= 30){
					warningRooms++;
				}
			}
		}

	for(int i = 0; i < N; i++){

		double sum = 0;

			for(int j = 0; j < N; j++){
				sum+= arr[i][j];

				}
		double avg = sum / N;

		if(avg > highestAvg){
			highestAvg = avg;
			highestFloor = i+1;
		}

	}


	cout <<"Hottest Room: " << "Floor "<<floorNo<< ", Room "<<roomNo <<"  => " <<hottestRoom<<" "<< endl;

	cout <<"Hottest Floor: " << "Floor "<<highestFloor<< " (avg " <<highestAvg << "C)"<<endl;

	cout <<"Rooms at WARNING or above: " << warningRooms;




	return 0;
}
