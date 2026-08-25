#include <iostream>
#include <cmath>
using namespace std;

void swapByReference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int calculateFactorial(int num){
    int res = 1;
    for(int i = num; i > 0 ; i--){
        res *= i;
    }
    
    return res;
}

void calculateSimpleInterest(int p,int r,int t){
  int SimpleInterest =  ( p * r * t ) / 100 ;

  cout << "The simple Interest is: "<<SimpleInterest;
    
}

void checkAgeCategory(int age){

    if( age >= 60){
        cout << "You are a Senior Citizen";
    }else if( age >= 18 && age <= 59){
        cout <<"You are Adult";
    }else{
        cout <<"You are Minor";
    }
}




int main(){
    /*
    int num1;
    int num2;

    cout << "Enter First Number: ";
    cin >> num1;

    cout << "Enter second Number: ";
    cin >> num2;

    cout << "Before swapByValue: ";
    cout << num1 << " "<< num2 << endl;

    swapByValue(num1,num2);
    
    cout << "After swapByValue: ";
    cout << num1 <<" " << num2 << endl;

    cout << "Before swapByReference: ";
    cout << num1 << " "<< num2 << endl;

    swapByReference(num1,num2);
    
    cout << "After swapByReference: ";
    cout << num1 <<" " << num2 << endl;
    */ 

    /*  
    
    int base;
    int expontial;

    cout << "Enter a base of number: ";
    cin >> base;

    cout << "Enter a expontial of number: ";
    cin >> expontial;

    int power = pow(base,expontial);

    cout << "The power of " << base << " is: "<< power;

    */
    /*
    
    int num;

    cout << "Enter a Number to Find a Factorial: ";
    cin >> num;

    int factorial = calculateFactorial(num);

    cout << "The Factorial of " << num << " is: " << factorial;

    */
/*
    int principal;
    int rate;
    int time;

    cout << "Enter a Principal: ";
    cin >> principal;

    cout << "Enter a Rate: ";
    cin >> rate;

    cout << "Enter a time: ";
    cin >> time;

    calculateSimpleInterest(principal,rate,time);
*/
    int age;

    cout << "Enter your age: ";
    cin >> age;

    checkAgeCategory(age);

}