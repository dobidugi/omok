#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "player.h"

Player::Player(int width, int height) : x(width), y(height), loop_x(width), loop_y(width)
{
	gotoxy(width / 2, height / 2);
	x = width / 2;
	y = width / 2;
}


int Player::move()
{
	int key;
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
		if (x < loop_x - 1)
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
		return 9;
		break;
	}
}

int Player::GetX() const
{
	return x;
}

int Player::GetY() const
{
	return y;
}

void Player::gotoxy(int get_x, int get_y)
{
	COORD Point;
	Point.X = get_x;
	Point.Y = get_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
}