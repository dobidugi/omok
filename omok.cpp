#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "omok.h"

#define _X 20
#define _Y 20 

// left ¦§ 1
// right ¦© 2
// left_up ¦£ 3
// right_up ¦¤ 4
// up ¦¨ 5
// down ¦ª 6
// left_down ¦¦ 7
// right_down ¦¥ 8
// center	 ¦« 0


// ¡Û black 8
// ¡Ü white 9
bool Omok::check_win()
{
	int b_cnt = 0;
	int w_cnt = 0;
	for (int i = y; i < y+5; i++)
	{
		if (arr[i][x] == 8)	b_cnt++;
		if (arr[i][x] == 9)	w_cnt++;
	} // over_length check
	

	if(b_cnt==5) return 0;
	if(w_cnt==5) return 1;


}

bool Omok::set()
{
	return game;
}
void Omok::gotoxy(int g_x,int g_y)
{
	COORD Pos;
	Pos.X = g_x;
	Pos.Y = g_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Omok::move()
{
	int key;
	key = getch();
	if (key == 224)
	{
		key = getch();
		switch (key)
		{
		

		case 75: // left move
			if (x > 0)
			{
				if (arr[y][x - 1] == 0)
				{
					x -= 1;
					gotoxy(x * 2,y);
				}
			}
			break;
		case 77: // right move 
			if (x < 19)
			{
				x += 1;
				gotoxy(x * 2,y);
			}
			break;
		case 72: // up move 
			if (y > 0)
			{
				y -= 1;
				gotoxy(x*2,y);
			}
			break;

		case 80: // down move 
			if (y < 19)
			{
				y += 1;
				gotoxy(x*2,y);

			}
			break;
		case 79: // push spacebar
			if (arr[y][x] != 0)
			{
				msg(3);
			}
			else if (arr[y][x] == 0)
			{
				if (turn == false)
				{
					arr[y][x] = 8;
					std::cout << "¡Û"; // black
					turn = true;	
					gotoxy(x*2,y);
					msg(check_win());
				}
				else if (turn == true)
				{
					arr[y][x] = 9;
					std::cout << "¡Ü"; // whtie
					turn = false;
					gotoxy(x*2,y);
					msg(check_win());
				}
			}
			break;
		}
	}


}
void Omok::msg(int i=0)
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = 20;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	if (i == 0)
	{
		std::cout << "¡Û winner!";
		game = 0;
	}
	else if(i == 1)
	{
		std::cout << "¡Ü winner!";
		game = 0;
	}
	else if (i == 3)
	{
		std::cout << "You can`t locate the rock here";
		Sleep(1000);
		msg();
		std::cout << "                              ";
	}

}
void Omok::start()
{
	for (int i = 0; i < _Y; i++)
	{
		for (int j = 0; j < _X; j++)
		{
			switch (arr[i][j])
			{
			case 0:
				std::cout << "¦«";
				break;
			case 1:
				std::cout << "¦§";
				arr[i][j] = 0;
				break;
			case 2:
				std::cout << "¦©";
				arr[i][j] = 0;
				break;
			case 3:
				std::cout << "¦£";
				arr[i][j] = 0;
				break;
			case 4:
				std::cout << "¦¤";
				arr[i][j] = 0;
				break;
			case 5:
				std::cout << "¦¨";
				arr[i][j] = 0;
				break;
			case 6:
				std::cout << "¦ª";
				arr[i][j] = 0;
				break;
			case 7:
				std:: cout << "¦¦";
				arr[i][j] = 0;
				break;
			case 8:
				std::cout << "¦¥";
				arr[i][j] = 0;
				break;
			}
		}
		std::cout << " " << std::endl;
	}
}