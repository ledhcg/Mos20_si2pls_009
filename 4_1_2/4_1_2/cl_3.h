#ifndef CL_3_H
#define CL_3_H

#include "cl_2.h"
#include <string>
using namespace std;

class cl_3 : public cl_2
{
public:
	cl_3(string nameObject, int num);

private:
	int number = 3;
};


#endif // !CL_3_H