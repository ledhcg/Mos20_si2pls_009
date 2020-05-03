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
	
	


	while (true) {
		
			int value;
			cin >> value;
			if (stack1.isFull() == false)
				stack1.push(value);
			else
				break;
			if (stack2.isFull() == false)
				stack2.push(value);
			else
				break;

	};
	 
	cout << stack1.getNameStack() << " " << stack1.getCapacity() << endl;
	cout << stack2.getNameStack() << " " << stack2.getCapacity() << endl;

	cout << setw(15) << left << stack1.getNameStack() << setw(15) << left << stack2.getNameStack();
	int distance = capacity1 - capacity2;
	if (distance <= 0) {
		for (int i = capacity1 - 1; i >= 0; i--) {
			cout << endl;
			stack1.showStack(i);
			stack2.showStack(i);
		};
	}
	else {
		for (int i = capacity2; i >= 0; i--) {
			cout << endl;
			stack1.showStack(i);
			stack2.showStack(i-1);
		};
	}
	
	return 0;
}