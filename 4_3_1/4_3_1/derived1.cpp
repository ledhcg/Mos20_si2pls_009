#include <iostream>
#include "derived1.h"
using namespace std;

void derived1::getArr() {
	cin >> size;
	if (size < 1 || size > 100)
		return getArr();
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

