#include "cl_application.h" 

using namespace std;

cl_application :: cl_application (string name ){ 
	set_object_name (name); 
} 

void cl_application :: bild_tree_objects (){                                  

	cl_2* ob_2;
	string nameParent, nameChild;

	while (true) {
		cin >> nameParent;
		cin >> nameChild;
		if (nameParent != nameChild) {
			if (this->get_object_name() == nameParent) {
				ob_2 = new cl_2((cl_base*)this);
				ob_2->set_object_name(nameChild);

			}
			else {
				for (size_t i = 0; i < children.size(); i++) {
					if (children.at(i)->get_object_name() == nameParent) {
						ob_2 = new cl_2((cl_base*)children.at(i));
						ob_2->set_object_name(nameChild);

					}
				}
			}

		}
		else {
			break;
		}
			
	}
} 

	int cl_application::exec_app() {
		show_object_state();
		return 0;
	}

	void cl_application::show_object_state() {
		cout << this->get_object_name();
		show_state_next(this);
	}

	void cl_application::show_child(cl_base* ob_parent) {
		cout << " " << ob_parent->get_object_name();
	}

	void cl_application::show_state_next(cl_base * ob_parent) {
	
		if (ob_parent->children.size() == 0)
			return;
		cout << endl;
		cout << ob_parent->get_object_name();
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