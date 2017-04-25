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
	void drawTopLeft() const;
	void drawTopCenter() const;
	void drawTopRight() const;

	void drawLeft() const;
	void drawCenter() const;
	void drawRight() const;

	void drawBottomLeft() const;
	void drawBottom() const;
	void drawBottomRight() const;
public:
	Board(int width, int height);
	~Board();
	void Pushcheck(Judge *J,int y,int x);
};

#endif 
