#include "cl_4.h"
#include <iostream>
using namespace std;
cl_4::cl_4(string nameObject) : cl_3(nameObject) {
	cout << nameObject << "_" << number << endl;
}