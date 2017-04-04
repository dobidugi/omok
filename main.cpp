#include <iostream>
#include <Windows.h>
#include "omok.h"


int main()
{
	Omok *M = new Omok;
	M->start();
	while (M->set()==1)
	{
		M->move();
	}
	Sleep(3000);
	delete M;
}