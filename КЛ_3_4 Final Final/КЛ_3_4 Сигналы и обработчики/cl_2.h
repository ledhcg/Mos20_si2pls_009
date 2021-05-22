#ifndef CL_2_H
#define CL_2_H

#include "cl_base.h" 

class cl_2 : public cl_base {
public:
    cl_2(cl_base* p_parent = 0);
    cl_2(cl_base* p_parent, bool infoSender, bool strorageMess);
    cl_2(cl_base* p_parent, bool id);
};

#endif // CL_2_H

