#include "cl_base.h"
#include <iostream>
#define SIGNALING (cl_base* p_parent, int x, int y, char k)
#define HANDLING1 (cl_base* p_parent, int x, int y)
#define HANDLING2 (cl_base* p_parent, char k, bool letter)
using namespace std;


void cl_base::setNameFile(string nameFile) {
	this->nameFile = nameFile;
}

string cl_base::getNameFile() {
	return this->nameFile;
}


void cl_base::setSignal SIGNALING {
	if (!((1 <= x && x <= 10) && (1 <= y && y <= 10))) {
		addDataFile.open(nameFile, ios::app);
		handling1(this, x, y);
	}
	else {
		if (!(('a' <= k && k <= 'z') || ('A' <= k && k <= 'Z'))) {
			addDataFile.open(nameFile, ios::app);
			handling2(this, k, false);
			
		}
		else {
			addDataFile.open(nameFile, ios::in);
			int position = (x - 1) * 12 + y - 1;
			addDataFile.seekp(position, ios::beg);
			handling2(this, k, true);
		}
	}
}
void cl_base::handling1 HANDLING1 {
	addDataFile << endl << "Coordinate is wrong ( " << x << ", " << y << " )";
	addDataFile.close();
}

void cl_base::handling2 HANDLING2 {
	if (letter) {
		addDataFile.put(k);
		addDataFile.close();
	}
	else {
		addDataFile << endl << "Not a letter of the Latin alphabet: " << k;
		addDataFile.close();
	}
}

void cl_base::showFile() {
	readFile.open(getNameFile(), ios::in);
	if (!readFile) {
		return;
	}
	string line;
	while (getline(readFile, line)) {
		cout << line;
		if (!readFile.eof()) {
			cout << endl;
		}
	}
	readFile.close();
}