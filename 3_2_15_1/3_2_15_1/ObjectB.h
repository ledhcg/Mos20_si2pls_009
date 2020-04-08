#ifndef OBJECT_B
#define OBJECT_B

class ObjectA;
class ObjectB
{
public:
	ObjectB();
	~ObjectB();
	void getInput(int m, int n);
	friend void max_object(ObjectA obA, ObjectB obB);

private:
	int x, y;
};
#endif // !OBJECT_B

