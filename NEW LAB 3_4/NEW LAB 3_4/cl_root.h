#ifndef CL_ROOT_H
#define CL_ROOT_H
#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"

using namespace std;

class cl_root : public cl_base
{
private:
    cl_base* pointer_of_root = NULL;
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
    void set_all();
    int exec_app();
};

#endif