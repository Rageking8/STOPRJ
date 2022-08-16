#pragma once
#include "Backpack.h"
#include <string>

class Character : public Backpack
{
public:
	Character();
	~Character();

	void set_pos(int idx1, int idx2);
	int get_pos(int idx);
	void set_stats(std::string stats, int new_amt);
	int get_stats(std::string stats);

	void move(char dir);

private:
	int attack;
	int cur_health;
	int max_health;
	int mp;

	int pos[2];
};
