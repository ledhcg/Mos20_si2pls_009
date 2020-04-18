#include <string>
using namespace std;
#ifndef STACKS
#define STACKS
#define MAX 100

class stacks
{
private:
	int top = -1;
	string nameStack;
	int capacity;
	int stack[MAX];

public:
	stacks(string nameStack, int capacity);
	~stacks();
	bool isFull();
	bool isEmpty();
	bool push(int value);
	bool peek();
	void showStack(int i);
	string getNameStack();
	int getCapacity();
	int getSize();
};
#endif // !STACKS
