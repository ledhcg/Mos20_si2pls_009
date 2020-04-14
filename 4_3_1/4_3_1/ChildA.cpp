#include "ChildA.h"
#include "superClass.h"
#include <iostream>
using namespace std;


void ChildA::getSize() {
	int size;
	cin >> size;
	if (size < 1 || size > 100)
		return getSize();
	else
	size = sizeOfArray;
}
