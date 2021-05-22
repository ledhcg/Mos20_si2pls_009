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

    //New 3.4
    void scanConnects(cl_base* ob_parent);
    

    void sendIDtoReceiver(cl_base* ob_parent, string receiver, int id);
    void nextSetID(cl_base* ob_parent, int id);

    void scanSignals(cl_base* ob_parent);


    void checkAndPrint(cl_base* ob_parent);
    // void nextPrintInfo(cl_base* ob_parent);
    void printInfoWithMessage(cl_base* ob_parent);
    void returnMessage(cl_base* ob_parent, string sender, string receiver);

private:

    void show_state_next(cl_base* ob_parent, int i);


};

#endif // CL_APPLICATION_H