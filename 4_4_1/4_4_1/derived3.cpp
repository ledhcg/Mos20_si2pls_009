#include "derived3.h"
#include <iostream>
#include <iomanip>
using namespace std;
void derived3::in_out() {
	cout << "Array dimension: " << size << endl;
	cout << "The original array:";
	for (int i = 0; i < size; i++) {
		cout << setw(5) << arr[i];
	}
	cout << endl;
	cout << "Min: " << derived::func() << endl;
	cout << "Sum: " << derived2::func();

}