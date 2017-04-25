#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
	int x;
	int y;
	int loop_x;
	int loop_y;
	//bool push = TRUE;
	void gotoxy(int get_x, int get_y);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
public:
	Player(int width,int height);
	int move();
	int GetX() const;
	int GetY() const;
};
#endif