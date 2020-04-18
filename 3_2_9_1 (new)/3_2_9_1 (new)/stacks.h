#include <string>
using namespace std;
#ifndef STACKS
#define STACKS
#define MAX 100
class stacks
{
public:
	int top = -1;
	string nameStack;
	int capacity;
	int stack[MAX];
	stacks(string nameStack, int capacity);
	~stacks();
	bool isFull();
	bool isEmpty();
	bool push(int value);
	bool peek();
	string getNameStack();
	int getCapacity();
	int getSize();
};
#endif // !STACKS

