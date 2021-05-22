#ifndef CL_1_H
#define CL_1_H
#include "cl_base.h"

class cl_1 : public cl_base
{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
};

#endif