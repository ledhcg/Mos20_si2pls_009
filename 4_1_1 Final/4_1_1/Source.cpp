#include <iostream>
using namespace std;
#include "cl_application.h"
cl_application* ob_start;
int main()
{
    string name;
    cin >> name;
    cl_application  ob_application(ob_start, name);

    ob_application.bild_tree_objects();

    return ob_application.exec_app();
}
