#include <iostream>
using namespace std;
int main() {
	double temp;
	int statusCode;
	string statusLabel;
	string action;

	cout << "Enter The Temperature of the store: ";
	cin >> temp;
	cout << "Temperature: " << temp;

	if(temp < 0){
		statusCode = -1;
		statusLabel = "SENSOR_ERROR";
	}else if (temp >= 0 && temp <= 29){
		statusCode = 0;
		statusLabel = "NORMAL";
	}else if (temp >= 30 && temp <= 44){
		statusCode = 1;
		statusLabel = "WARNING";
	}else if (temp >= 45 && temp <= 59){
		statusCode = 2;
		statusLabel = "CRITICAL";
	}else if (temp >= 60){
		statusCode = 3;
		statusLabel = "SHUTDOWN";
	}else{
		cout << "Invalid Input......";
	}

	switch(statusCode){
	case -1:
		action = "Sensor fault - check wiring";
		break;
	case 0:
		action = "No action required";
		break;
	case 1:
		action = "Alert sent to supervisor";
		break;
	case 2:
		action = "Cooling system triggered";
		break;
	case 3 :
		action = "Emergency shutdown initiated";
		break;
	default:
		action = "Something went wrong";
	}

	double farhrenheit = (temp * 9 /5) + 32;

	string reading = (temp < 25) ? "Below Average" : "Above Average";

	cout << "Temperature: " << temp <<"C"<< " / " << farhrenheit << "F" << endl;;
	cout << "Status: " << statusLabel << endl;
	cout << "Action: " << action << endl ;
	cout << "Reading: " << reading << endl;

	return 0;
}
