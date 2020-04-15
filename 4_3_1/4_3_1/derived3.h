#include "derived1.h"
#include "derived2.h"

#ifndef DERIVED3
#define DERIVED3

class derived3 : public derived1, public derived2
{
public:
	void doIt();
};

#endif // !DERIVED3
