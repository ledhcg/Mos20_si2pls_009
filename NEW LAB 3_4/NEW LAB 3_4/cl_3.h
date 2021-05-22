#ifndef CL_3_H
#define CL_3_H
#include "cl_base.h"

class cl_3 : public cl_base
{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
};

#endif