#include <iostream>
#include <vector>
#include "Board.h"

Board::Board(int _width, int _hegiht) : width(_width) , height(_hegiht)
{
	system("cls");
	map.assign(height, std::vector<int>(width, 0));
	Board::drawMap(); 
}


void drawTopLeft() { std::cout << "��"; }
void drawTopCenter() { std::cout << "��"; }
void drawTopRight() { std::cout << "��"; std::cout << "" << std::endl; }

void drawLeft() { std::cout << "��"; }
void drawCenter() { std::cout << "��"; }
void drawRight() { std::cout << "��"; std::cout << "" << std::endl; }

void drawBottomLeft() { std::cout << "��"; }
void drawBottom() { std::cout << "��"; }
void drawBottomRight() { std::cout << "��"; }

void Board::drawMap()
{
	for (int i = 0; i<height; i++)
	{
		if (i == 0) drawTopLeft();
		else if (i >= 1 && i <= height - 2) drawLeft();
		else if (i == height - 1)  drawBottomLeft();
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && j >= 1 && j <= width - 2) drawTopCenter();
			else if (i == 0 && j == width - 1)  drawTopRight();
			else if (i != 0 && i <= height - 2 && j >= 1 && j <= width - 2) drawCenter();
			else if (i != 0 && i <= height - 2 && j == width - 1) drawRight();
			else if (i == height - 1 && j >= 1 && j <= width - 2) drawBottom();
			else if (i == height - 1 && j == width - 1) drawBottomRight();
		}
	}

}

void Board::Pushcheck(Judge *J ,int y ,int x)
{
	if (true == J->push_check(map[y][x]))
	{
		if (false == J->turn)
		{
			map[y][x] = 8;
			J->turn = true;
			std::cout << "��"; // black
			J->msg(J->win_check(map));
		}
		else if (true == J->turn)
		{
			map[y][x] = 9;
			J->turn = false;
			std::cout << "��"; // white
			J->msg(J->win_check(map));
		}
	}
}

