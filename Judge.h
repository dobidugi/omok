#ifndef JUDGE_H_
#define JUDGE_H_
#include <vector>
class Judge
{
private:
	int width;
	int height;
	bool game = true;
	std::vector<std::vector<int>> map;
public:
	bool turn = false;
	Judge(int width, int height);
	bool push_check(int value);
	bool win_check(std::vector<std::vector<int>> map);
	void msg(bool A);
	bool play();
};


#endif