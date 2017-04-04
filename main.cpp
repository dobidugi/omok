#include <iostream>
#include <Windows.h>
#include "omok.h"

int main()
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = 22;
	Omok *M = new Omok;
	M->start();
	while (M->set()==1)
	{
		M->move();
	}
	Sleep(3000);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	delete M;
}