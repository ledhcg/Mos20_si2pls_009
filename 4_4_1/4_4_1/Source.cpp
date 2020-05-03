#include <iostream>
#include "derived3.h"
#include "cl_base.h"
using namespace std;

int main() {
	derived3* ab;
	ab = new derived3;
	ab->cl_base::in_out();
	ab->in_out();
}