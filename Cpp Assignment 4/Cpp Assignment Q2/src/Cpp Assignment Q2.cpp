//============================================================================
// Name        : Vehicle Fleet Management: Inheritance & Polymorphism.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


class Vehicle {
protected:
	string registrationNo;
	string ownerName;
	int yearOfManufacture;
	double kmDriven;

public:

	Vehicle(const string& reg, const string& owner, int year, double km){
		cout<<"[Vehicle Constructor] V-ET001 : Green Logistics" << endl;
		registrationNo = reg;
		ownerName = owner;
		yearOfManufacture = year;
		kmDriven = km;
	}

	virtual double fuelCost(double kmToTravel) const = 0; //pure virtual

	// virtual - prints common info
	virtual void describe() const {

	    cout << "Registration No: " << registrationNo << endl;
	    cout << "Owner Name: " << ownerName << endl;
	    cout << "Year of Manufacture: " << yearOfManufacture << endl;
	    cout << "KM Driven: " << kmDriven << endl;
	}

	virtual string vehicleType() const = 0;    //pure virtual

	virtual ~Vehicle(){
		 cout << "[Vehicle Destructor]" << endl;   // Virtual destructor
	}

	double getKmDriven() const{
		return kmDriven;
	}
	string getRegNo() const{
		return registrationNo;
	}

	string getOwnerName() const{
		return ownerName;
	}

};

//Vehicle::~Vehicle() {
//    cout << "[Vehicle Destructor]" << endl;
//}


class Car : public Vehicle{
	 string fuelType;
	 double mileageKmp;


public:

	    Car(const string& reg,
	        const string& owner,
	        int year,
	        double km,
	        const string& fuel,
	        double mileage)
	        : Vehicle(reg, owner, year, km),
	          fuelType(fuel),
	          mileageKmp(mileage) {

	    	cout <<"[Car Constructor] V-ET001." << endl;
	    }

	  double fuelCost(double kmToTravel) const override{

		  double fuelPrice;

	         if (fuelType == "Petrol")
	             fuelPrice = 106.00;
	          else
	             fuelPrice = 93.00;


	         return (kmToTravel / mileageKmp) * fuelPrice;

	  }

	  string vehicleType() const override {
	          return "Car";
	  }

	  void describe() const override {

	          Vehicle::describe();

	          cout << "Fuel Type: " << fuelType << endl;
	          cout << "Mileage: " << mileageKmp << " km/l" << endl;
	      }


};

class Truck : public Vehicle{

	 double payloadCapacityTons;
	 double fuelEfficiencyKmpl;

public:
	Truck( const string & reg,
		        const string& owner,
		        int year,
		        double km,
		        double capacity,
		        double fuelEfficiency)
		        : Vehicle(reg, owner, year, km),
				  payloadCapacityTons(capacity),
				  fuelEfficiencyKmpl(fuelEfficiency){

		    	cout <<"[Truck Constructor] V-ET001." << endl;
		    }

	string vehicleType() const {
		return "Truck";
	}

	 double fuelCost(double kmToTravel) const override{
		 double fuelPrice = 93.00;   // Diesel

		 double effectiveEfficiency =
		         fuelEfficiencyKmpl * (1 - payloadCapacityTons * 0.05);

		     return (kmToTravel / effectiveEfficiency) * fuelPrice;
	 }
	 void describe() const override {

		          Vehicle::describe();

		          cout << "payloadCapacityTons " << payloadCapacityTons << endl;
		          cout << "fuelEfficiencyKmpl: " << fuelEfficiencyKmpl<< " km/l" << endl;
		      }

};

class ElectricTruck : public Truck {

    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& reg,
                  const string& owner,
                  int year,
                  double km,
                  double capacity,
                  double fuelEfficiency,
                  double batteryCapacity,
                  double range)
        : Truck(reg, owner, year, km,capacity, fuelEfficiency),
          batteryCapacityKWh(batteryCapacity),
          rangePerChargeKm(range)
    {

        cout << "[ElectricTruck Constructor] V-ET001" << endl;
    }

    double fuelCost(double kmToTravel) const override {

        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh
               * 9.50;
    }

    string vehicleType() const override {

        return "Electric Truck";
    }

    void describe() const override {

        Truck::describe();

        cout << "Battery Capacity: "
             << batteryCapacityKWh << " kWh" << endl;

        cout << "Range per Charge: "
             << rangePerChargeKm << " km" << endl;
    }
};

class Van : public Vehicle {

    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg,
        const string& owner,
        int year,
        double km,
        int seats,
        double mileage)
        : Vehicle(reg, owner, year, km),
          seatingCapacity(seats),
          mileageKmpl(mileage) {
    	cout <<"Van Constructor >>>>" << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double fuelPrice = 106.00;  // Petrol

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    string vehicleType() const override {

        return "Van";
    }

    void describe() const override {

        Vehicle::describe();

        cout << "Seating Capacity: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl << " km/l" << endl;
    }
};

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm) {

    cout << endl;
    cout << "===== FLEET REPORT =====" << endl;
    cout << "Trip Distance: "
         << tripKm << " km" << endl;

    cout << endl;

    cout << "Reg\t\tType\t\tOwner\t\tKm Driven"
         << endl;

    cout << "------------------------------------------------------------"
         << endl;


    // --------------------------------
    // PART 1: PRINT VEHICLE TABLE
    // --------------------------------

    for (Vehicle* v : fleet) {

        cout << v->getRegNo() << "\t"
             << v->vehicleType() << "\t"
             << v->getOwnerName() << "\t"
             << v->getKmDriven()
             << endl;
    }


    cout << endl;

    cout << "===== FUEL / CHARGE COST ESTIMATE ====="
         << endl;


    // --------------------------------
    // PART 2 + PART 3:
    // COST + MOST EFFICIENT
    // --------------------------------

    double minCost = 1e9;

    Vehicle* efficientVehicle = nullptr;


    for (Vehicle* v : fleet) {

        // Runtime polymorphism
        double cost = v->fuelCost(tripKm);


        cout << v->getRegNo()
             << " (" << v->vehicleType() << ")"
             << " : Rs. "
             << cost;



        ElectricTruck* electric =
            dynamic_cast<ElectricTruck*>(v);


        if (electric != nullptr) {
        	cout << " [Electric Vehicle]" << endl;
//            cout << " [Battery: "
//                 << electric->getBatteryPercentage()
//                 << "% charged]";
        }


        cout << endl;



        if (cost < minCost) {

            minCost = cost;

            efficientVehicle = v;
        }
    }


    cout << endl;

    cout << "Most Efficient Vehicle: "
         << efficientVehicle->getRegNo()
         << " ("
         << efficientVehicle->vehicleType()
         << ") - Rs. "
         << minCost
         << " for "
         << tripKm
         << " km"
         << endl;
}



int main() {

    vector<Vehicle*> fleet;


    fleet.push_back(
        new Car(
            "KA01AA001",
            "Ramesh Kumar",
            2020,
            45200,
            "Petrol",
            18
        )
    );


    fleet.push_back(
        new Truck(
            "MH04BB002",
            "Shyam Logistics",
            2018,
            123500,
            10,
            6
        )
    );


    fleet.push_back(
        new ElectricTruck(
            "GJ07CC003",
            "Green Fleet Co",
            2023,
            89000,
            8,
            5,
            85,
            250
        )
    );


    fleet.push_back(
        new Van(
            "DL09DD004",
            "City Travels",
            2021,
            67000,
            12,
            15
        )
    );


    fleet.push_back(
        new Car(
            "MH12EE005",
            "Amit Sharma",
            2022,
            35000,
            "Diesel",
            20
        )
    );




    printFleetReport(fleet, 200);



    for (Vehicle* v : fleet) {

        delete v;
    }


    return 0;
}
