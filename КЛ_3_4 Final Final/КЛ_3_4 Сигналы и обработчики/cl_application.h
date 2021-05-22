#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include "cl_base.h"
class cl_application : public cl_base {
public:
    cl_application(string name);
    void bild_tree_objects();
    int exec_app();
    void show_object_state();
    void addNewChild(cl_base* ob_parent, string nameParent, string nameChild, int state, int selectFamily);
    //START NEW 3.4
    void scanConnects(cl_base* ob_parent);
    void scanSignals(cl_base* ob_parent);
    void printConnects(cl_base* ob_parent);
    void printInfoWithMessage(cl_base* ob_parent);
    void returnMessage(cl_base* ob_parent, string sender, string message);
    //END NEW 3.4
private:
    void show_state_next(cl_base* ob_parent, int i);
};

#endif // CL_APPLICATION_H