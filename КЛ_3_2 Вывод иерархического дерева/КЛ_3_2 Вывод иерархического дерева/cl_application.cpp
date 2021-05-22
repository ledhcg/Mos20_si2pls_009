#include "cl_application.h" 
#include <iomanip>
using namespace std;

cl_application::cl_application(string name) {
	set_object_name(name);
	set_state(1);
}

void cl_application::bild_tree_objects() {

	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	cl_5* ob_5;
	cl_6* ob_6;
	string nameParent, nameChild;
	int selectFamily;
	int state;

	while (true) {
		cin >> nameParent;
		if (nameParent == text_finish)
			break;
		cin >> nameChild >> selectFamily >> state;
		if (selectFamily == 2) {
			if (get_object_name(this) == nameParent) {
				ob_2 = new cl_2((cl_base*)this);
				ob_2->set_object_name(nameChild);
				ob_2->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily);
			}

		}
		else if (selectFamily == 3) {

			if (get_object_name(this) == nameParent) {
				ob_3 = new cl_3((cl_base*)this);
				ob_3->set_object_name(nameChild);
				ob_3->set_state(state);

			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily);
			}

		}
		else if (selectFamily == 4) {

			if (get_object_name(this) == nameParent) {
				ob_4 = new cl_4((cl_base*)this);
				ob_4->set_object_name(nameChild);
				ob_4->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily);
			}
		}
		else if (selectFamily == 5) {

			if (get_object_name(this) == nameParent) {
				ob_5 = new cl_5((cl_base*)this);
				ob_5->set_object_name(nameChild);
				ob_5->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily);
			}
		}
		else if (selectFamily == 6) {

			if (get_object_name(this) == nameParent) {
				ob_6 = new cl_6((cl_base*)this);
				ob_6->set_object_name(nameChild);
				ob_6->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily);
			}
		}
		else
			break;
	};
}
void cl_application::addNewChild(cl_base* ob_parent, string nameParent, string nameChild, int state, int selectFamily) {
	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	cl_5* ob_5;
	cl_6* ob_6;



	//Test
	cl_6 a = new cl_base(this);




	if (selectFamily == 2) {
	for (size_t i = 0; i < ob_parent->children.size(); i++) {
		if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
			ob_2 = new cl_2((cl_base*)ob_parent->children.at(i));
			ob_2->set_object_name(nameChild);
			if (get_state((cl_base*)ob_parent->children.at(i)) > 0) {
				ob_2->set_state(state);
			}
			else {
				ob_2->set_state(0);
			}
			return;
		}
	}
	}
	else if (selectFamily == 3) {
		for (size_t i = 0; i < ob_parent->children.size(); i++) {
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				ob_3 = new cl_3((cl_base*)ob_parent->children.at(i));
				ob_3->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) > 0) {
					ob_3->set_state(state);
				}
				else {
					ob_3->set_state(0);
				}
				return;
			}
		}
	}
	else if (selectFamily == 4) {
		for (size_t i = 0; i < ob_parent->children.size(); i++) {
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				ob_4 = new cl_4((cl_base*)ob_parent->children.at(i));
				ob_4->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) > 0) {
					ob_4->set_state(state);
				}
				else {
					ob_4->set_state(0);
				}
				return;
			}
		}
	}
	else if (selectFamily == 5) {
		for (size_t i = 0; i < ob_parent->children.size(); i++) {
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				ob_5 = new cl_5((cl_base*)ob_parent->children.at(i));
				ob_5->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) > 0) {
					ob_5->set_state(state);
				}
				else {
					ob_5->set_state(0);
				}
				return;
			}
		}
	}
	else if (selectFamily == 6) {
		for (size_t i = 0; i < ob_parent->children.size(); i++) {
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				ob_6 = new cl_6((cl_base*)ob_parent->children.at(i));
				ob_6->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) > 0) {
					ob_6->set_state(state);
				}
				else {
					ob_6->set_state(0);
				}
				return;
			}
		}
	}
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		addNewChild((*(ob_parent->it_child)), nameParent, nameChild, state, selectFamily); 
		ob_parent->it_child++;
	}
}
int cl_application::exec_app() {
	show_object_state();
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
		show_state_next((*(ob_parent->it_child)), i+1 ); ob_parent->it_child++;
	}
}