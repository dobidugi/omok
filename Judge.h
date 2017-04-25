#ifndef JUDGE_H_
#define JUDGE_H_
#include <vector>
class Judge
{
private:
	int width;
	int height;
	std::vector<std::vector<int>> map;
	bool game = true;
	bool WidthCheck(int value);
	bool HeightCheck(int value);
	bool CrossCheck(int value);
	bool RcrossCheck(int value);
	void msg();
public:
	bool turn = false;
	Judge(int width, int height);
	~Judge();
	bool push_check(int value);
	void win_check(std::vector<std::vector<int>> copy_map);
	bool play();
};
#endif