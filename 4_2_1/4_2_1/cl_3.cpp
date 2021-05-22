#include "cl_3.h"
#include <iostream>
using namespace std;
cl_3::cl_3(string nameObject) : cl_2(nameObject) {
	cout << nameObject << "_" << number << endl;
}