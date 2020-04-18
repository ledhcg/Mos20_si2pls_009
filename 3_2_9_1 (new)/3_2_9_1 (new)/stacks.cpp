#include "stacks.h"
#include <string>
using namespace std;
stacks::stacks(string nameStack, int capacity) {
	this->capacity = capacity;
	this->nameStack = nameStack;
}
bool stacks::isFull() {
	if (top >= capacity - 1) {
		return true;
	}
	else {
		return false;
	}
}
bool stacks::isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}
}
bool stacks::push(int value) {
	if (isFull()) {
		return false;
	}
	else {
		++top;
		stack[top] = value;
		return true;
	}
}
bool stacks::peek() {
	if (isEmpty() == false) {
		return true;
	}
	else {
		return false;
	}
}
string stacks::getNameStack() {
	return nameStack;
}
int stacks::getCapacity() {
	return capacity;
}
int stacks::getSize() {
	return top + 1;
};
