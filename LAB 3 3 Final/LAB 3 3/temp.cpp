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
			}
			else {
				cout << "Error" << endl;
			}
		}
		else {
			scanElementsX(checkNext, this);
		}
	}
	processAccess(this);

}
bool cl_application::scanTextFinish(char check, char checkNext) {
	string text;
	text.push_back(check);
	text.push_back(checkNext);
	char charNext;
	charNext = getchar();
	while (charNext != '\n') {
		text.push_back(charNext);
		charNext = getchar();
	}
	cout << "Text check finish: " << text << endl;
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





void cl_application::scanLink(cl_base* ob_parent) {
	//cl_2* ob_2;
	//string linkName = "///jhd";
	//string checkName = "gdvj";
	//bool stateDo = true;
	//	ob_2 = new cl_2((cl_base*)ob_parent, true);
	//	ob_2->setLinkName(linkName);
	//	ob_2->setCheckName(checkName);
	//	ob_2->setStateDo(stateDo);

	//	cl_2* ob_2a;
	//	string linkNameA = "/cuong/jhbjd/jhd";
	//	string checkNameA = "cuong";
	//	bool stateDoA = true;
	//	ob_2a = new cl_2((cl_base*)ob_parent, true);
	//	ob_2a->setLinkName(linkNameA);
	//	ob_2a->setCheckName(checkNameA);
	//	ob_2a->setStateDo(stateDoA);




	cout << endl << "Test: " << endl;
	if (ob_parent->childrenLink.size() == 0) {
		cout << "Khong co ket qua" << endl;
		return;
	}
	ob_parent->it_childLink = ob_parent->childrenLink.begin();
	while (ob_parent->it_childLink != ob_parent->childrenLink.end()) {
		if (getStateDo((*(ob_parent->it_childLink)))) {
			cout << endl << "Link: " << getLinkName((*(ob_parent->it_childLink))) << " Object name: " << getCheckName((*(ob_parent->it_childLink)));
		}
		else {
			cout << endl << "Link: " << getLinkName((*(ob_parent->it_childLink))) << " Object not found";
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
	ob_2L->getStateDo(false);





	//cout << "check state: " << getStateDo((cl_2*)ob_2L) << endl;
	//ob_2L->setCheckName("test");
	//ob_2L->setStateDo(true);
	//
	//ob_2L->setCheckName("cuong");
	//ob_2L->setStateDo(true);


	/*
	if (linkName.size() == 1) { //ok
		cl_2* ob_2L;
		ob_2L = new cl_2((cl_base*)ob_parent, true);
		ob_2L->setLinkName(linkName);
		ob_2L->setStateDo(false);
		return;
	}
	if (linkName[count] == '/') { // Vij tri xuat phhat = /
		int i = count + 1;
		string name;
		while (linkName[i] != '/') {
			name.push_back(linkName[i]);
			if (i == (linkName.size() - 1)) {
				break;
			}
			else
				i++;
		}
		if (linkName[i] == '/') { //Neu sau khi quet ten = '/'
			if (i == (linkName.size() - 1)) { // vi tri '/' o cuoi cung
				cl_2* ob_2L;
				ob_2L = new cl_2((cl_base*)ob_parent, true);
				ob_2L->setLinkName(linkName);
				ob_2L->setStateDo(false);
				return;
			}
			else { // Quet ten bt - '/dfvs/' or '// hjsd'
				cout << name <<"**" << endl;
				if (name.size() == 0) {  //quet ten rong ///kjkj
					if (checkMember(ob_parent)) { //Co mem
						i++;
						string name;
						while (linkName[i] != '/') {
							name.push_back(linkName[i]);
							if (i == (linkName.size() - 1)) {
								break;
							}
							else
								i++;
						}
						cout << name << endl;
						bool checkResult = false;
						ob_parent->it_child = ob_parent->children.begin();
						while (ob_parent->it_child != ob_parent->children.end()) {
							cout << name << "?" << get_object_name((*(ob_parent->it_child))) << endl;
							if (name == get_object_name((*(ob_parent->it_child)))) {
								cout << "success" << endl;
								checkResult = true;
								connectAccess(i, linkName, name, (*(ob_parent->it_child)), false);
								break;
							}
							ob_parent->it_child++;
						}
						if (checkResult == false) {
							cl_2* ob_2a;
							ob_2a = new cl_2((cl_base*)ob_parent, true);
							ob_2a->setLinkName(linkName);
							ob_2a->setStateDo(false);
							return;
						}
					}
					else { // khong co mem
						cl_2* ob_2L;
						ob_2L = new cl_2((cl_base*)ob_parent, true);
						ob_2L->setLinkName(linkName);
						ob_2L->setStateDo(false);
						return;
					}
				}
				else {
					//co ten /gjhb/
					if (name == get_object_name(ob_parent)) {
						if (checkMember(ob_parent)) { //Co mem
							cout << "join" << endl;
							i++;
							string name;
							while (linkName[i] != '/') {
								name.push_back(linkName[i]);
								if (i == (linkName.size() - 1)) {
									break;
								}
								else
									i++;
							}
							bool checkResult = false;
							ob_parent->it_child = ob_parent->children.begin();
							while (ob_parent->it_child != ob_parent->children.end()) {
								if (name == get_object_name((*(ob_parent->it_child)))) {
									checkResult = true;
									//cout << "Success" << endl;
									connectAccess(i, linkName, name, (*(ob_parent->it_child)), false);
									return;
								}
								ob_parent->it_child++;
							}
							if (checkResult == false) {
								cl_2* ob_2a;
								ob_2a = new cl_2((cl_base*)ob_parent, true);
								ob_2a->setLinkName(linkName);
								ob_2a->setStateDo(false);
								return;
							}

						}
						else { // bang ten nhung khong co mem
							cl_2* ob_2L;
							ob_2L = new cl_2((cl_base*)ob_parent, true);
							ob_2L->setLinkName(linkName);
							ob_2L->setStateDo(false);
							return;
						}
					}
					else { //khong bang ob_parent
						cl_2* ob_2L;
						ob_2L = new cl_2((cl_base*)ob_parent, true);
						ob_2L->setLinkName(linkName);
						ob_2L->setStateDo(false);
						return;

					}
				}
			}
		}
		else { //Ney sau khi quet ten la mot chu cai vd : /gvhgvjhb
			if (name == get_object_name(ob_parent)) {
				cl_2* ob_2L;
				ob_2L = new cl_2((cl_base*)ob_parent, true);
				ob_2L->setLinkName(linkName);
				ob_2L->setCheckName(name);
				ob_2L->setStateDo(true);
				return;
			}
			else {
				cl_2* ob_2L;
				ob_2L = new cl_2((cl_base*)ob_parent, true);
				ob_2L->setLinkName(linkName);
				ob_2L->setStateDo(false);
				return;
			}
		}

	}
	else {
		cl_2* ob_2L;
		ob_2L = new cl_2((cl_base*)ob_parent, true);
		ob_2L->setLinkName(linkName);
		ob_2L->setStateDo(false);
		return;
	}

	*/

	//		
	//		if (linkName[i] == '/') {
	//			
	//			//truong hop ten bi rong vd : //abkkk
	//			if (name.size() == 0) {
	//				//Neu cothanh vien thi quet tiep
	//				if (checkMember(ob_parent)) {
	//					i++;
	//					string name;
	//					while (linkName[i] != '/') {
	//						name.push_back(linkName[i]);
	//						if (i == (linkName.size() - 1)) {
	//							break;
	//						}
	//						else
	//							i++;
	//					}
	//					cout << "check char 2: " << linkName[i] << endl;
	//					cout << name << "**" << endl;
	//					bool checkResult = false;
	//					ob_parent->it_child = ob_parent->children.begin();
	//					while (ob_parent->it_child != ob_parent->children.end()) {
	//						if (name == get_object_name((*(ob_parent->it_child)))) {
	//							checkResult = true;
	//							cout << "Success" << endl;
	//							connectAccess(i, linkName, name, (*(ob_parent->it_child)), false);
	//							break;
	//						}
	//						else {
	//							ob_parent->it_child++;
	//						}
	//					}
	//					if (checkResult == false) {
	//						cl_2* ob_2a;
	//						ob_2a = new cl_2((cl_base*)ob_parent, true);
	//						ob_2a->setLinkName(linkName);
	//						ob_2a->setStateDo(false);
	//						cout << "ABC2" << endl;
	//						return true;
	//					}
	//				}
	//				else { //ok
	//					//Link khong tim thay
	//					cl_2* ob_2a;
	//					ob_2a = new cl_2((cl_base*)ob_parent, true);
	//					ob_2a->setLinkName(linkName);
	//					ob_2a->setStateDo(false);
	//					cout << "ABC3" << endl;
	//					return true;
	//				}
	//				
	//			}
	//			//Truong hop ten co - vd : /jahj/
	//			else {
	//				//Kiem tra ten co giong nhu ten root khong
	//				if (name == get_object_name(ob_parent)) { 
	//					if (checkMember(ob_parent)) {
	//						i++;
	//						string name;
	//						while (linkName[i] != '/') {
	//							name.push_back(linkName[i]);
	//							if (i == (linkName.size() - 1)) {
	//								break;
	//							}
	//							else
	//								i++;
	//						}
	//						
	//						cout << "check char 2: " << linkName[i] << endl;
	//						cout << name << "**" << endl;
	//						bool checkResult = false;
	//						ob_parent->it_child = ob_parent->children.begin();
	//						while (ob_parent->it_child != ob_parent->children.end()) {
	//							if (name == get_object_name((*(ob_parent->it_child)))) {
	//								checkResult = true;
	//								cout << "Success" << endl;
	//								connectAccess(i, linkName, name, (*(ob_parent->it_child)), false);
	//								break;
	//							}
	//							else {
	//								ob_parent->it_child++;
	//							}
	//						}
	//						if (checkResult == false) {
	//							cl_2* ob_2a;
	//							ob_2a = new cl_2((cl_base*)ob_parent, true);
	//							ob_2a->setLinkName(linkName);
	//							ob_2a->setStateDo(false);
	//							cout << "ABC4" << endl;
	//							return true;
	//						}
	//					}
	//					else { //ok
	//						//Link khong tim thay - Khong co member; /root/<k ton tai>
	//						cl_2* ob_2a;
	//						ob_2a = new cl_2((cl_base*)ob_parent, true);
	//						ob_2a->setLinkName(linkName);
	//						ob_2a->setStateDo(false);
	//						cout << "ABC5" << endl;
	//						return true;
	//					}
	//				}
	//				else { //ok
	//					//Ten khong giong nhuw ten root
	//					//Link khong tim thay 
	//					cl_2* ob_2a;
	//					ob_2a = new cl_2((cl_base*)ob_parent, true);
	//					ob_2a->setLinkName(linkName);
	//					ob_2a->setStateDo(false);
	//					cout << "ABC6" << endl;
	//					return true;
	//				}
	//				
	//			}
	//		}
	//		else {
	//			// truong hop /root -> enter <chu cuoi cung la t>
	//			
	//				if (name == get_object_name(ob_parent)) { // ok
	//					cl_2* ob_2a;
	//					ob_2a = new cl_2((cl_base*)ob_parent, true);
	//					ob_2a->setLinkName(linkName);
	//					ob_2a->setCheckName(name);
	//					ob_2a->setStateDo(true);
	//					return true;
	//				}
	//				else { //ok
	//					cl_2* ob_2a;
	//					ob_2a = new cl_2((cl_base*)ob_parent, true);
	//					ob_2a->setLinkName(linkName);
	//					ob_2a->setStateDo(false);
	//					cout << "ABC7" << endl;
	//					return true;
	//				}
	//			
	//		}
	//		break;
	//	}
	//}
	//else {
	//
	//}
}
//			else {
//
//				cout << "Debug: Name: " << name << " name Object: " << get_object_name(ob_parent) << endl;
//				if (name == get_object_name(ob_parent)) {
//					if (name.size() == 0) {
//						cl_2* ob_2a;
//						ob_2a = new cl_2((cl_base*)ob_parent, true);
//						ob_2a->setLinkName(linkName);
//						ob_2a->setCheckName(name);
//						ob_2a->setStateDo(false);
//
//						cout << "Success with link: " << linkName << "; name: " << name << "; active: " << false << endl;
//						cout << "****" << endl;
//						return notify = true;
//					}
//					else {
//						if (notFound) {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(false);
//							cout << "Success with link: " << linkName << "; name: " << name << "; active: " << false << endl;
//							cout << "****" << endl;
//							return notify = true;
//						}
//						else {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(true);
//							cout << "Success with link: " << linkName << "; name: " << name << "; active: " << true << endl;
//							cout << "****" << endl;
//							return notify = true;
//						}
//					}
//				}
//				else {
//					if (name.size() == 0) {
//						cl_2* ob_2a;
//						ob_2a = new cl_2((cl_base*)ob_parent, true);
//						ob_2a->setLinkName(linkName);
//						ob_2a->setCheckName(name);
//						ob_2a->setStateDo(false);
//						cout << "Success with link: " << linkName << "; name: " << name << "; active: " << false << endl;
//						cout << "****" << endl;
//						return notify = true;
//					}
//					else {
//						if (notFound) {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(false);
//							cout << "Success with link: " << linkName << "; name: " << name << "; active: " << false << endl;
//							cout << "****" << endl;
//							return notify = true;
//						}
//						else {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(false);
//							cout << "Success with link: " << linkName << "; name: " << name << "; active: " << false << endl;
//							cout << "****" << endl;
//							return notify = true;
//						}
//					}
//
//				}
//			}
//			if (i < linkName.size()) {
//				i++;
//			}
//		}
//	}
//	else {
//		int i = count;
//
//		while (i < linkName.size()) {
//			string name;
//			while (linkName[i] != '/') {
//				name.push_back(linkName[i]);
//				if (i == (linkName.size() - 1)) {
//					break;
//				}
//				else
//					i++;
//			}
//			cout << "Debug i: " << linkName[i] << endl;
//
//			if (linkName[i] == '/') {
//				if (name.size() == 0) {
//					ob_parent->it_child = ob_parent->children.begin();
//					while (ob_parent->it_child != ob_parent->children.end()) {
//						if (connectAccess(i, linkName, (*(ob_parent->it_child)), false)) {
//							break;
//						}
//						else {
//							ob_parent->it_child++;
//						}
//					}
//				}
//				else {
//					if (name == get_object_name(ob_parent)) {
//						ob_parent->it_child = ob_parent->children.begin();
//						while (ob_parent->it_child != ob_parent->children.end()) {
//							if (connectAccess(i, linkName, (*(ob_parent->it_child)), false)) {
//								break;
//							}
//							else {
//								ob_parent->it_child++;
//							}
//						}
//					}
//				}
//			}
//			else {
//				if (name.size() == 0) {
//					cl_2* ob_2a;
//					ob_2a = new cl_2((cl_base*)ob_parent, true);
//					ob_2a->setLinkName(linkName);
//					ob_2a->setCheckName(name);
//					ob_2a->setStateDo(false);
//					return notify = true;
//				}
//				else {
//					if (name == get_object_name(ob_parent)) {
//						if (name.size() == 0) {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(false);
//							return notify = true;
//						}
//						else {
//							if (notFound) {
//								cl_2* ob_2a;
//								ob_2a = new cl_2((cl_base*)ob_parent, true);
//								ob_2a->setLinkName(linkName);
//								ob_2a->setCheckName(name);
//								ob_2a->setStateDo(false);
//								return notify = true;
//							}
//							else {
//								cl_2* ob_2a;
//								ob_2a = new cl_2((cl_base*)ob_parent, true);
//								ob_2a->setLinkName(linkName);
//								ob_2a->setCheckName(name);
//								ob_2a->setStateDo(true);
//								return notify = true;
//							}
//						}
//					}
//					else {
//						if (name.size() == 0) {
//							cl_2* ob_2a;
//							ob_2a = new cl_2((cl_base*)ob_parent, true);
//							ob_2a->setLinkName(linkName);
//							ob_2a->setCheckName(name);
//							ob_2a->setStateDo(false);
//							return notify = true;
//						}
//						else {
//							if (notFound) {
//								cl_2* ob_2a;
//								ob_2a = new cl_2((cl_base*)ob_parent, true);
//								ob_2a->setLinkName(linkName);
//								ob_2a->setCheckName(name);
//								ob_2a->setStateDo(false);
//								return notify = true;
//							}
//							else {
//								cl_2* ob_2a;
//								ob_2a = new cl_2((cl_base*)ob_parent, true);
//								ob_2a->setLinkName(linkName);
//								ob_2a->setCheckName(name);
//								ob_2a->setStateDo(false);
//								return notify = true;
//							}
//						}
//
//					}
//				}
//			}
//			if (i < linkName.size()) {
//				i++;
//			}
//		}
//
//	}
//}

bool cl_application::connectAccess(int count, string linkName, string name, cl_base* ob_parent, bool notFound) {
	if (count == linkName.size() - 1) {
		cout << "Ok with :" << endl;
		if (name == get_object_name(ob_parent)) {
			cout << "Ok 1" << endl;
			cl_2* ob_2a;
			ob_2a = new cl_2((cl_base*)ob_parent, true);
			ob_2a->setLinkName(linkName);
			ob_2a->setCheckName(name);
			ob_2a->setStateDo(true);
			cout << "ABC8" << endl;
			return true;
		}
		else {
			cout << "Ok 2" << endl;
			cl_2* ob_2a;
			ob_2a = new cl_2((cl_base*)ob_parent, true);
			ob_2a->setLinkName(linkName);
			ob_2a->setStateDo(false);
			cout << "ABC9" << endl;
			return true;
		}
	}
}
bool cl_application::checkMember(cl_base* ob_parent) {
	if (ob_parent->children.size() == 0) {
		return false;
	}
	else
		return true;
}


int cl_application::exec_app() {
	show_object_state();

	return 0;
}

void cl_application::show_object_state() {
	show_state_next(this, 0);
	scanLink(this);
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