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
			string text;
			text.push_back(check);
			text.push_back(checkNext);
			char charNext;
			charNext = getchar();
			while (charNext != '\n') {
				if (charNext != ' ') {
					text.push_back(charNext);
					charNext = getchar();
				}
				else
					break;
				
			}
			if (text == text_finish) {
				break;
			}
		}
		else {
			scanElementsX(checkNext, this);
		}
	}
	processAccess(this);
	
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
void cl_application::resultLink(cl_base* ob_parent) {
if (ob_parent->childrenLink.size() == 0) {
	return;
}
ob_parent->it_childLink = ob_parent->childrenLink.begin();
while (ob_parent->it_childLink != ob_parent->childrenLink.end()) {
	if (getStateDo((*(ob_parent->it_childLink)))) {
		cout << endl << getLinkName((*(ob_parent->it_childLink))) << " Object name: " << getCheckName((*(ob_parent->it_childLink)));
	}
	else {
		cout << endl << getLinkName((*(ob_parent->it_childLink))) << " Object not found";
	}
	ob_parent->it_childLink++;
}
}
void cl_application::processAccess(cl_base* ob_parent) {
	while (true) {
		string linkName;
		cin >> linkName;
		if (linkName == text_finish2) {
			break;
		}
		else {
			connectWithRoot(0, linkName, ob_parent, false);
		}
	}
}
void cl_application::connectWithRoot(int count, string linkName, cl_base* ob_parent, bool notFound) {

	cl_2* ob_2L;
	ob_2L = new cl_2((cl_base*)ob_parent, true);
	ob_2L->setLinkName(linkName);
	ob_2L->setStateDo(false);


	if (linkName[count] == '/') {
		count++;
		string name;
		while (linkName[count] != '/') {
			name.push_back(linkName[count]);
			if (count == (linkName.size() - 1)) {
				break;
			}
			else
				count++;
		}

		if (linkName[count] == '/') { 
			// Tan cung sau khi quet = '/'
			if (name.size() == 0) {
				// Ten bi trong : VD: //jhkjnkjnkjnk
				if (checkMember(ob_parent)) {
					//Neu van con phan tu con =>
					count++;
					string name;
					while (linkName[count] != '/') {
						name.push_back(linkName[count]);
						if (count == (linkName.size() - 1)) {
							break;
						}
						else
							count++;
					}
					if (checkMemberDeep(this, name)) {
						if (getStateDo((cl_2*)ob_2L) == false) {
							ob_2L->setCheckName(name);
							ob_2L->setStateDo(true);
						}
					}
				}
				else {
					//Khong con phan tu con => false
				}

			}
			else {
				// co ten : VD: /hbjbhj/jkjnkn
				if (name == get_object_name(ob_parent)) {
					if (checkMember(ob_parent)) {
						//Neu van con phan tu con =>
						ob_parent->it_child = ob_parent->children.begin();
						while (ob_parent->it_child != ob_parent->children.end()) {
							connectAccess(count, linkName, ob_2L, (*(ob_parent->it_child)));
							ob_parent->it_child++;
						}
					}
					else {
						//Khong con phan tu con => false
					}
				}
				else {
					// khong bang ten == root -> vd root, link /rdssd/hbjb => false
				}
			}
		}
		else {
			//Tan cung sau khi quet la mot chu
			if (name == get_object_name(ob_parent)) {
				//neu tu cuoi day = voi vi tri con tro
				if (getStateDo((cl_2*)ob_2L) == false) {
					ob_2L->setCheckName(name);
					ob_2L->setStateDo(true);
				}
			}
			else {
				//tu cuoi day khong bang voi vi tri con tro => false
			}
		}
	}
	else {
		// VD: root/hnkj/jnkjn - Vi pham -> false
	}
	
	/*cout << "check state: " << getStateDo((cl_2*)ob_2L) << endl;
	if (getStateDo((cl_2*)ob_2L) == false) {
		ob_2L->setCheckName("k");
		ob_2L->setStateDo(true);
	}*/
	//
	//ob_2L->setCheckName("test");
	//ob_2L->setStateDo(true);
	////
	//ob_2L->setCheckName("em");
	//ob_2L->setStateDo(true);
}
void cl_application::connectAccess(int count, string linkName, cl_2* ob_2L, cl_base* ob_parent) {
	count++;
	string name;
	while (linkName[count] != '/') {
		name.push_back(linkName[count]);
		if (count == (linkName.size() - 1)) {
			break;
		}
		else
			count++;
	}

	if (linkName[count] == '/') {
		// Tan cung sau khi quet = '/'
		if (name.size() == 0) {
			// Ten bi trong : VD: //jhkjnkjnkjnk
			if (checkMember(ob_parent)) {
				//Neu van con phan tu con =>
				count++;
				string name;
				while (linkName[count] != '/') {
					name.push_back(linkName[count]);
					if (count == (linkName.size() - 1)) {
						break;
					}
					else
						count++;
				}
				if (checkMemberDeep(this, name)) {
					if (getStateDo((cl_2*)ob_2L) == false) {
						ob_2L->setCheckName(name);
						ob_2L->setStateDo(true);
					}
				}
			}
			else {
				//Khong con phan tu con => false
			}

		}
		else {
			// co ten : VD: /hbjbhj/jkjnkn
			if (name == get_object_name(ob_parent)) {
				if (checkMember(ob_parent)) {
					//Neu van con phan tu con =>
					ob_parent->it_child = ob_parent->children.begin();
					while (ob_parent->it_child != ob_parent->children.end()) {
						connectAccess(count, linkName, ob_2L, (*(ob_parent->it_child)));
						ob_parent->it_child++;
					}
				}
				else {
					//Khong con phan tu con => false
				}
			}
			else {
				// khong bang ten == root -> vd root, link /rdssd/hbjb => false
			}
		}
	}
	else {
		//Tan cung sau khi quet la mot chu
		if (name == get_object_name(ob_parent)) {
			//neu tu cuoi day = voi vi tri con tro
			if (getStateDo((cl_2*)ob_2L) == false) {
				ob_2L->setCheckName(name);
				ob_2L->setStateDo(true);
			}
		}
		else {
			//tu cuoi day khong bang voi vi tri con tro => false
		}
	}
}
bool cl_application::checkMemberDeep(cl_base* ob_parent, string name) {
	bool result = false;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		if (name == get_object_name(*(ob_parent->it_child))) {
			result = true;
		}
		if (checkMemberDeep((*(ob_parent->it_child)), name)) {
			result = true;
		}
		ob_parent->it_child++;
	}
	return result;
}
bool cl_application::checkMember(cl_base* ob_parent) {
	if (ob_parent->children.size() == 0) {
		return false;
	} else
		return true;
}


int cl_application::exec_app() {
	show_object_state();
	
	return 0;
}

void cl_application::show_object_state() {
	show_state_next(this, 0);
	resultLink(this);
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
