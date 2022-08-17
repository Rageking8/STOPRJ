#pragma once
#include "Backpack.h"
#include "Skill.h"
#include <string>

class Character : public Backpack, public Skill
{
public:
	Character();
	~Character();

	void set_pos(int idx1, int idx2);
	int get_pos(int idx);
	void set_stats(std::string stats, int new_amt);
	int get_stats(std::string stats);

	void set_name(std::string new_name);
	std::string get_name();

	void move(char dir);

	bool get_recruited();

protected:
	std::string name;

	int attack;
	int cur_health;
	int max_health;
	int cur_mp;
	int max_mp;

	int pos[2];

	bool recruited;
};
