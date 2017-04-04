#include <iostream>
#include "omok.h"


int main()
{
	Omok *M = new Omok;
	M->start();
	while (M->set()==1)
	{
		M->move();
	}
	delete M;
}