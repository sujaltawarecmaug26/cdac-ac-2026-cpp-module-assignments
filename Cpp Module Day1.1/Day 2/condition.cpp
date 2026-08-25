#include <iostream>
using namespace std;

int main(){
    int age;
    

    cout << "Enter your age: ";
    cin >> age;


    if(age >= 18)
        cout <<" You can vote !! \n";
    else{
        cout <<" You cannot vote \n"; 
    }
    int i = 0;
    do{
        cout <<" You can vote !!" << i << "\n" ;
        i++;
    }while( i < 3);

    return 0;
}