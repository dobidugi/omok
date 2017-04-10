#ifndef BOARD_H_
#define BOARD_H_

class board
{

private:
	int x;
	int y;
	
public:
	board(int size);
	void drawMap();
};

#endif