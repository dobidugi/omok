#include <vector>

#ifndef OMOK_H_
#define OMOK_H_
#define _X 20
#define _Y 20
class Omok {
private:
	bool turn = 0;
	bool game = 1;
	int x;
	int y;
	int loop_x;
	int loop_y;
	std::vector<std::vector<int>> arr;
	void gotoxy(int g_x, int g_y);
	void msg(int i);
	void drawMap();
public:
	bool check_win(); // cehck_winner
	void move(); // move key
	//void start();
	bool set();
	Omok(int x,int y);
	~Omok();
};
#endif