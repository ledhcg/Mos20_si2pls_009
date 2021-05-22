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
		if (checkNext == '/') {
			break;
		}
		else {
		scanElementsX(checkNext, this);
		}
		
	}
			
	
}


void cl_application::scanElements(cl_base* ob_parent) {
	cout << "Father when scan: " << get_object_name((cl_base*)ob_parent) << endl;
	string ancestor;
	char checkNext;
	checkNext = getchar();// use getchar() cause can scan '\n' and ' '
	if (checkNext == '/') {
		return;
	}
	while (checkNext != '/') {
		if (checkNext != ' ') {
			ancestor.push_back(checkNext);
			checkNext = getchar();
		}
		else break;
	}
	cout << "Result ancestor: " << ancestor << endl;
	if (checkNext == ' ') {

		cl_2* ob_2;
		cl_3* ob_3;
		cl_4* ob_4;
		cl_5* ob_5;
		cl_6* ob_6;
		int selectFamily;
		int state;

		//Scan nameObject 
		string nameObject;
		cin >> nameObject >> selectFamily >> state;
		if (selectFamily == 2) {
			ob_2 = new cl_2((cl_base*)ob_parent);
			ob_2->set_object_name(nameObject);
			ob_2->set_state(state);

			//Debug
			//cout << "Success with 2" << endl;
			//cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_2) << endl;
		}
		return;
		// else if (selectFamily == 3) {
		//	ob_3 = new cl_3((cl_base*)ob_parent);
		//	ob_3->set_object_name(nameObject);
		//	ob_3->set_state(state);

		//	//Debug
		//	cout << "Success with 3" << endl;
		//	cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_3) << endl;
		//	return;
		//}
		//else if (selectFamily == 4) {
		//	ob_4 = new cl_4((cl_base*)ob_parent);
		//	ob_4->set_object_name(nameObject);
		//	ob_4->set_state(state);

		//	//Debug
		//	cout << "Success with 4" << endl;
		//	cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_4) << endl;
		//	return;
		//}
		//else if (selectFamily == 5) {
		//	ob_5 = new cl_5((cl_base*)ob_parent);
		//	ob_5->set_object_name(nameObject);
		//	ob_5->set_state(state);

		//	//Debug
		//	cout << "Success with 5" << endl;
		//	cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_5) << endl;
		//	return;
		//}
		//else if (selectFamily == 6) {
		//	ob_6 = new cl_6((cl_base*)ob_parent);
		//	ob_6->set_object_name(nameObject);
		//	ob_6->set_state(state);

		//	//Debug
		//	cout << "Success with 6" << endl;
		//	cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_6) << endl;
		//	return;
		//}
		//return;
	} else {
		ob_parent->it_child = ob_parent->children.begin();
		while (ob_parent->it_child != ob_parent->children.end()) {

			//Debug
			//cout << "Check name: " << get_object_name((*(ob_parent->it_child))) << " and " << ancestor << " and char:" << checkNext<< endl;
			if (get_object_name((*(ob_parent->it_child))) == ancestor) {
				scanElements((*(ob_parent->it_child)));
				break;
			}
			ob_parent->it_child++;
		}
	}

}




void cl_application::scanElementsX(char nextChar, cl_base* ob_parent) {
	//string ancestor;
	//cout << "check empty: "<< "'" << nextChar << "'" << endl;
	//if (nextChar == ' ') {
	//	addNewChild(ob_parent);

	//	//cout << "CUONG" << endl;
	//	//cl_2* ob_2;
	//	//int selectFamily;
	//	//int state;

	//	////Scan nameObject 
	//	//string nameObject;
	//	//cin >> nameObject >> selectFamily >> state;

	//	////Debug
	//	//cout << nameObject << " " << selectFamily << " " << state << endl;
	//	//if (selectFamily == 2) {
	//	//	ob_2 = new cl_2((cl_base*)ob_parent);
	//	//	ob_2->set_object_name(nameObject);
	//	//	ob_2->set_state(state);

	//	//	////Debug
	//	//	cout << "Success with 2" << endl;
	//	//	cout << "TH3: Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_2) << endl << endl;
	//	//}
	//	//return;
	//} 
	//if (nextChar != '/') {
	//	ancestor.push_back(nextChar);
	//}
	//
	//
	//char checkNext;
	//checkNext = getchar();
	//ancestor = scanString(checkNext);
	////checkNext = getchar();  // use getchar() cause can scan \n and ' ;
	////
	////	while (checkNext != '/') {
	////		if (checkNext != ' ') {
	////			ancestor.push_back(checkNext);
	////			checkNext = getchar();
	////		}
	////		else break;
	////	}
	//	cout << "In to tien scanE: " << ancestor << "; Check char Next 1: " << checkNext << endl;
	//	if (checkNext == ' ') {

	//		//addNewChild(ob_parent);
	//		cl_2* ob_2;
	//		int selectFamily;
	//		int state;

	//		//Scan nameObject 
	//		string nameObject;
	//		cin >> nameObject >> selectFamily >> state;
	//		//Debug
	//		cout << nameObject <<" "<< selectFamily <<" "<< state << endl;
	//		if (selectFamily == 2) {
	//			ob_2 = new cl_2((cl_base*)ob_parent);
	//			ob_2->set_object_name(nameObject);
	//			ob_2->set_state(state);

	//			//Debug
	//			cout << "Success with 2" << endl;
	//			cout << "Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_2) << endl <<endl;
	//		}
	//		return;
	//	}

	//	else {

	//		//Debug
	//		cout << "Check char o vi tri tiep theo:" << checkNext << " " <<"In lai to tien: " << ancestor << endl;


	//		//checkNext = getchar();
	//		//scanElementsX(checkNext, this);
	//		/*for (size_t i = 0; i < ob_parent->children.size(); i++) {
	//			if (get_object_name((cl_base*)ob_parent->children.at(i)) == ancestor) {

	//				checkNext = getchar();
	//				scanElementsX(checkNext, (*(ob_parent->it_child)));
	//				return;
	//			}
	//		}*/
	//		
	//		string newAncestor;
	//		newAncestor = scanString(checkNext);
	//		//checkNext = getchar();  // use getchar() cause can scan \n and ' ;

	//		//while (checkNext != '/') {
	//		//	if (checkNext != ' ') {
	//		//		newAncestor.push_back(checkNext);
	//		//		checkNext = getchar();
	//		//	}
	//		//	else break;
	//		//}
	//		cout << "Check char o vi tri tiep theo 2:" << checkNext << " " << "In lai to tien: " << newAncestor << endl;
	//		ob_parent->it_child = ob_parent->children.begin();
	//		while (ob_parent->it_child != ob_parent->children.end()) {
	//			//Debug
	//			cout << "Check kiem tra bang nhau: " << get_object_name((*(ob_parent->it_child))) << "?" << newAncestor << endl;
	//			if (get_object_name((*(ob_parent->it_child))) == newAncestor) {
	//			
	//				cout << "Success with check char: " << newAncestor << ";" << "to tien: " << get_object_name((*(ob_parent->it_child))) << endl;
	//				scanElementsX(checkNext, (*(ob_parent->it_child)));
	//				break;
	//			}
	//			ob_parent->it_child++;
	//		}

	//		//


	//		/*ob_parent->it_child = ob_parent->children.begin();
	//		while (ob_parent->it_child != ob_parent->children.end()) {
	//			if (get_object_name((*(ob_parent->it_child))) == ancestor) {
	//				checkNext = getchar();
	//				cout << "Check NEXT: " << checkNext;
	//				scanElementsX(checkNext, (*(ob_parent->it_child)));
	//				break;
	//			}
	//			ob_parent->it_child++;

	//		}*/
	//		/*ob_parent->it_child = ob_parent->children.begin();
	//		while (ob_parent->it_child != ob_parent->children.end()) {
	//			cout << "Check name: " << get_object_name((*(ob_parent->it_child))) << " and " << ancestor << " and char:" << checkNext << endl;
	//			if (get_object_name((*(ob_parent->it_child))) == ancestor) {
	//				checkNext = getchar();
	//				scanElements((*(ob_parent->it_child)));
	//				break;
	//			}
	//			ob_parent->it_child++;
	//		}*/
	//	}

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
	
	cout << "Check result: " << ancestor << " charNext '" << charNext << "'" << endl;
	if (charNext == ' ') {
		addNewChild(this);
	}
	if (charNext == '/') {
		doWithChildLink(this);
	}

}

void cl_application::doNext(char nextChar, cl_base* ob_parent, string ancestor) {
	string newAncestor;
	char checkNext;
	checkNext = getchar();  // use getchar() cause can scan \n and ' ;

	while (checkNext != '/') {
		if (checkNext != ' ') {
			newAncestor.push_back(checkNext);
			checkNext = getchar();
		}
		else break;
	}
	if (checkNext == ' ') {


		addNewChild(ob_parent);



		//cl_2* ob_2;
		//int selectFamily;
		//int state;

		////Scan nameObject 
		//string nameObject;
		//cin >> nameObject >> selectFamily >> state;
		//
		////Debug
		//cout << nameObject << " " << selectFamily << " " << state << endl;
		//if (selectFamily == 2) {
		//	ob_2 = new cl_2((cl_base*)ob_parent);
		//	ob_2->set_object_name(nameObject);
		//	ob_2->set_state(state);

		//	////Debug
		//	cout << "Success with 2" << endl;
		//	cout << "TH2: Father: " << get_object_name((cl_base*)ob_parent) << "; Child: " << get_object_name(ob_2) << endl << endl ;
		//} 
		//return;
	}

	//Debug
	cout << "Check char or vi tri doNext: " << nextChar << "In to tien o vi tri doNext: " << newAncestor << endl;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		//Debug
		cout << "Check kiem tra bang nhau: " << get_object_name((*(ob_parent->it_child))) << "?" << newAncestor << endl;
		if (get_object_name((*(ob_parent->it_child))) == newAncestor) {
			cout << "Success with check char: "<< checkNext << endl;
			scanElementsX(checkNext, (*(ob_parent->it_child)));
			break;
		}
		ob_parent->it_child++;
	}
}



void cl_application::doWithChildLink(cl_base* ob_parent) {
	string ancestor;
	//ancestor = scanString(charNext, ancestor);
	char charNext;
	charNext = getchar();
	while (charNext != '/') {
		if (charNext != ' ') {
			ancestor.push_back(charNext);
			charNext = getchar();

		}
		else break;
	}

	cout << "Debug (doWithChildLink): " << ancestor << endl;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {

		//debug 

		cout << "//Check: " << get_object_name((*(ob_parent->it_child))) << " ? " << ancestor << " - charNext : " << charNext << endl;
		if (get_object_name((*(ob_parent->it_child))) == ancestor && charNext == '/') {
			cout << "Debug: Join 1:" << endl;
			doWithChildLink((*(ob_parent->it_child)));
			break;
		}
		if (get_object_name((*(ob_parent->it_child))) == ancestor && charNext == ' ') {
			cout << "Debug: Join 2:" << endl;
			addNewChild((*(ob_parent->it_child)));
			break;
		}
		ob_parent->it_child++;
	}
}



string cl_application::scanString(char checkNext, string ancestor) {
	cout << "Join ScanString: OK" << endl;
	char checkNextF;
	checkNextF = getchar(); 
	while (checkNextF != '/') {
		if (checkNextF != ' ') {
			ancestor.push_back(checkNextF);
			checkNextF = getchar();
		}
		else break;
	}
	checkNext = checkNextF;
	return ancestor;
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
		cout << "Add Child: OK" << endl;
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