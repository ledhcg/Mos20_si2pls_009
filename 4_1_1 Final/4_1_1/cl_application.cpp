#include "cl_application.h" 

using namespace std;

cl_application :: cl_application (cl_base* ob_parent, string name ){
	this->set_object_name (name); 
} 

void cl_application :: bild_tree_objects (){                                  

	cl_2* ob_2;
	string nameParent, nameChild;

	while (true) {
		cin >> nameParent;
		cin >> nameChild;
		if (nameParent != nameChild) {
			if (get_object_name(this) == nameParent) {
				ob_2 = new cl_2((cl_base*)this);
				ob_2->set_object_name(nameChild);

			}
			else {
				add_new_child(this, nameParent, nameChild);
			}
		}
		else {
			break;
		}	
	}
} 

void cl_application::add_new_child(cl_base* ob_parent, string nameParent, string nameChild) {
	cl_2* ob_2;
	for (size_t i = 0; i < ob_parent->children.size(); i++) {
		if (get_object_name((cl_base*)ob_parent->children.at(i)) == nameParent) {
			ob_2 = new cl_2((cl_base*)ob_parent->children.at(i));
			ob_2->set_object_name(nameChild);
			return;
		}
	}
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
			add_new_child((*(ob_parent->it_child)), nameParent, nameChild);
			ob_parent->it_child++;
	}
}


	int cl_application::exec_app() {
		show_object_state();
		return 0;
	}

	void cl_application::show_object_state() {
		cout << get_object_name(this);
		show_state_next(this);
	}

	void cl_application::show_child(cl_base* ob_parent) {
		cout << "  " << get_object_name(ob_parent);
	}

	void cl_application::show_state_next(cl_base * ob_parent) {
	
		if (ob_parent->children.size() == 0)
			return;
		cout << endl;
		cout << get_object_name(ob_parent);

		ob_parent->it_child = ob_parent->children.begin();
		while (ob_parent->it_child != ob_parent->children.end()) {
			show_child((*(ob_parent->it_child))); 
			ob_parent->it_child++;
		}
		
		ob_parent->it_child = ob_parent->children.begin();
		while (ob_parent->it_child != ob_parent->children.end()) {
			show_state_next((*(ob_parent->it_child))); 
			ob_parent->it_child++;
		}
	}