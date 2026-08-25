#include <iostream>
using namespace std;

int main()
{

    /* Q) Check Number whether is positive or not

        int a;
        cout<<"Enter a Number to check whether is positive or not: ";
        cin>>a;

        if(a <0){
            cout<< a << " is a negative number";
        }else{
            cout << a << " is a positive number";
        }

    */

    /* Q) Find the Largest of Three Number

    int num1;
    int num2;
    int num3;

    cout << "Enter a First Number: ";
    cin >> num1;

    cout << "Enter a Second Number: ";
    cin >> num2;

    cout << "Enter a Third Number: ";
    cin >> num3;

    if (num1 > num2)
    {
        if (num1 > num3)
        {
            cout << "The Largest of Three Number is: " << num1;
        }
        else
        {
            cout << "The Largest of Three Number is: " << num3;
        }
    }
    else
    {
        if (num2 > num3)
        {
            cout << "The Largest of Three Number is: " << num2;
        }
        else
        {
            cout << "The Largest of Three Number is: " << num3;
        }
    }
    */
    /*
    Q) Grade Evaluation System

    int math;
    int science;
    int history;

    cout << "Enter a marks Scored in Math: ";
    cin >> math;

    cout << "Enter a marks Scored in Science: ";
    cin >> science;

    cout << "Enter a marks Scored in History: ";
    cin >> history;

    int avg = (math + science + history) / 3;

    cout << "Your Average marks is : "<<avg << "\n";

    if(avg >= 90){
        cout << "You Got Grade A";
    }else if (avg > 70 && avg < 89){
        cout << "You Got Grade B";
    }else if (avg > 50 && avg < 69){
        cout << "You Got Grade C";
    }else if (avg > 30 && avg < 49){
        cout << "You Got Grade D";
    }else{
        cout << "You are failed";
    }

    */

    return 0;
}