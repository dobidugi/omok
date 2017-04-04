#include <iostream>
#include "omok.h"


int main()
{
	Omok *M = new Omok;
	M->start();
	while (1)
	{
		M->point();
	}

}