//#include <iostream>
//#include <string>
//using namespace std;
//
//void callback(char i) {
//	while (i == '/') {
//		char check;
//		cin >> check;
//		if (check != '/')
//
//		cout << a << endl;
//		int j;
//		cin >> j;
//		callback(j);
//	}
//}
//int main() {
//
//	char i;
//	cin >> i;
//	callback(i);
//}
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
//
//void scanElements() {
//	string ancestor;
//	char checkNext;
//	checkNext=getchar();  // use getchar() cause can scan \n and ' ;
//	while (checkNext != '/'){
//		if (checkNext != ' ') {
//			ancestor.push_back(checkNext);
//			checkNext = getchar();
//		}
//		else break;
//	}
//	cout << ancestor << endl;
//	if (checkNext == ' ') {
//		int a, b;
//		cin >> a >> b;
//		return;
//	}
//		
//	else {
//		cout << "debug: " << checkNext << endl;
//		scanElements();
//	}
//}
						
int main()
{
	//string test = "///hjjkjcd/jhjhkj/khbjkbkj/gfchgvugtftrd/fhgvjhvjh";
	//if (test[0] == '/') {
	//	cout << test.size() << endl;
	//	int i = 1;

	//	while (i < test.size()) {
	//		cout << "Debug: " << i << endl;
	//		string name;
	//		while (test[i] != '/') {
	//			name.push_back(test[i]);
	//			if (i == (test.size() - 1)) {
	//				break;
	//			}
	//			else
	//				i++;
	//		}
	//		cout << "'" << name << "'" << endl;
	//		cout << "Debug2: " << i << endl;
	//		if (name.size() == 0) {
	//			cout << endl << "Fail" << endl;
	//		}
	//		if (i == test.size() - 1) {
	//			cout << "Last string: " << name << endl;
	//		}

	//		if (i < test.size()) {
	//			i++;
	//			cout << "Debug3: " << i << endl;
	//		}
	//	}
	//}
	//else {
	//	cout << test.size() << endl;
	//	int i = 0;

	//	while (i < test.size()) {
	//		cout << "Debug: " << i << endl;
	//		string name;
	//		while (test[i] != '/') {
	//			name.push_back(test[i]);
	//			if (i == (test.size() - 1)) {
	//				break;
	//			}
	//			else
	//				i++;
	//		}
	//		cout << "'" << name << "'" << endl;
	//		cout << "Debug2: " << i << endl;
	//		if (name.size() == 0) {
	//			cout << endl << "Fail" << endl;
	//		}
	//		if (i == test.size() - 1) {
	//			cout << "Last string: " << name << endl;
	//		}

	//		if (i < test.size()) {
	//			i++;
	//			cout << "Debug3: " << i << endl;
	//		}
	//	}
	//}
	//


	string test = "////hjjkjcd/jhjhkj/khbjkbkj/gfchgvugtftrd/fhgvjhvjh";
	if (test[0] == '/') {
		int i = 1;

		while (i < test.size()) {
			string name;
			while (test[i] != '/') {
				name.push_back(test[i]);
				if (i == (test.size() - 1)) {
					break;
				}
				else
					i++;
			}
			cout << "Debug i: " << test[i] << endl;

			
			if (i == test.size() - 1) {
				cout << "Last string: " << name << endl;
			}

			if (i < test.size()) {
				
				cout << "String: " << name << endl;
				i++;
			}
		}
	}
	//else {
	//	
	//	int i = 0;

	//	while (i < test.size()) {
	//		
	//		string name;
	//		while (test[i] != '/') {
	//			name.push_back(test[i]);
	//			if (i == (test.size() - 1)) {
	//				break;
	//			}
	//			else
	//				i++;
	//		}
	//		cout << "'" << name << "'" << endl;
	//		cout << "Debug2: " << i << endl;
	//		if (name.size() == 0) {
	//			cout << endl << "Fail" << endl;
	//		}
	//		if (i == test.size() - 1) {
	//			cout << "Last string: " << name << endl;
	//		}

	//		if (i < test.size()) {
	//			i++;
	//			cout << "Debug3: " << i << endl;
	//		}
	//	}
	//}
	return 0;
}