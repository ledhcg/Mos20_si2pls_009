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

//START NEW 3.4

cl_base::cl_base(cl_base* p_parent, bool infoSender, bool strorageMess)
{
	if (infoSender) {
		set_object_name("cl_base");
		if (p_parent) {
			this->p_parent = p_parent;
			p_parent->addChildInfoSender(this);
		}
		else {
			this->p_parent = 0;
		}
	}
	if (strorageMess) {
		set_object_name("cl_base");
		if (p_parent) {
			this->p_parent = p_parent;
			p_parent->addChildstorageMess(this);
		}
		else {
			this->p_parent = 0;
		}
	}
}
	

cl_base::cl_base(cl_base* p_parent, bool id)
{
		set_object_name("cl_base");
		if (p_parent) {
			this->p_parent = p_parent;
			p_parent->addChildInfoSender(this);
		}
		else {
			this->p_parent = 0;
		}
}

//END NEW 3.4



void cl_base::set_object_name(string object_name) {

	this->object_name = object_name;
}

string cl_base::get_object_name(cl_base* p_parent) {
	return p_parent->object_name;
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

//START NEW 3.4
void cl_base::setConnect SIGNALING {
	p_parent->setID(id);
	p_parent->setNameSender(nameSender);
	p_parent->setNameReceiver(nameReceiver);
}
void cl_base::deleteConnect() {

}
void cl_base::signaling HANDLING {
	p_parent->setNameSender(nameSender);
	p_parent->setMessageText(message);
}

void cl_base::setNameSender(string nameSender) {
	this->nameSender = nameSender;
}
string cl_base::getNameSender(cl_base* p_parent) {
	return p_parent->nameSender;
}

void cl_base::setNameReceiver(string nameReceiver) {
	this->nameReceiver = nameReceiver;
}
string cl_base::getNameReceiver(cl_base* p_parent) {
	return p_parent->nameReceiver;
}

void cl_base::setMessageText(string messageText) {
	this->messageText = messageText;
}
string cl_base::getMessageText(cl_base* p_parent) {
	return p_parent->messageText;
}

void cl_base::setID(int id) {
	this->id = id;
}
int cl_base::getID(cl_base* p_parent) {
	return p_parent->id;
}


void cl_base::addChildInfoSender(cl_base* p_child) {
	infoSender.push_back(p_child);
}
void cl_base::addChildstorageMess(cl_base* p_child) {
	storageMess.push_back(p_child);
}


//END NEW 3.4