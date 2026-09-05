//============================================================================
// Name        : Network Request Dispatcher.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

enum class HttpStatus{
	OK             = 200,
	Created        = 201,
	BadRequest     = 400,
	Unauthorized   = 401,
	NotFound       = 404,
	ServerError    = 500
};

void handleResponse(HttpStatus status, const string& endpoint){

	int statusCode = (int) status;

	switch(statusCode){
	case 200:
		cout <<endpoint<<"    ->"<<statusCode <<" Ok    : Request successful" << endl;
		break;
	case 201:
		cout <<endpoint<<"    ->"<<statusCode <<" Created : Resource created successfully" << endl;
		break;
	case 400:
		cout <<endpoint<<"    ->"<<statusCode <<" Invalid request : Please check the request data" << endl;
		break;
	case 401:
		cout <<endpoint<<"    ->"<<statusCode <<" Authentication required : Please log in first" << endl;
		break;
	case 404:
		cout <<endpoint<<"    ->"<<statusCode <<" Endpoint Not Found   : Endpoint does not exis" << endl;
		break;
	case 500:
		cout <<endpoint<<"    ->"<<statusCode <<" Server Error   : Internal server error — retry later" << endl;
		break;

	}
}

using header     = pair<string, string>;
using HeaderList = vector<header>;
using Port       = unsigned int;
using IPAddress  = string;

typedef unsigned long long RequestId;


void  printHeaders(const HeaderList& headers){

	cout<<"Headers: "<<endl;

	for(const header& h: headers){
		cout << h.first << " : " << h.second << endl;
	}

}


int main() {
	RequestId req = 1748293847;
	Port frontend = 5000;
	IPAddress serverIP = "192.168.1.10";

	HeaderList header = {
			{"Content-Type", "application/json"},
			{"Authorization", "Bearer xyz"},
		{"Accept", "application/json"}
	};

	handleResponse(HttpStatus::ServerError,"[POST /api/order]");
	handleResponse(HttpStatus::OK,"[GET /api/users]");
	handleResponse(HttpStatus::Unauthorized,"[POST /api/login]");
	handleResponse(HttpStatus::NotFound,"[GET /api/products/99]");

	cout<<"===================================================" << endl;

	cout<<"Request ID: "<<req <<endl;
	cout<<"Server Port: "<<frontend <<endl;
	cout << "Server IP: " << serverIP << endl;
	cout <<endl;

	printHeaders(header);


	return 0;
}
