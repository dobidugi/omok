#include <iostream>
#include <Windows.h>
#include "Board.h"
#include "player.h"
#include "Judge.h"

int main()
{
	int set_width;
	int set_height;
	std::cout << "input width : ";
	std::cin >> set_width;
	std::cout << "input height : ";
	std::cin >> set_height;
	Board *B = new Board(set_width, set_height);
	Player *P = new Player(set_width, set_height);
	Judge *J = new Judge(set_width, set_height);
	while (J->play() == true ) // 게임상태
	{
		while (1)
		{
			if (9 == P->move()) break; 
		}		
		B->Pushcheck(J,P->GetY(),P->GetX());
	}
}