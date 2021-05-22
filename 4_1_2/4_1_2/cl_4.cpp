#include "cl_4.h"
#include <math.h>
#include <iostream>
using namespace std;
cl_4::cl_4(string nameObject, int num) : cl_3(nameObject, num) {
	cout << nameObject << "_" << number << " " << pow(num, number);
}