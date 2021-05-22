#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_base.h"


class cl_application : public cl_base {

public:
	cl_application();
	void buildFile();
	void createNewFile();
	void scanPosition();
	int exec_app();
	
private:
	cl_base toDo;
	void printToScreen();
};

#endif // !CL_APPLICATION_H