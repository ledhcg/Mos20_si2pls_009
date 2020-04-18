#include "cl_base.h"

class cl_application : public cl_base
{
public:
    cl_application();

    void bild_tree_objects();
    int  exec_app();

    void show_object_tree();

private:
    void show_object_next(cl_base* ob_parent, int i_level);
};
