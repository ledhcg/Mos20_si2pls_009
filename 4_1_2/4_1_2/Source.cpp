#include "cl_4.h"
#include <iostream>
using namespace std;
int main() {

	string name; 
	int number;
	cin >> name >> number;
	cl_4* object = new cl_4(name, number);
	return 0;
}
