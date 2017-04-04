#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "omok.h"

#define _X 20
#define _Y 20 

// 왼쪽 ├ 1
// 오른쪽 ┤ 2
// 왼쪽위 ┌ 3
// 오른쪽위 ┐ 4
// 맨위 ┬ 5
// 맨아래 ┴ 6
// 왼쪽아래 └ 7
// 오른쪽 아래 ┘ 8
// 가운대 ┼ 0

bool Omok::check_win()
{

	return 0;
}

void Omok::gotoxy(int g_x)
{
	COORD Pos;
	Pos.X = g_x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Omok::point()
{
	int key;
	key = getch();
	switch (key)
	{
	case 75: // left
		if (x > 0)
		{
			if (arr[y][x - 1] == 0)
			{
				x -= 1;
				gotoxy(x * 2);
				test();
				std::cout << y << x;
	
			}
		}
			break;
		case 77: // right
			if (x < 19)
			{
				x += 1;
				gotoxy(x * 2);
				test();
				std::cout << y << x;
			}
			break;
		case 72: // up
			if (y > 0)
			{
				y -= 1;
				gotoxy(x);
			}
			break;

		case 80: // down
			if (y < 19)
			{
				y += 1;
				gotoxy(x);
			}
			break;
		}



}
void Omok::test()
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = 22;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

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
				std::cout << "┼";
				break;
			case 1:
				std::cout << "├";
				arr[i][j] = 0;
				break;
			case 2:
				std::cout << "┤";
				arr[i][j] = 0;
				break;
			case 3:
				std::cout << "┌";
				arr[i][j] = 0;
				break;
			case 4:
				std::cout << "┐";
				arr[i][j] = 0;
				break;
			case 5:
				std::cout << "┬";
				arr[i][j] = 0;
				break;
			case 6:
				std::cout << "┴";
				arr[i][j] = 0;
				break;
			case 7:
				std:: cout << "└";
				arr[i][j] = 0;
				break;
			case 8:
				std::cout << "┘";
				arr[i][j] = 0;
				break;
			}
		}
		std::cout << "" << std::endl;
	}
}