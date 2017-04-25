#include <iostream>
#include <Windows.h>
#include "Judge.h"

Judge::Judge(int _width, int _hegiht) : width(_width), height(_hegiht) {}

Judge::~Judge() { map.clear(); }

bool Judge::push_check(int value)
{
	if (value == 0) return true;
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
		return 0;
	}
}


void Judge::msg()
{
	COORD Point;
	Point.X = 0;
	Point.Y = height;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Point);
	if (turn == false) { std::cout << "¡Û Win"; 	game = false; }
	else if (turn == true) { std::cout << "¡Ü Win"; 	game = false; }
}

bool Judge::play()
{
	return game;
}

void Judge::win_check(std::vector<std::vector<int>> copy_map)
{
	map = copy_map;
	int value;
	bool result = false;
	if (turn == false) value = 8;
	else if (turn == true) value = 9;	
	if (true == WidthCheck(value)) msg();
	else if (true == HeightCheck(value)) msg();
	else if (true == CrossCheck(value)) msg();
	else if (true == RcrossCheck(value)) msg();
}

bool Judge::WidthCheck(int value)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == value) && (map[i][j + 1] == value) && (map[i][j + 2] == value) && (map[i][j + 3] == value) && (map[i][j + 4] == value))
			{
				return 1;
			}
		}
	}
	return 0;
}

bool Judge::HeightCheck(int value)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[j][i] == value) && (map[j + 1][i] == value) && (map[j + 2][i] == value) && (map[j + 3][i] == value) && (map[j + 4][i] == value))
			{

				return 1;
			}
		}
	}
	return 0;
}

bool Judge::CrossCheck(int value)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == value) && (map[i + 1][j + 1] == value) && (map[i + 2][j + 2] == value) && (map[i + 3][j + 3] == value) && (map[i + 4][j + 4] == value))
			{
				return 1;
			}
		}
	}
	return 0;
}

bool Judge::RcrossCheck(int value)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((map[i][j] == value) && (map[i - 1][j + 1] == value) && (map[i - 2][j + 2] == value) && (map[i - 3][j + 3] == value) && (map[i - 4][j + 4] == value))
			{
				return 1;
			}
		}
	}
	return 0;
}