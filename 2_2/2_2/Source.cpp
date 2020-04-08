#include <iostream>
#include "Array.h"
#include <iomanip>
using namespace std;

//#define MAX 10
//
//class Arr {
//private:
//	int a[MAX];
//	int n;
//public:
//	Arr(){
//		n = 0;
//	}
//	~Arr(){}
//	void inputArr() {
//		int x;
//		n = 0;
//		while (cin >> x)
//		{
//			a[n++] = x;
//		}
//	}
//	void printArr() {
//		for (int i = 0; i < n; i++)
//			cout << a[i] << " ";
//		cout << endl;
//	}
//
//	void quantityOfArr() {
//		cout << "N = " << n << endl;
//	}
//	void invertArr() {
//		int* b = new int[n];
//		for (int i = 0; i < n; i++)
//			b[i] = a[n - 1 - i];
//		for (int i = 0; i < n; i++)
//			a[i] = b[i];
//		delete[] b;
//	}
//};
int main() {

	int n;
	cin >> n;
	Array a;
	a.inputArr(n);
	Array b = a;
	cout << "N = " << n  <<endl;
	a.printArr(5);
	b.invertArr();
	cout << endl;
    b.printArr(5);
	return 0;

}
