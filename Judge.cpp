#include <iostream>
#include <Windows.h>
#include "Judge.h"

Judge::Judge(int _width, int _hegiht) : width(_width), height(_hegiht) 
{
	map.assign(height, std::vector<int>(width, 0));
}


bool Judge::push_check(int check_y, int check_x)
{
	if (map[check_y][check_x] == 0)
	{
		push(check_y, check_x);
		return true;
	}
	else
	{
		COORD Point;
		Point.X = 0;
		Point.Y = height;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
		std::cout << "You can`t locate the rock here";
		Sleep(1000);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
		std::cout << "                                         ";
	}
}

void Judge::push(int y,int x)
{
	if (turn == false)
	{
		map[y][x] = 8;
		std::cout << "¡Û"; // black
		turn = true;
		msg(win_check());
	}
	else if (turn == true)
	{
		map[y][x] = 9;
		std::cout << "¡Ü"; // whtie
		turn = false;
		msg(win_check());
	}
}

bool Judge::win_check()
{
	int b_cnt = 0;
	int w_cnt = 0;
	int cnt = 1;

	for (int i = 0; i < height; i++) //length_check start
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == 8) && (map[i][j + 1] == 8) && (map[i][j + 2] == 8) && (map[i][j + 3] == 8) && (map[i][j + 4] == 8))
			{
				return 0;
			}
			else if ((map[i][j] == 9) && (map[i][j + 1] == 9) && (map[i][j + 2] == 9) && (map[i][j + 3] == 9) && (map[i][j + 4] == 9))
			{
				return 1;
			}
		}
	} //length_check finish

	for (int i = 0; i < height; i++) // width_check start
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[j][i] == 8) && (map[j + 1][i] == 8) && (map[j + 2][i] == 8) && (map[j + 3][i] == 8) && (map[j + 4][i] == 8))
			{

				return 0;
			}
			if ((map[j][i] == 9) && (map[j + 1][i] == 9) && (map[j + 2][i] == 9) && (map[j + 3][i] == 9) && (map[j + 4][i] == 9))
			{

				return 1;
			}
		}
	} // width_check finish

	for (int i = 0; i < height; i++) //reverse_cross_check start
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == 8) && (map[i - 1][j + 1] == 8) && (map[i - 2][j + 2] == 8) && (map[i - 3][j + 3] == 8) && (map[i - 4][j + 4] == 8))
			{
				return 0;
			}
			else if ((map[i][j] == 9) && (map[i - 1][j + 1] == 9) && (map[i - 2][j + 2] == 9) && (map[i - 3][j + 3] == 9) && (map[i - 4][j + 4] == 9))
			{
				return 1;
			}
		}
	} //reverse_cross_check finish
	for (int i = 0; i < height; i++) //cross_check start
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == 8) && (map[i + 1][j + 1] == 8) && (map[i + 2][j + 2] == 8) && (map[i + 3][j + 3] == 8) && (map[i + 4][j + 4] == 8))
			{
				return 0;
			}
			else if ((map[i][j] == 9) && (map[i + 1][j + 1] == 9) && (map[i + 2][j + 2] == 9) && (map[i + 3][j + 3] == 9) && (map[i + 4][j + 4] == 9))
			{
				return 1;
			}
		}
	} //_cross_check finish
}

void Judge::msg(bool A)
{
	COORD Point;
	Point.X = 0;
	Point.Y = height;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
	if (A == 0) { std::cout << "¡Û Win"; 	game = false; }
	else if (A == 1) { std::cout << "¡Ü Win"; 	game = false; }

}

bool Judge::play()
{
	return game;
}