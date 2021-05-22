#include "stacks.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

stacks::stacks(string nameStack, int capacity) {
	this->capacity = capacity;
	this->nameStack = nameStack;
}
stacks::~stacks(){}
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
void stacks::showStack(int i) {
	if (i >= 0 && i < capacity) 
		cout << setw(15) << right << stack[i];
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
