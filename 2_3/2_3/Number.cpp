#include "Number.h"
#include <iostream>
using namespace std;

Number::Number() {
	long long int x;
	cin >> x;
	this->a = x;
}
Number::~Number() {
}
void Number::numOfElements() {
	long long int temp = a;
	if (temp == 0)
		k = 1;
	else {
		while (temp != 0) {
			temp = temp / 10;
			k++;
		}
	}
}
void Number::printN() {
	cout << "n = " << a << endl;
}
void Number::printNOE() {
	cout << "N = " << k;
}
