#ifndef JUDGE_H_
#define JUDGE_H_
#include <vector>
class Judge
{
private:
	int width;
	int height;
	bool turn = 0;
	bool game = true;
	std::vector<std::vector<int>> map;
	void push(int y,int x);
	void msg(bool A);
public:
	Judge(int width, int height);
	bool push_check(int check_x, int check_y);
	bool win_check();
	bool play();
};


#endif