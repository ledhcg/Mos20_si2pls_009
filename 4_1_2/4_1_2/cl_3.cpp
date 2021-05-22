#include "cl_3.h"
#include <math.h>
#include <iostream>
using namespace std;
cl_3::cl_3(string nameObject, int num) : cl_2(nameObject, num) {
	cout << nameObject << "_" << number << " " << pow(num, number) << endl;
}