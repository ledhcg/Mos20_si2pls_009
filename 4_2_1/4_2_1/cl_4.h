#ifndef CL_4_H
#define CL_4_H

#include "cl_3.h"
#include <string>
using namespace std;

class cl_4 : public cl_3
{
public:
	cl_4(string nameObject);

private:
	int number = 4;
};


#endif // !CL_4_H