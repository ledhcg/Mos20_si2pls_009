#include <iostream>
using namespace std;

#include "cl_application.h"

int main()
{
    cl_application file_application;

    file_application.buildFile();

    return file_application.exec_app();
}
