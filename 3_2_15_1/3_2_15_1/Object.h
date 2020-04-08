#ifndef OBJECT
#define OBJECT


class Object2;

class Object1
{
private:
	int a;
public:
	Object1(int j);
	friend void max_object(Object1, Object2);
	~Object1();
};

class Object2
{
private:
	int x, y;
public:
	Object2();
	friend void max_object(Object1, Object2);
	~Object2();

};

#endif //! OBJECT 