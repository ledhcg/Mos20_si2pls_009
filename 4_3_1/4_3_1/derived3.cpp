#include "derived3.h"
#include <iostream>
using namespace std;


void derived3::doIt() {
	getArr();
	cout << "Array dimension: "<< size << endl;
	cout << "The original array: ";
	printArr();
	cout << endl;
	exchangeSort();
	cout << "An ordered array: ";
	printArr();
}