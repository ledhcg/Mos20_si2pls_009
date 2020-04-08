#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math m;
	int m1 = m.math1();
	int m2 = m.math2(m1);
	m.math3(m2);
	m.printMath();
	return 0;
}