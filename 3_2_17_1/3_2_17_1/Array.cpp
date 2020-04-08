#include "Array.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Arr::Arr(int *a) {
	cin >> number;
	if (number >= 5 && number <= 20) {
		for (int i = 0; i < number; i++) {
			a[i] = pow(i, 2);
		}
	}
	else
	{
		number = 0;
	}
}
void Arr::printReverseElement(int *a) {
	for (int i = number-1; i >=0; i--) {
		cout << setw(5) << a[i];
	}
}
Arr::~Arr() {
}
