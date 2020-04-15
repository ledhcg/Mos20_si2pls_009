#include "base.h"

#ifndef DERIVED2
#define DERIVED2

class derived2 : virtual public base
{
public:
	void exchangeSort();
	void printArr();
};

#endif // !DERIVED2