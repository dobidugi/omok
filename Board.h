#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
class Board
{
private:
	int width;
	int height;
	void drawMap();
	
public:
	Board(int width, int height);
	
};

#endif 
