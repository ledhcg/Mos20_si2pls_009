#include <iostream>
#include "ObjectA.h"
#include "ObjectB.h"
using namespace std;

void max_object(ObjectA obA, ObjectB obB) {
	int max = obB.x;
	if (max < obB.y)
		max = obB.y;
	if (max < obA.a)
		max = obA.a;
	cout << "max = " << max;
}


int main() {
	int j, m, n;
	cin >> j;
	ObjectA o1 = ObjectA(j);
	cin >> m >> n;
	ObjectB o2;
	o2.getInput(m, n);
	max_object(o1, o2);
}