#include "cl_application.h" 
using namespace std;

cl_application::cl_application(string name) {
	set_object_name(name);
	set_state(1);
}

void cl_application::bild_tree_objects() {

	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	string nameParent, nameChild;
	int selectFamily;
	int state;

	while (true) {
		cin >> nameParent;
		if (nameParent == text_finish)
			break;
		cin >> nameChild >> selectFamily >> state;
		if (selectFamily == 2) {
			if (this->get_object_name() == nameParent) {
				ob_2 = new cl_2((cl_base*)this);
				ob_2->set_object_name(nameChild);
				ob_2->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily, 0);
			}

		}
		else if (selectFamily == 3) {

			if (this->get_object_name() == nameParent) {
				ob_3 = new cl_3((cl_base*)this);
				ob_3->set_object_name(nameChild);
				ob_3->set_state(state);

			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily, 0);
			}

		}
		else if (selectFamily == 4) {

			if (this->get_object_name() == nameParent) {
				ob_4 = new cl_4((cl_base*)this);
				ob_4->set_object_name(nameChild);
				ob_4->set_state(state);
			}
			else {
				addNewChild(this, nameParent, nameChild, state, selectFamily, 0);
			}
		}
		else
			break;
	};
}
void cl_application::addNewChild(cl_base* ob_parent, string nameParent, string nameChild, int state, int selectFamily, int i) {
	cout << "Call back " << i << endl;
	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	if (selectFamily == 2) {
	for (size_t i = 0; i < ob_parent->children.size(); i++) {
		cout << get_object_name((cl_base*)ob_parent->children.at(i)) << "-" << nameParent << endl;
		if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
			cout << "Ok2" << endl;
			cout << "The " << i << "-" << selectFamily << " true." << endl;
			ob_2 = new cl_2((cl_base*)ob_parent->children.at(i));
			ob_2->set_object_name(nameChild);
			if (get_state((cl_base*)ob_parent->children.at(i)) == 1) {
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
			cout << get_object_name((cl_base*)ob_parent->children.at(i)) << "-" << nameParent << endl;
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				cout << "Ok3" << endl;
				cout << "The " << i << "-" << selectFamily << " true." << endl;
				ob_3 = new cl_3((cl_base*)ob_parent->children.at(i));
				ob_3->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) == 1) {
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
			cout << get_object_name((cl_base*)ob_parent->children.at(i)) << "-" << nameParent << endl;
			if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
				cout << "Ok4" << endl;
				cout << "The " << i << "-" << selectFamily << " true." << endl;
				ob_4 = new cl_4((cl_base*)ob_parent->children.at(i));
				ob_4->set_object_name(nameChild);
				if (get_state((cl_base*)ob_parent->children.at(i)) == 1) {
					ob_4->set_state(state);
				}
				else {
					ob_4->set_state(0);
				}
				return;
			}
		}
	}
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		cout << "join" << endl;
		addNewChild((*(ob_parent->it_child)), nameParent, nameChild, state, selectFamily, i+1); 
		ob_parent->it_child++;
	}
}
int cl_application::exec_app() {
	show_object_state();
	return 0;
}

void cl_application::show_object_state() {
	show_state_next(this);
}


void cl_application::show_state_next(cl_base* ob_parent) {
	if (ob_parent->get_state() == 0)
		return;
	else if (ob_parent->get_state() == 1) {
		cout << "The object " << ob_parent->get_object_name() << " is ready" << endl;
	}
	else if (ob_parent->get_state() == -1) {
		cout << "The object " << ob_parent->get_object_name() << " is not ready" << endl;
	}
	if (ob_parent->children.size() == 0)
		return;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		show_state_next((*(ob_parent->it_child))); ob_parent->it_child++;
	}
}