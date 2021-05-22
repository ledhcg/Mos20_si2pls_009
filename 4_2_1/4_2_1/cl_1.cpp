#include "cl_1.h"
#include <iostream>
using namespace std;

cl_1::cl_1(string nameObject) {
	this->nameObject = nameObject;
	cout << nameObject << "_" << number << endl;
}
cl_1::cl_1(string nameObject,int x) {
	while (x--) {
		this->nameObject = nameObject;
		cout << nameObject << "_" << number << endl;
	}
}