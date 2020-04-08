
#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;
Triangle::Triangle(double x, double y, double z) 
{
	a = x;
	b = y;
	c = z;
}
void Triangle::P() 
{
	double p;
	p = a + b + c;
	cout << "P = " << p << endl;
}
void Triangle::S()
{
	double s;
	double p;
	p = (a + b + c) / 2;
	s = sqrt((p) * (p - a) * (p - b) * (p - c));
	cout << "S = " << s << endl;
}
Triangle:: ~Triangle()
{
}