#include "Math.h"
#include <iostream>
using namespace std;

Math::Math() {
	a = 0;
	b = 0;
	count = 0;
	total = 0;
	countMath = 0;
	arrTotal[0] = 0;
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
void Math::printMath() {
	for (int i = 0; i < count; i++) {
		if (i == count - 1)
			cout << arrTotal[i];
		else
			cout << arrTotal[i] << endl;
	}
	
}
void Math::math1() {
	int x, y;
	char k;
	cin >> x >> k >> y;
	this->a = x;
	this->b = y;
	total = Calculate(k, a, b);
	countMath++;
}

void Math::mathNext() {
	
	char k;
	cin >> k;
	if (k == 'C')
		printMath();
	else
	{
		int y;
		cin >> y;
		total = Calculate(k, total, y);
		countMath++;
		if (countMath % 3 == 0)
		{
			arrTotal[count] = total;
			count++;
		}
		mathNext();
	}
}
