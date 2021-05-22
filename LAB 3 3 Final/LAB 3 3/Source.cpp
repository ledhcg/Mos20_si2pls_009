#include <iostream>
using namespace std;

#include "cl_application.h"

int main()
{
    string name;
    cin >> name;

    cl_application  ob_application(name);
   

    ob_application.bild_tree_objects();
    cout << "Object tree";

    return ob_application.exec_app();
}
