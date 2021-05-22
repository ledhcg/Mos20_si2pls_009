#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_base.h"

class cl_application : public cl_base {

public:

    cl_application(string name);
    void bild_tree_objects();
    int exec_app();
    void show_object_state();

private:

    void show_state_next(cl_base* ob_parent);


};

#endif // CL_APPLICATION_H