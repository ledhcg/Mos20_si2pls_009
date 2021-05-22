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
	scanConnects(this);
	scanSignals(this);
}

void cl_application::scanConnects(cl_base* ob_parent) {
	while (true) {
		int id;
		string sender, receiver;
		cin >> id;
		if (id == 0)
			break;
		else {
			cin >> sender >> receiver;
			cl_2* connectStart;
			connectStart = new cl_2((cl_base*)ob_parent, true, false);
			connectStart->setNameSender(sender);
			connectStart->setID(id);
			connectStart->setNameReceiver(receiver);
			sendIDtoReceiver(this, receiver, id);
		}
	}	
}

void cl_application::sendIDtoReceiver(cl_base* ob_parent, string receiver, int id) {
	if (ob_parent->children.size() == 0)
		return;
	ob_parent->it_child = ob_parent->children.begin();
	while (ob_parent->it_child != ob_parent->children.end()) {
		if (receiver == get_object_name((*(ob_parent->it_child)))) {
			nextSetID((*(ob_parent->it_child)), id);
		}
		ob_parent->it_child++;
	}
}

void cl_application::nextSetID(cl_base* ob_parent, int id) {
	ob_parent->setID(id);
}


void cl_application::scanSignals(cl_base* ob_parent) {
	while (true) {
		string sender;
		string message;
		cin >> sender;
		if (sender == "endsignals") {
			break;
		}
		else {
			cin >> message;
			cl_2* messageStart;
			messageStart = new cl_2((cl_base*)ob_parent, false, true);
			messageStart->setNameSender(sender);
			messageStart->setMessageText(message);
		}
	}
}

void cl_application::checkAndPrint(cl_base* ob_parent) {
	cout << endl << "Set connects";
	if (ob_parent->infoSender.size() == 0)
		return;
	ob_parent->it_iS = ob_parent->infoSender.begin();
	while (ob_parent->it_iS != ob_parent->infoSender.end()) {
		cout << endl << getID((*(ob_parent->it_iS))) << " " << getNameSender((*(ob_parent->it_iS))) << " " << getNameReceiver(*(ob_parent->it_iS));
		ob_parent->it_iS++;
	}
}

void cl_application::printInfoWithMessage(cl_base* ob_parent) {
	cout << endl << "Emit signals";
	/*if (ob_parent->infoSender.size() == 0)
		return;
	ob_parent->it_iS = ob_parent->infoSender.begin();
	while (ob_parent->it_iS != ob_parent->infoSender.end()) {
		returnMessage(this, getNameSender(*(ob_parent->it_iS)), getNameReceiver((*(ob_parent->it_iS))));
		ob_parent->it_iS++;
	}*/
	if (ob_parent->storageMess.size() == 0)
		return;
	ob_parent->it_sM = ob_parent->storageMess.begin();
	while (ob_parent->it_sM != ob_parent->storageMess.end()) {

		returnMessage(this, getNameSender(*(ob_parent->it_sM)), getMessageText((*(ob_parent->it_sM))));

		ob_parent->it_sM++;
	}
}

void cl_application::returnMessage(cl_base* ob_parent, string sender, string message) {
	/*if (ob_parent->storageMess.size() == 0)
		return;
	ob_parent->it_sM = ob_parent->storageMess.begin();
	while (ob_parent->it_sM != ob_parent->storageMess.end()) {
		if (sender == getNameSender((*(ob_parent->it_sM)))) {
			cout << endl << "Signal to " << receiver << " Text: " << sender << " -> " << getMessageText((*(ob_parent->it_sM)));
		}
		ob_parent->it_sM++;
	}*/
	if (ob_parent->infoSender.size() == 0)
		return;
	ob_parent->it_iS = ob_parent->infoSender.begin();
	while (ob_parent->it_iS != ob_parent->infoSender.end()) {
		if (sender == getNameSender((*(ob_parent->it_iS)))) {

			cout << endl << "Signal to " << getNameReceiver((*(ob_parent->it_iS))) << " Text: " << sender << " -> " << message;
		}
		ob_parent->it_iS++;
	}
}

//void cl_application::printInfoWithMessage(cl_base* ob_parent) {
//	cout << endl << "Emit signals";
//	if (ob_parent->infoSender.size() == 0)
//		return;
//	ob_parent->it_iS = ob_parent->infoSender.begin();
//	while (ob_parent->it_iS != ob_parent->infoSender.end()) {
//		
//		//cout << endl << "Signal to " << getNameReceiver((*(ob_parent->it_iS))) << " Text: " << getNameSender(*(ob_parent->it_iS)) << " -> " << returnMessage(this, getNameSender(*(ob_parent->it_iS)));
//		returnMessage(this, getNameSender(*(ob_parent->it_iS)), getNameReceiver((*(ob_parent->it_iS))));
//		ob_parent->it_iS++;
//	}
//}
//
//void cl_application::returnMessage(cl_base* ob_parent, string sender, string receiver) {
//	//string result = "";
//	if (ob_parent->storageMess.size() == 0)
//		return;
//	ob_parent->it_sM = ob_parent->storageMess.begin();
//	while (ob_parent->it_sM != ob_parent->storageMess.end()) {
//		if (sender == getNameSender((*(ob_parent->it_sM)))) {
//			cout << endl << "Signal to " << receiver << " Text: " << sender << " -> " << getMessageText((*(ob_parent->it_sM)));
//			//result = getMessageText((*(ob_parent->it_sM)));
//			//break;
//		}
//		ob_parent->it_sM++;
//	}
//	//return result;
//}
void cl_application::addNewChild(cl_base* ob_parent, string nameParent, string nameChild, int state, int selectFamily) {
	cl_2* ob_2;
	cl_3* ob_3;
	cl_4* ob_4;
	cl_5* ob_5;
	cl_6* ob_6;
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
	checkAndPrint(this);
	printInfoWithMessage(this);
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