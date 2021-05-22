#ifndef CL_BASE_H
#define CL_BASE_H
#define SIGNAL_D(signal_f) (TYPE_SIGNAL) (&signal_f))
#define HENDLER_D(hendler_f) (TYPE_HANDLER) (&hendler_f))
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cl_base
{
protected:
    string name;
    cl_base* p_parent;
    int number;
    int readiness;
    vector <cl_base*> children;
    vector <string> m_coordinates;
    vector <string> links;
    typedef void (cl_base::* TYPE_SIGNAL) (string&);
    typedef void (cl_base::* TYPE_HANDLER) (string);
    struct o_sh
    {
        TYPE_SIGNAL p_signal;
        cl_base* p_cl_base;
        TYPE_HANDLER p_hendler;
    };
    vector <o_sh*> connects;
    vector <o_sh*>::iterator it;

public:
    cl_base(cl_base* p_parent);
    cl_base(cl_base* p_parent, string name, int number, int readiness);
    string get_object_name();
    ~cl_base();
    cl_base* search(string coordinates);
    bool test_for_uniqueness();
    void readiness_check();
    void showtree(int counter);
    cl_base* search_coordinates(string coordinates);
    void set_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_hendler);
    void delete_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_hendler);
    void emit_signal(TYPE_SIGNAL p_signal, string& s_command);
};

#endif