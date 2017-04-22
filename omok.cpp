#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "omok.h"

//#define _X 20
//#define _Y 20 

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


Omok::Omok(int _x, int _y) : loop_x(_x) , loop_y(_y) , x(_x),y(_y)
{
	arr.assign(y, std::vector<int>(x, 0));
	Omok::drawMap();
}

Omok::~Omok()
{
	arr.clear();
}



void drawTopLeft() { std::cout << "¦£"; }
void drawTopCenter() { std::cout << "¦¨"; }
void drawTopRight() { std::cout << "¦¤"; std::cout << "" << std::endl; }

void drawLeft() { std::cout << "¦§"; }
void drawCenter() { std::cout << "¦«"; }
void drawRight() { std::cout << "¦©"; std::cout << "" << std::endl; }

void drawBottomLeft() { std::cout << "¦¦"; }
void drawBottom() { std::cout << "¦ª"; }
void drawBottomRight() { std::cout << "¦¥"; }

void Omok::drawMap()
{
	//	map.resize(x*y);
	Omok::gotoxy(0, 0);
	int cnt = 0;
	for (int i = 0; i<loop_y; i++)
	{
		if (i == 0) drawTopLeft();
		else if (i >= 1 && i <= y - 2) drawLeft();
		else if (i == y - 1)  drawBottomLeft();
		for (int j = 0; j < loop_x; j++)
		{
			if (i == 0 && j >= 1 && j <= x - 2) drawTopCenter();
			else if (i == 0 && j == x - 1)  drawTopRight();
			else if (i != 0 && i <= y - 2 && j >= 1 && j <= x - 2) drawCenter();
			else if (i != 0 && i <= y - 2 && j == x - 1) drawRight();
			else if (i == y - 1 && j >= 1 && j <= x - 2) drawBottom();
			else if (i == y - 1 && j == x - 1) drawBottomRight();
		}
	}
	//x = x / 2;
	//y = y / 2;
}

bool Omok::check_win()
{
	int b_cnt = 0;
	int w_cnt = 0;
	int cnt = 1;

	for (int i = 0; i < loop_y; i++) //length_check start
	{
		for (int j = 0; j < loop_x; j++)
		{
			if ((arr[i][j] == 8) && (arr[i][j + 1] == 8) && (arr[i][j + 2] == 8) && (arr[i][j + 3] == 8) && (arr[i][j + 4] == 8))
			{
				return 0;
			}
			else if ((arr[i][j] == 9) && (arr[i][j + 1] == 9) && (arr[i][j + 2] == 9) && (arr[i][j + 3] == 9) && (arr[i][j + 4] == 9))
			{
				return 1;
			}
		}
	} //length_check finish

	for (int i = 0; i < loop_y; i++) // width_check start
	{
		for (int j = 0; j < loop_x; j++)
		{
			if ((arr[j][i] == 8) && (arr[j + 1][i] == 8) && (arr[j + 2][i] == 8) && (arr[j + 3][i] == 8) && (arr[j + 4][i] == 8))
			{

				return 0;
			}
			if ((arr[j][i] == 9) && (arr[j + 1][i] == 9) && (arr[j + 2][i] == 9) && (arr[j + 3][i] == 9) && (arr[j + 4][i] == 9))
			{

				return 1;
			}
		}
	} // width_check finish

	for (int i = 0; i < loop_y; i++) //reverse_cross_check start
	{
		for (int j = 0; j < loop_x; j++)
		{
			if ((arr[i][j] == 8) && (arr[i - 1][j + 1] == 8) && (arr[i - 2][j + 2] == 8) && (arr[i - 3][j + 3] == 8) && (arr[i - 4][j + 4] == 8))
			{
				return 0;
			}
			else if ((arr[i][j] == 9) && (arr[i - 1][j + 1] == 9) && (arr[i - 2][j + 2] == 9) && (arr[i - 3][j + 3] == 9) && (arr[i - 4][j + 4] == 9))
			{
				return 1;
			}
		}
	} //reverse_cross_check finish
	for (int i = 0; i < loop_y; i++) //reverse_cross_check start
	{
		for (int j = 0; j < loop_x; j++)
		{
			if ((arr[i][j] == 8) && (arr[i + 1][j + 1] == 8) && (arr[i + 2][j + 2] == 8) && (arr[i + 3][j + 3] == 8) && (arr[i + 4][j + 4] == 8))
			{
				return 0;
			}
			else if ((arr[i][j] == 9) && (arr[i + 1][j + 1] == 9) && (arr[i + 2][j + 2] == 9) && (arr[i + 3][j + 3] == 9) && (arr[i + 4][j + 4] == 9))
			{
				return 1;
			}
		}
	} //reverse_cross_check finish

}

bool Omok::set()
{
	return game;
}
void Omok::gotoxy(int g_x, int g_y)
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
				x -= 1;
				gotoxy(x * 2, y);
			}
			break;
		case 77: // right move 
			if (x < loop_x  - 1)
			{
				x += 1;
				gotoxy(x * 2, y);
			}
			break;
		case 72: // up move 
			if (y > 0)
			{
				y -= 1;
				gotoxy(x * 2, y);
			}
			break;

		case 80: // down move 
			if (y < loop_y - 1)
			{
				y += 1;
				gotoxy(x * 2, y);

			}
			break;
		case 79: // push spacebar
			if (arr[y][x] != 0)
			{
				//msg(3);
			}
			else if (arr[y][x] == 0)
			{
				if (turn == false)
				{
					arr[y][x] = 8;
					std::cout << "¡Û"; // black
					turn = true;
					gotoxy(x * 2, y);
					msg(check_win());
					//gotoxy(40, 0);
					//std::cout << "Turn : ¡Ü" << std::endl;
					gotoxy(x * 2, y);
				}
				else if (turn == true)
				{
					arr[y][x] = 9;
					std::cout << "¡Ü"; // whtie
					turn = false;
					gotoxy(x * 2, y);
					msg(check_win());
					///gotoxy(40, 0);
					///std::cout << "Turn : ¡Û" << std::endl;
					gotoxy(x * 2, y);
				}
			}
			break;
		}
	}


}
void Omok::msg(int i)
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = 20;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	if (i == 0)
	{
		std::cout << " ¡Û Win!";
		game = 0;
	}
	else if (i == 1)
	{
		std::cout << " ¡Ü Win!";
		game = 0;
	}
	/*else if (i == 3)
	{
		std::cout << "You can`t locate the rock here";
		Sleep(1000);
		Pos.X = x*10;
		Pos.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		std::cout << "                              ";
	}*/

}
