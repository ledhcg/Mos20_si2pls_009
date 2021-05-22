#include "cl_application.h" 
#include <iomanip>
#include <iostream>
using namespace std;

cl_application::cl_application() {
	string name = "file.txt";
	toDo.setNameFile(name);
}

void cl_application::buildFile() {
	createNewFile();
	scanPosition();
}

void cl_application::createNewFile() {
	ofstream newFile(toDo.getNameFile(), ios::out);
		if (!newFile) {
			return;
		}
		for (int indexR = 1; indexR <= 10; indexR++) {
			if (indexR != 1) {
				newFile << endl;
			}
			for (int indexC = 1; indexC <= 10; indexC++) {
				int number = 8;
				newFile << number;
			}
		}
	newFile.close();
}

void cl_application::scanPosition() {
	while (true) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
		else {
			char k;
			cin >> k;
			toDo.setSignal(this, x, y, k);
		}
	}
}


int cl_application::exec_app() {
	printToScreen();
	return 0;
}

void cl_application::printToScreen() {
	toDo.showFile();
}
