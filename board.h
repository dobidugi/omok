#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
class board
{

private:
	int x;
	int y;
	void drawMap();
public:
	board(int _x,int _y);
	~board();
	int **arr;
	void test();
};

#endif