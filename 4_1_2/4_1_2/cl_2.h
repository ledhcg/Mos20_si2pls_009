#ifndef CL_2_H
#define CL_2_H

#include "cl_1.h"
#include <string>
using namespace std;

class cl_2 : public cl_1
{
public:
	cl_2(string nameObject, int num);

private:
	int number = 2;
};


#endif // !CL_2_H