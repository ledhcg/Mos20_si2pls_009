#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H

#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include "cl_base.h"


class cl_application : public cl_base {

public:
	cl_application(string name);
	void bild_tree_objects();
	void scanElementsX(char nextChar, cl_base* ob_parent);
	void doWithChildLink(cl_base* ob_parent);
	void addNewChild(cl_base* ob_parent);
	void resultLink(cl_base* ob_parent);
	void processAccess(cl_base* ob_parent);
	void connectWithRoot(int count, string linkName, cl_base* ob_parent, bool notFound);
	void connectAccess(int count, string linkName, cl_2* ob_2L, cl_base* ob_parent);
	bool checkMemberDeep(cl_base* ob_parent, string name);
	bool checkMember(cl_base* ob_parent);
	int exec_app();
	void show_object_state();
private:

	void show_state_next(cl_base* ob_parent, int i);


};

#endif // CL_APPLICATION_H