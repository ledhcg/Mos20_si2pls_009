#include <iostream>
#include <string>
#include "cl_2.h"

void cl_2::signal(string& a)
{
    cout << "Signal to " << a;
}
void cl_2::handler(string a)
{
    cout << " Text: ";
    return;
}