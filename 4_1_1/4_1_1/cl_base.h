#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cl_base {
public:
    cl_base(cl_base* p_parent = 0);

    void      set_object_name(string    object_name);
    string    get_object_name();
    void      set_parent(cl_base* p_parent);
    void      add_child(cl_base* p_child);
    void      delete_child(string    object_name);
    cl_base* get_child(string    object_name);
    cl_base* get_object(string    object_path);

    vector < cl_base* > children;       // ссылки на потомков
    vector < cl_base* > ::iterator  it_child;
private:
    string       object_name;            // наименование объекта
    cl_base* p_parent;               // ссылка на головной объект
};
