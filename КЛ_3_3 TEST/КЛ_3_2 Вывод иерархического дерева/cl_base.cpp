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

cl_base::cl_base(cl_base* p_parent, bool checkLink) {
	set_object_name("cl_base");
	if (p_parent) {
		this->p_parent = p_parent;
		p_parent->addChildLink(this);
	}
	else {
		this->p_parent = 0;
	}
}
void cl_base::set_object_name(string object_name) {

	this->object_name = object_name;
}

string cl_base::get_object_name(cl_base* p_parent) {
	return p_parent->object_name;
}

//Start new 3.3 

void cl_base::setLinkName(string linkName) {
	this->linkName = linkName;
}
string cl_base::getLinkName(cl_base* p_parent) {
	return p_parent->linkName;
}
void cl_base::setCheckName(string checkName) {
	this->checkName = checkName;
}
string cl_base::getCheckName(cl_base* p_parent) {
	return p_parent->checkName;
}
void cl_base::setStateDo(bool stateDo) {
	this->stateDo = stateDo;
}
bool cl_base::getStateDo(cl_base* p_parent) {
	return p_parent->stateDo;
}

void cl_base::addChildLink(cl_base* p_child) {
	childrenLink.push_back(p_child);
}

//End new 3.3
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
		if (get_object_name((*it_child)) == object_name) {
			return (*it_child);
		}
		it_child++;
	}
	return 0;
}



void cl_base::set_state(int c_state) {
	this->c_state = c_state;
}

int cl_base::get_state(cl_base* p_parent) {
	return p_parent->c_state;
}

