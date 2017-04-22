#include <iostream>
#include <Windows.h>
//#include "board.h"
#include "omok.h"

int main()
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = 22;
	int getx, gety;
	std::cout << "input widthsize : ";
	std::cin >> getx; 
	std::cout << "input heightsize : ";
	std::cin >> gety;
	Omok *M = new Omok(getx, gety);
	//M->start();
	while (M->set()==1)
	{
		M->move();
	}
	Sleep(3000);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	delete M;
	
}