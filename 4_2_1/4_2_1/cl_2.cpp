#include "cl_2.h"
#include <iostream>
using namespace std;
cl_2::cl_2(string nameObject) : cl_1(nameObject) {
	cout << nameObject << "_" << number << endl;
}