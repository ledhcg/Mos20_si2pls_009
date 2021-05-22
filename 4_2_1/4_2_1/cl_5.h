#ifndef CL_5_H
#define CL_5_H

#include "cl_4.h"
#include <string>
using namespace std;

class cl_5 : public cl_4
{
public:
	cl_5(string nameObject);

private:
	int number = 5;
};


#endif // !CL_5_H