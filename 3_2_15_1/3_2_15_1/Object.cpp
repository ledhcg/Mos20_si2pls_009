#include "Object.h"
#include <iostream>
using namespace std;

Object1::Object1(int j) {
	this->a = j;
}
Object2::Object2() {
	cin >> x >> y;
}
void max_object(Object1 i, Object2 k) {
	int max = k.x;
	if (max < k.y)
		max = k.y;
	if (max < i.a)
		max = i.a;
	cout << "max = " << max;
}
Object1::~Object1() {
}
Object2::~Object2() {
}
