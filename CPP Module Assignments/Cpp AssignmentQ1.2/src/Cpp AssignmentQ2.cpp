#include <iostream>
using namespace std;

int main(){
	int N;
	cout << "Enter the size: ";
	cin >> N;


	double temp[N];


	for(int i =0; i < N; i++){
		cin >> temp[i];
	}

	int skip = 0;

	cout << "Readings Entered: " << N <<endl;


	cout <<"Valid readings: ";
	for(int i = 0; i < N; i++){
		if( temp[i] <= 0){
			skip++;
		}else
		cout << temp[i] <<" ";
	}

	cout << endl;

	for(int i = 0; i < N; i++){
		if(temp[i] >= 45){
			cout <<"First CRITICAL :" <<"Index :" << i << " " << "=>" << " "<< temp[i];
			break;
		}

	}

	double mini = INT_MAX;
	double maxi = INT_MIN;

	for(int i = 0; i < N; i++){
		mini= min(mini,temp[i]);
		maxi = max(maxi,temp[i]);
	}

	int sum = 0;
	int normal = 0;
	int warning = 0;
	int critical = 0;
	int shutdown = 0;

	for(double arr : temp){
		sum += arr;
		if (arr >= 0 && arr <= 29){
			normal++;
		}else if (arr >= 30 && arr <= 44){
			warning++;
		}else if (arr >= 45 && arr <= 59){
			critical++;
		}else{
			shutdown++;
			}
	}

	double  avg = sum / (N - skip);


	cout << endl;

	cout << "Min:" << mini <<" "<< "Max: " << maxi << " "<< "Average: " << avg << endl;

	cout << "Normal: " << normal <<" " << "Warning: " << warning << " ";
	cout <<"Critical: " << critical <<" " << "Shutdown: " << shutdown;



return 0;



}
