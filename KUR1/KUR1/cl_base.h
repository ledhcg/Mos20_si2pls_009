#ifndef CL_BASE_H
#define CL_BASE_H

#include <string>
#include <fstream>
#define SIGNALING (cl_base* p_parent, int x, int y, char k)
#define HANDLING1 (cl_base* p_parent, int x, int y)
#define HANDLING2 (cl_base* p_parent, char k, bool letter)
using namespace std;

class cl_base
{
private:
	string nameFile;
	ofstream addDataFile;
	ifstream readFile;

public:
	void setNameFile(string nameFile);
	string getNameFile();

	void setSignal SIGNALING;
	void handling1 HANDLING1;
	void handling2 HANDLING2;
	void showFile();
};


#endif // !CL_BASE_H





