

#ifndef OBJECT_A
#define OBJECT_A
class ObjectB;
class ObjectA
{
public:
	ObjectA(int j);
	~ObjectA();
	friend void max_object(ObjectA obA, ObjectB obB);

private:
	int a;
};
#endif // !OBJECT_A

