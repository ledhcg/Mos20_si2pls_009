#include "cl_2.h"
#include <math.h>
#include <iostream>
using namespace std;
cl_2::cl_2(string nameObject, int num) : cl_1(nameObject, num) {
	cout << nameObject << "_" << number << " " << pow(num, number) << endl;
}