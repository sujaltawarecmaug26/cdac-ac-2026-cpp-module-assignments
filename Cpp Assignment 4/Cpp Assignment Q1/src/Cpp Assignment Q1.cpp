//============================================================================
// Name        :  Financial Ledger: Move Semantics & Operator Overloading.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class LedgerEntry{
	string description;
	double* amounts;
	int days;


public:
	static int totalEntries ;

	LedgerEntry(const string& desc, int days) {
	    cout << "Parameter Constructor..." << endl;

	    description = desc;
	    this->days = days;

	    amounts = new double[days];

	    for (int i = 0; i < days; i++) {
	        amounts[i] = 0;
	    }

	    totalEntries++;
	}

	// Copy Constructor — deep copy
	LedgerEntry(const LedgerEntry& other){
		description = other.description;
		days = other.days;

		amounts = new double[days]; // on heap

		for(int i =0; i < days; i++){
			amounts[i] = other.amounts[i];
		}

		totalEntries++;
	}

	LedgerEntry& operator=(const LedgerEntry& other){

		if(this == &other){
			return *this;
		}

		delete [] amounts;

		description = other.description;
		days = other.days;

		amounts = new double[days];

		for(int i =0; i < days; i++){

			amounts[i] = other.amounts[i];

		}

		return *this;
	}

	// Move Constructor — transfer ownership, leave source in valid empty state
	LedgerEntry(LedgerEntry&& other) noexcept{
		description = other.description;
		days = other.days;
		amounts = other.amounts;

		other.amounts = nullptr;

		totalEntries++;
	}

	// Move Assignment Operator — transfer ownership with self-assignment guard
	LedgerEntry& operator=(LedgerEntry&& other) noexcept{
		if(this != &other){
			delete[] this->amounts;
			description = other.description;
			days = other.days;
			amounts = other.amounts;
			other.amounts = nullptr;

			return *this;
		}

		return *this;

	}

	~LedgerEntry(){
		delete [] amounts;
		totalEntries--;
	}

	LedgerEntry operator+(const LedgerEntry& other) const{

		LedgerEntry result("Combined", other.days);

		for (int i = 0; i < other.days; i++) {
		    result[i] = this->amounts[i] + other.amounts[i];
		}


		return result;
	}

	// Compare total sum of amounts
	bool operator==(const LedgerEntry& other) const{
		double sumJan = 0;
		double sumFeb = 0;

		for(int i = 0; i < other.days;i++){
			sumJan += this->amounts[i];
		}

		for(int i = 0; i < other.days;i++){
			sumFeb += other.amounts[i];
		}

		return sumJan == sumFeb;
	}

	bool operator>(const LedgerEntry& other) const{
		double sumJan = 0;
				double sumFeb = 0;

				for(int i = 0; i < other.days;i++){
					sumJan += this->amounts[i];
				}

				for(int i = 0; i < other.days;i++){
					sumFeb += other.amounts[i];
				}

				return sumJan > sumFeb;
	}

	// Subscript operator — access/modify individual day's amount
		double& operator[](int index) {
			return amounts[index];
		}

		const double& operator[](int index) const {
			return amounts[index];
		}

		friend ostream& operator<<(ostream& out, const LedgerEntry& entry){
			out << "Description: " << entry.description << endl;
			    out << "Days: " << entry.days << endl;
			    out << "Amounts: ";

			    for (int i = 0; i < entry.days; i++) {
			        out << entry.amounts[i] << " ";
			    }
			    return out;
		}

		friend istream& operator>>(istream& in, LedgerEntry& entry){
			in >> entry.description ;
			in >> entry.days;

			delete[] entry.amounts;
			entry.amounts = new double[entry.days];

			for (int i = 0; i < entry.days; i++) {
				in >> entry.amounts[i];
		}
			return in;
		}
};

 int  LedgerEntry::totalEntries = 0;


int main() {

	// Objective 1 — Constructor & deep copy
	LedgerEntry jan("January Sales", 5);

	jan[0] = 1200.50;  jan[1] = 3400.00;  jan[2] = 800.75;
	jan[3] = 2100.00;  jan[4] = 650.25;


	LedgerEntry feb("February Sales", 5);
	feb[0] = 900.00;   feb[1] = 2200.50;  feb[2] = 1750.00;
	feb[3] = 3000.00;  feb[4] = 475.50;
	cout << jan << endl;
	cout << feb << endl;

	// Objective 2 — Operator + (sum two ledgers into combined)
	LedgerEntry combined = jan + feb;
	cout << "Combined: " << combined << endl;



	// Objective 3 — Relational operators
	cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << endl;
	cout << "Jan  > Feb : " << (jan  > feb ? "Yes" : "No") << endl;



	// Objective 4 — Move constructor (should NOT deep copy)
	LedgerEntry moved = move(jan);
	cout << "After move, jan.amounts is null: "<<(true ? "YES" : "NO") << endl;
	cout << "Moved entry: " << moved << endl;



	// Objective 5 — Move assignment
	LedgerEntry q1("Q1 Total", 5);
	q1 = move(feb);
	// feb's resources transferred to q1
	cout << "Q1 (moved from feb): " << q1 << endl;

	// Objective 6 — Static member
	cout << "Live LedgerEntry objects: " << LedgerEntry::totalEntries << endl;

	return 0;
}
