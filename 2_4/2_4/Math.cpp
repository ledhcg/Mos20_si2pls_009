#include "Math.h"
#include <iostream>
using namespace std;

Math::Math() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	total = 0;
}
Math::~Math() {
}
int Math::Calculate(char k, int x, int y) {

	if (k == '+')
		return x + y;
	if (k == '-')
		return x - y;
	if (k == '*')
		return x * y;
	if (k == '%')
		return x % y;
	return 0;
}
int Math::math1() {
	int x, y;
	char k;
	cin >> x >> k >> y;
	this->a = x;
	this->b = y;

	return Calculate(k, a, b);
}
int Math::math2(int m) {
	int y;
	char k;
	cin >> k >> y;
	this->c = y;
	return Calculate(k, m, c);
}
void Math::math3(int m) {
	int y;
	char k;
	cin >> k >> y;
	this->d = y;
	this->total = Calculate(k, m, d);
}
void Math::printMath() {
	cout << total;
}