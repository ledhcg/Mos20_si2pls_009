#include "cl_base.h" 

cl_base::cl_base(cl_base* p_parent)
{

	set_object_name("cl_base");
	if (p_parent) {
		this->p_parent = p_parent;
		p_parent->add_child(this);
	}
	else {
		this->p_parent = 0;
	}
}
void cl_base::set_object_name(string object_name) {

	this->object_name = object_name;
}
string cl_base::get_object_name() {

	return object_name;
}
void cl_base::set_parent(cl_base* p_parent) {
	if (p_parent) {
		this->p_parent = p_parent;
		p_parent->add_child(this);
	}
}
void cl_base::add_child(cl_base* p_child) {

	children.push_back(p_child);
}


cl_base* cl_base::get_child(string object_name) {

	if (children.size() == 0) return 0;
	it_child = children.begin();
	while (it_child != children.end()) {
		if ((*it_child)->get_object_name() == object_name) {
			return (*it_child);
		}
		it_child++;
	}
	return 0;
}



void cl_base::set_state(int c_state) {
	this->c_state = c_state;
}
int cl_base::get_state() {

	return c_state;
}