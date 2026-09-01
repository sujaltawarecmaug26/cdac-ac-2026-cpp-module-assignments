//============================================================================
// Name        : Hospital Patient Registr.cpp
// Author      : sujal taware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Patient{
	int patientId;
	string name;
	int age;
	string ward;
	const string bloodGroup;

public:
	// Constructor 1 — Default: id=0, name="Unknown", age=0, ward="General", bloodGroup="O+"
	Patient(): bloodGroup("O+"){
		patientId = 0;
		name ="Unknown";
		age = 0;
		ward = "General";
	}

	// Constructor 2 — Emergency admission: only id and name known
	Patient(int id, const string& name){
		this->patientId = id;
		this->name = name;
	}
	// Constructor 3 — Full admission detail
	Patient(int id, const string& name, int age, const string& ward, const string&
	bg):bloodGroup(bg){
		patientId = id;
		this->name = name;;
		this->age = age;
		this->ward = ward;
	}

	~Patient(){
		cout<<"Patient " << name << " discharged." <<endl;
	}

	void displayRecord() const{
		cout <<"====== Patient Details ======" <<endl;
		cout <<"Patient Id is: "<<patientId <<endl;
		cout <<"Patient Name is: "<< name <<endl;
		cout <<"Patient Age is: " << age <<endl;
		cout <<"Patient Ward is: "<< ward << endl;
		cout <<"Patient BloodGroup is: "<< bloodGroup << endl;
	}

	void transferWard(const string& newWard){
		cout <<"old Ward: " <<ward << " new ward: "<< newWard << endl;;
	}

};




int main() {


	//obj on stack
//	Patient p1();
//	Patient p2(10,"Salman Khan");
//	Patient p3(101,"Binod Kumr",22,"C","AB+");
//	p2.displayRecord();
//	p3.displayRecord();


	//obj on stack

	int n = 4;
	Patient* ptr = new Patient[n]{
		Patient(),                                               // Calls Constructor 1
		        Patient(10, "Salman Khan"),                             // Calls Constructor 2
		        Patient(101, "Binod Kumar", 22, "ICU", "AB+")
	};

	for(int i = 0; i < n; i++){

		ptr[i].displayRecord();

			cout<<endl;
		}

		cout<<endl;

		ptr[1].transferWard("ICU");

		cout<<endl;

		delete[] ptr;

	return 0;
}
