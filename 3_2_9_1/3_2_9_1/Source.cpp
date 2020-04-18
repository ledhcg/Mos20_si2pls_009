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
	
	


	while (stack1.isFull() == false || stack2.isFull() == false) {
		
			int value;
			cin >> value;
			stack1.push(value);
			stack2.push(value);

	};
	 
	cout << stack1.getNameStack() << " " << stack1.getSize() << endl;
	cout << stack2.getNameStack() << " " << stack2.getSize() << endl;

	cout << setw(15) << left << stack1.getNameStack() << setw(15) << left << stack2.getNameStack() << endl;
	int distance = capacity1 - capacity2;
	if (distance >= 0) {
		for (int i = capacity1 - 1; i >= 0; i--) {
			stack1.showStack(i);
			stack2.showStack(i-distance);
			cout << endl;
		};
	}
	else {
		for (int i = capacity2 - 1; i >= 0; i--) {
			stack1.showStack(i+distance);
			stack2.showStack(i);
			cout << endl;
		};
	}
	


	return 0;
}