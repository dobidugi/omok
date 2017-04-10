#include <iostream>
#include "board.h"

board::board(int _x,int _y) : x(_x), y(_y) 
{
	arr = new int*[y];
	for (int i = 0; i < x; i++)
	{
		arr[i] = new int[x];
	}
	
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			arr[i][j] = 0;
		}
	}
	board::drawMap();
}
board::~board()
{
	for (int i = 0; i < y; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

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
void board::test()
{
	arr[0][0]= 4;
}
void board::drawMap()
{
	//	map.resize(x*y);
	int cnt = 0;
	for(int i=0;i<y;i++)
	{
		if (i == 0) drawTopLeft();
		else if (i >= 1 && i <= y - 2) drawLeft();
		else if (i == y - 1)  drawBottomLeft();
		for (int j = 0; j < x; j++)
		{
			if (i == 0 && j >= 1 && j <= x - 2) drawTopCenter();
			else if (i == 0 && j == x - 1)  drawTopRight();
			else if (i != 0 && i <= y - 2 && j >= 1 && j <= x - 2) drawCenter();
			else if (i != 0 && i <= y - 2 && j == x - 1) drawRight();
			else if (i == y-1 && j >= 1 && j <= x - 2) drawBottom();
			else if (i == y - 1 && j == x - 1) drawBottomRight();
		}
	}
}

