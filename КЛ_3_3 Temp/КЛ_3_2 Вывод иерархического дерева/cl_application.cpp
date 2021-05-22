#include "cl_application.h" 
#include <iomanip>
using namespace std;

cl_application::cl_application(string name) {
	set_object_name(name);
	set_state(1);
}

void cl_application::bild_tree_objects() {
	while (true)
	{
		char check, checkNext;
		cin >> check >> checkNext;

		if (check != '/') {
			if (scanTextFinish(check, checkNext)) {
				break;
			} break;
		}
		else {
			scanElementsX(checkNext, this);
		}
	}
}
bool cl_application::scanTextFinish(char check, char checkNext) {
	string text;
	text.push_back(check);
	text.push_back(checkNext);
	char charNext;
	charNext = getchar();
	while (charNext == '\n') {
		text.push_back(charNext);
		charNext = getchar();
	}
	if (text == text_finish) {
		return true;
	} 
}
void cl_application::scanElementsX(char nextChar, cl_base* ob_parent) {
	
	string ancestor;
	ancestor.push_back(nextChar);
	char charNext;
	charNext = getchar();
	while (charNext != '/') {
		if (charNext != ' ') {
			ancestor.push_back(charNext);
			charNext = getchar();
			
		}
		else break;
	}
	if (charNext == ' ') {
		addNewChild(this);
	}
	if (charNext == '/') {
		doWithChildLink(this);
	}
}
void cl_application::doWithChildLink(cl_base* ob_parent) {
	string ancestor;
	char charNext;
	charNext = getchar();
	while (charNext != '/') {
		if (charNext != ' ') {
			ancestor.push_back(charNext);
			charNext = getchar();

		}
		else break;
	}

	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		if (get_object_name((*(ob_parent->it_child))) == ancestor && charNext == '/') {
			doWithChildLink((*(ob_parent->it_child)));
			break;
		}
		if (get_object_name((*(ob_parent->it_child))) == ancestor && charNext == ' ') {
			addNewChild((*(ob_parent->it_child)));
			break;
		}
		ob_parent->it_child++;
	}
}
void cl_application::addNewChild(cl_base* ob_parent) {

	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	cl_5* ob_5;
	cl_6* ob_6;
	int selectFamily;
	int state;
	string nameObject;
	cin >> nameObject >> selectFamily >> state;

	if (selectFamily == 2) {
		ob_2 = new cl_2((cl_base*)ob_parent);
		ob_2->set_object_name(nameObject);
		ob_2->set_state(state);
	}
	else if (selectFamily == 3) {
		ob_3 = new cl_3((cl_base*)ob_parent);
		ob_3->set_object_name(nameObject);
		ob_3->set_state(state);
	} 
	else if (selectFamily == 4) {
		ob_4 = new cl_4((cl_base*)ob_parent);
		ob_4->set_object_name(nameObject);
		ob_4->set_state(state);
	} 
	else if (selectFamily == 5) {
		ob_5 = new cl_5((cl_base*)ob_parent);
		ob_5->set_object_name(nameObject);
		ob_5->set_state(state);
	}
	else if (selectFamily == 6) {
		ob_6 = new cl_6((cl_base*)ob_parent);
		ob_6->set_object_name(nameObject);
		ob_6->set_state(state);
	}
	else return;
}




int cl_application::exec_app() {
	show_object_state();
	extension(this);
	return 0;
}
void cl_application::show_object_state() {
	show_state_next(this, 0);
}
void cl_application::show_state_next(cl_base* ob_parent, int i) {
	if (i == 0) {
		cout << endl << get_object_name(ob_parent);
	}
	else {
		cout << endl << setw(4 * i) << " " << get_object_name(ob_parent);
	}


	if (ob_parent->children.size() == 0)
		return;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		show_state_next((*(ob_parent->it_child)), i + 1);
		ob_parent->it_child++;
	}
}
void cl_application::extension(cl_base* ob_parent) {

	if (ob_parent->children.size() == 0) {
		cout << endl << get_object_name(ob_parent) << " " << "Object not found";
		return;
	}
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		
		cout << endl << get_object_name(ob_parent) << " Object name: " << get_object_name((*(ob_parent->it_child)));
		extension((*(ob_parent->it_child)));
		ob_parent->it_child++;
	}

}