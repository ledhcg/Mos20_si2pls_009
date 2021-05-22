#include <iostream>
#include <string>
#include "cl_3.h"

void cl_3::signal(string& a)
{
    cout << "Signal to " << a;
}
void cl_3::handler(string a)
{
    cout << " Text: ";
    return;
}