#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include "Judge.h"
class Board
{
private:
	int width;
	int height;
	void drawMap();
	std::vector<std::vector<int>> map;
public:
	Board(int width, int height);
	void Pushcheck(Judge *J,int y,int x);
};

#endif 
