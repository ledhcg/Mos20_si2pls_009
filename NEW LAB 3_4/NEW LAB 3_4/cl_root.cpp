#include <iostream>
#include <string>
#include <vector>
#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_root.h"

using namespace std;

void cl_root::signal(string& a)
{
    cout << "Signal to " << a;
}
void cl_root::handler(string a)
{
    cout << " Text: ";
    return;
}

void cl_root::set_all()
{
    string name, parent = " ", coordinates;
    int number, readiness;
    cin >> name;
    cl_base* ob_root = new cl_base(0, name, 1, 1);
    pointer_of_root = ob_root;
    while (parent != "endtree")
    {
        cin >> parent;
        if (parent == "endtree")
            break;
        cin >> name >> number >> readiness;
        cl_base* dad = pointer_of_root->search(parent);
        switch (number)
        {
        case 1:
        {
            cl_base* ob_1 = new cl_1(dad, name, number, readiness);
            break;
        }
        case 2:
        {
            cl_base* ob_2 = new cl_2(dad, name, number, readiness);
            break;
        }
        case 3:
        {
            cl_base* ob_3 = new cl_3(dad, name, number, readiness);
            break;
        }
        }
    }
    string number1; string first, second;
    cl_base* from = nullptr;
    cl_base* to = nullptr;
    cin >> number1;
    while (number1 != "0")
    {
        cin >> first >> second;
        links.push_back(number1);
        links.push_back(first);
        links.push_back(second);
        from = pointer_of_root->search(first);
        to = pointer_of_root->search(second);
        if (from != nullptr)
        {
            from->set_connect(SIGNAL_D(from->signal), to, HENDLER_D(to->handler));
        }
        cin >> number1;
    }
}

int cl_root::exec_app()
{
    pointer_of_root->showtree(0);
    cout << endl << "Set connects";
    for (int i = 0; i < links.size(); i += 3)
    {
        cout << endl;
        cout << links[i] << " " << links[i + 1] << " " << links[i + 2];
    }
    cout << endl << "Emit signals";