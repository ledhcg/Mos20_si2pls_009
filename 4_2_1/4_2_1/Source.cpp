#include "cl_8.h"
#include <iostream>
using namespace std;
int main() {

	string name; 
	cin >> name;
	cl_1* pointer = new cl_1(name, 2);
	cl_8* object = new cl_8(name);

	return 0;
}
