#include <iostream>
#include <cmath>
using namespace std;



	inline double distanceBetween(double x1, double y1, double x2, double y2){


		return sqrt( pow(x2-x1,2) + pow(y2-y1,2) );

	}

	inline double toRadians(double degrees){

		return degrees * (M_PI/180.0);
	}

	inline double clamp(double value, double minVal, double maxVal){

		if(value < minVal){
			return minVal;
		}else if (value > maxVal){
			return maxVal;
		}else{
			return value;
		}
	}

	inline bool isInSafeZone(double x, double y, double cx, double cy, double radius){

		double distance = distanceBetween(x,y,cx,cy);

		if(distance <= radius){
			return true;
		}else{
			return false;
		}
	}

int main() {
	double homeX = 0.0;
	double homeY  = 0.0;

	double safeZoneRadius = 50.0;

	double waypoint1X = 10.0;
	double waypoint1Y = 20.0;

	double waypoint2X = 30.0;
	double waypoint2Y = 40.0;


	double waypoint3X = 60.0;
	double waypoint3Y = 50.0;



	double distance1 = distanceBetween(homeX,homeY,waypoint1X,waypoint1Y);
	 cout << "Waypoint 1" << endl;
	 cout << "Distance from home: " << distance1 << endl;
	 cout<< boolalpha << "Inside safe zone: "<< isInSafeZone(waypoint1X, waypoint1Y,
	                homeX, homeY, safeZoneRadius)<< endl;
	 cout << "====================================================" << endl;

	 double distance2 = distanceBetween(homeX,homeY,waypoint2X,waypoint2Y);
	 	 cout << "Waypoint 2" << endl;
	 	 cout << "Distance from home: " << distance2 << endl;
	 	cout << boolalpha << "Inside safe zone: "<< isInSafeZone(waypoint2X, waypoint2Y,
	 	                homeX, homeY, safeZoneRadius)<< endl;
	 	 cout << "====================================================" << endl;

	 double distance3 = distanceBetween(homeX,homeY,waypoint3X,waypoint3Y);
	 	cout << "Waypoint 3" << endl;
	 	cout << "Distance from home: " << distance3 << endl;
	 	cout << boolalpha << "Inside safe zone: "<< isInSafeZone(waypoint3X, waypoint3Y,
	 		 	             homeX, homeY, safeZoneRadius)<< endl;
	 	 cout << "====================================================" << endl;



	return 0;
}
