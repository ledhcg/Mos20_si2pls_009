#include <iostream>
#include <iomanip>
#include "derived2.h"
using namespace std;

void derived2::exchangeSort() {

		int temp;
		for (int i = 0; i < (size - 1); i++)
		{
			for (int j = (i + 1); j < size; j++)
			{
				if (arr[i] > arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}

}

void derived2::printArr() {
	for (int i = 0; i < size; i++)
		cout << setw(5) << arr[i];
}