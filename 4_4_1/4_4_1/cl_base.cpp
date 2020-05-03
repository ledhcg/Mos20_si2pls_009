#include "cl_base.h"
#include <iostream>
using namespace std;
void cl_base::in_out() {
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}