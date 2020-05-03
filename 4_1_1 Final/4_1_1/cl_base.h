#ifndef CL_BASE_H

#define CL_BASE_H



#include <iostream>

#include <string>

#include <vector>



using namespace std;



class cl_base

{

public:

    cl_base(cl_base* p_parent = 0);



    void set_object_name(string object_name);

    string get_object_name(cl_base* p_parent);

    void set_parent(cl_base* p_parent);

    void add_child(cl_base* p_child);

    cl_base* get_child(string object_name);


    



    vector < cl_base* > children;  

    vector < cl_base* > ::iterator it_child;



private:

    string  object_name;       

    cl_base* p_parent;         


};



#endif // CL_BASE_H