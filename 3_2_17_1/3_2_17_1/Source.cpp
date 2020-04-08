#include "Array.h"
using namespace std;
#define MAX 20
int main() {
	int *a = new int[MAX];
	Arr arr1 = Arr(a);
	arr1.printReverseElement(a);
	delete[] a;
}