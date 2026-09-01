//============================================================================
// Name        : Assignment Q1.cpp
// Author      : Sujal Taware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Product{
	int productId;
	string name;
	double price;
	int quantity;

public:

	void acceptDetails(){
		cout << "Enter Product Id: ";
		cin >> productId;

		cout << "Enter Name: ";
		cin >> name;

		cout << "Enter price: ";
		cin >> price;

		cout << "Enter quantity: ";
		cin>>quantity;


	}

	void displayDetails() const{

		    cout << productId << "    "
		         << name << "    "
		         << price << "    "
		         << quantity << "    "
		         << totalValue() << endl;
		}

	double totalValue() const{
		return price * quantity;
	}

	bool isLowStock(int threshold) const{
		if(quantity < threshold){
			return true;
		}else{
			return false;
		}
	}

	string getName() const {
	    return name;
	}




};

//====== Part B ===========
double reorderCost(int qty, double unitPrice){
	double baseCost  = qty * unitPrice;
		return baseCost;
	}


double reorderCost(double qty, double unitPrice){
	double baseCost = qty * unitPrice;
	return baseCost;
}


double reorderCost(int qty, double unitPrice, double taxRate){
	double baseCost = qty * unitPrice;
	double tax = baseCost * taxRate / 100;

	return baseCost + tax;

}

double applyDiscount(double price, double discountPercent = 10.0){
		double discountPrice = price * discountPercent / 100;
		double finalPrice = price - discountPrice;
		return finalPrice;
}


int main() {
	int N =2;
	Product product [5];
	int threshold;

	for(int i = 0; i < N; i++){
		product[i].acceptDetails();

	}
	cout << "================ INVENTORY REPORT ================" << endl;

    cout << "ID" << "      "
         << "Name" << "      "
         << "Price" << "    "
         << "Qty" << "    "
         << "Total Value" << endl;

	int highestIndex = 0;
	double highestValue = product[0].totalValue();

	for(int i = 0; i < N; i++){
		product[i].displayDetails();

		if(product[i].totalValue() > highestValue){
			highestValue = product[i].totalValue();
			highestIndex = i;
		}

	}



	cout <<"Enter threshold: ";
	cin>>threshold;

	cout <<"Highest Value Product : ";
	product[highestIndex].getName();
	cout<<" ( " <<highestValue;
	cout<<" "<<" )" << endl;

	for(int i = 0; i < N; i++){

		if(product[i].isLowStock(threshold)){
			cout <<"Low Stock "<<"( "<<"threshold: "<< threshold << " ) : ";
			product[i].getName();
		}
	}
	cout<<reorderCost(5, 1233.12) << endl;
	cout <<reorderCost(7, 44.60) << endl;
	cout <<reorderCost(7, 44.60,10.5) << endl;
	cout<<applyDiscount(10000);



	return 0;
}
