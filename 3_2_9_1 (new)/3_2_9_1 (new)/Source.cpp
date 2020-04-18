#include "stacks.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main() {
	string nameStack1;
	int capacity1;
	cin >> nameStack1 >> capacity1;
	stacks stack1 = stacks(nameStack1, capacity1);
	string nameStack2;
	int capacity2;
	cin >> nameStack2 >> capacity2;
	stacks stack2 = stacks(nameStack2, capacity2);
	while (stack1.isFull() != false) {
		int value;
		cin >> value;
		stack1.push(value);
	};
	while (stack2.isFull() != false) {
		int value;
		cin >> value;
		stack2.push(value);
	};

	cout << setw(15) << left << stack1.getNameStack() << setw(15) << left << stack2.getNameStack() << endl;
	return 0;
}