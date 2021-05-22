#ifndef CL_2_H
#define CL_2_H
#include "cl_base.h"

class cl_2 : public cl_base
{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
};

#endif