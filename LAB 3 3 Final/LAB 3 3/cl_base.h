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

    //New 3.3
    cl_base(cl_base* p_parent, bool checkLink);
    //

    void set_object_name(string object_name);

  
    string get_object_name(cl_base* p_parent);
    void set_parent(cl_base* p_parent);

    void add_child(cl_base* p_child);

    cl_base* get_child(string object_name);

    void set_state(int c_state);

    int get_state(cl_base* p_parent);






    //Start New 3.3
    void setLinkName(string linkName);
    string getLinkName(cl_base* p_parent);

    void setCheckName(string checkName);
    string getCheckName(cl_base* p_parent);

    void setStateDo(bool stateDo);
    bool getStateDo(cl_base* p_parent);
    void addChildLink(cl_base* p_child);

    vector < cl_base* > childrenLink;
    vector < cl_base* > ::iterator it_childLink;
    //End New 3.3


    vector < cl_base* > children;
    vector < cl_base* > ::iterator it_child;
    string text_finish = "endtree";
    string text_finish2 = "//";


private:

    //Start New 3.3
    string linkName;
    string checkName;
    bool stateDo;

    //End New 3.3

    string  object_name;
    cl_base* p_parent;

    int    c_state;




};



#endif // CL_BASE_H