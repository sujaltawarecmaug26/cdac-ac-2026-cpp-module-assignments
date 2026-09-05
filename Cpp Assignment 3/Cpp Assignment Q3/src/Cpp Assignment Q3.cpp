//============================================================================
// Name        : LogBufferCpp.cpp
// Author      : Sujal Taware
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;


class LogBuffer{
	char *buffer;
	int capacity;
	int size;
	static int instanceCount;

public:
	// Constructor — allocates char buffer of given capacity on hea
	LogBuffer(int capacity): capacity(capacity){
		size = 0;
		buffer = new char[capacity + 1]; // Allocates on heap
		buffer[0] =0;
		instanceCount++;
		cout<<"Parameter Constructor..." << endl;

	}

	// Copy Constructor — must perform a DEEP copy
	LogBuffer(const LogBuffer& other){
		capacity = other.capacity;
		size = other.size;
		buffer = new char [capacity +1];

		memcpy(buffer, other.buffer, size+1);
		instanceCount++;

	}
	// Destructor — frees the buffer, decrements instanceCoun
	~LogBuffer(){
		cout <<"LogBuffer Destruct0r...." << endl;
		 delete[] buffer;
		instanceCount--;
	}

	LogBuffer& operator=(const LogBuffer& other){
		if(this == &other){
			cout<<"[Self-assignment detected — no operation]"<< endl;
			return *this;
		}
			delete []buffer;

			capacity = other.capacity;
			size = other.size;
			buffer = new char [capacity +1];

			memcpy(buffer, other.buffer, size+1);

			return *this;

	}

	void display(){
		cout <<endl;
		cout <<"Buffer Capacity: " << capacity << endl;
		cout<<"size: " << size << endl;

	}

	void append(const char* msg){
		int msgLength = strlen(msg); //calculate msg length

		int available = capacity - size; //it shows how many space is available

		int copyLength = min(msgLength, available); //how many ele are copied

		memcpy(buffer + size, msg, copyLength);

		size += copyLength; //update the size;

		buffer[size] = '\0'; // C-string end
	}
	void print() const{
		for(int i = 0; i < size ; i++){
			cout <<buffer[i] ;
		}
		cout << endl;
	}
	void clear(){
		buffer[0] = '\0';
		size = 0;
	}


	static int getInstanceCount(){
		return instanceCount;
	}

};

// Initialize static member
int LogBuffer::instanceCount =0;




int main() {
	// Objective 1 : Basic usage
	LogBuffer log1(256);
	log1.append("Server started on port 8080");
	log1.append(" | Request received from 192.168.1.10");
	log1.print();


	// Objective 2 : Deep copy via copy constructor
	LogBuffer log2 = log1;     // copy constructor
	log2.append(" | Cached response sent");
	cout << "log1 : "; log1.print(); // must NOT contain log2's append
	cout << "log2 : "; log2.print();


	// Objective 3 : Copy assignment operator
	LogBuffer log3(128);
	log3 = log1;       // copy assignment
	log3.print();
	log1.print();


	// Objective 4 : Self-assignment guard
//	log1 = log1;       // must not crash or corrupt data
//	log1.print();


//	log3.clear();
//	log3.print();

//	logBuffer log3;
//
//	log3 = log1;
	{
	    LogBuffer test(50);
	    cout <<"Live LogBuffer objects : " <<LogBuffer::getInstanceCount() << endl;
	}

	// Objective 5 : Static member
	cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;


	return 0;
}
