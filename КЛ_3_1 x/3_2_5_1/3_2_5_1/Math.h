#ifndef MATH
#define MATH

#define MAX 100

class Math
{
private:
	int a, b;
	int count;
	int total;
	int countMath;
	int arrTotal[MAX];
public:
	Math();
	~Math();
	int Calculate(char k, int x, int y);
	void printMath();
	void math1();
	void mathNext();

};
#endif // !MATH

