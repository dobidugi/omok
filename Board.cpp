#include <iostream>
#include <vector>
#include "Board.h"

Board::Board(int _width, int _hegiht) : width(_width) , height(_hegiht)
{
	system("cls");
	map.assign(height, std::vector<int>(width, 0));
	Board::drawMap(); 
}

Board::~Board() {}

void Board::drawTopLeft() const { std::cout << "¦£"; }
void Board::drawTopCenter() const  { std::cout << "¦¨"; }
void Board::drawTopRight() const { std::cout << "¦¤"; std::cout << "" << std::endl; }

void Board::drawLeft() const  { std::cout << "¦§"; }
void Board::drawCenter() const  { std::cout << "¦«"; }
void Board::drawRight() const  { std::cout << "¦©"; std::cout << "" << std::endl; }

void Board::drawBottomLeft() const  { std::cout << "¦¦"; }
void Board::drawBottom() const  { std::cout << "¦ª"; }
void Board::drawBottomRight() const { std::cout << "¦¥"; }

void Board::drawMap()
{
	for (int i = 0; i<height; i++)
	{
		if (i == 0) drawTopLeft();
		else if (i >= 1 && i <= height - 2) Board::drawLeft();
		else if (i == height - 1)  Board::drawBottomLeft();
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && j >= 1 && j <= width - 2) Board::drawTopCenter();
			else if (i == 0 && j == width - 1)  Board::drawTopRight();
			else if (i != 0 && i <= height - 2 && j >= 1 && j <= width - 2) Board::drawCenter();
			else if (i != 0 && i <= height - 2 && j == width - 1) Board::drawRight();
			else if (i == height - 1 && j >= 1 && j <= width - 2) Board::drawBottom();
			else if (i == height - 1 && j == width - 1) Board::drawBottomRight();
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
			std::cout << "¡Û"; // black
			J->win_check(map);
			J->turn = true;
		}
		else if (true == J->turn)
		{
			map[y][x] = 9;
			std::cout << "¡Ü"; // white
			J->win_check(map);
			J->turn = false;
		}
	}
}

