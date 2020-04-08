#include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	Triangle tri(x, y, z);
	tri.P();
	tri.S();
	return 0;

}