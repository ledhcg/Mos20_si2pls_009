#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 10


Array::Array() {
		n = 1;
		a[0] = { 0 };
}
Array::~Array() {}
	//void Array::scanArr() {
	//	int x;
	//	char y;
	//	n = 0;
	//	while (cin >> x)
	//	{
	//		a[n++] = x;
	//	}
	//}
	void Array::inputArr(int k)
	{
		this->n = k;
		for (int i = 0; i < n; i++)
			cin >> a[i];

	}
	//void Array::printArr() {
	//	for (int i = 0; i < n; i++)
	//		cout << a[i] << " ";
	//	cout << endl;
	//}
	void Array::printArr(int k)
	{
		cout << left;
		for (int i = 0; i < n; i++)
			if (i != n - 1)
				cout << setw(k) << a[i] << left;
			else
				cout << a[i];
	}
	/*void Array::quantityOfArr() {
		cout << "N = " << n << endl;
	}*/
	void Array::invertArr() {
		int* b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = a[n - 1 - i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		delete[] b;
	}
