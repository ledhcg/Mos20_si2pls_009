#include <iostream>
#include <string>
#include "cl_1.h"

void cl_1::signal(string& a)
{
    cout << "Signal to " << a;
}
void cl_1::handler(string a)
{
    cout << " Text: ";
    return;
}