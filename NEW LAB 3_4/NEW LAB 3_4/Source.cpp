#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
#include "cl_root.h"
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"

using namespace std;

int main()
{
    cl_root ob_root(NULL);
    ob_root.set_all();
    return ob_root.exec_app();
}