#include "Character.h"

Character::Character() : attack{}, cur_health{}, max_health{}, cur_mp{}, max_mp{}, pos{}
{
	name = "";
	set_item_qty("coin", 20);
	recruited = false;
}

Character::~Character()
{
}

void Character::set_pos(int idx1, int idx2)
{
	pos[0] = idx1;
	pos[1] = idx2;
}

int Character::get_pos(int idx)
{
	return (idx >= 0 && idx <= 1) ? pos[idx] : -1;
}

void Character::set_stats(std::string stats, int new_amt)
{
	if (new_amt <= 1000) {
		if (stats == "attack")
			attack = (new_amt < 0) ? 0 : new_amt;
		else if (stats == "cur_health")
			cur_health = (new_amt < 0) ? 0 : new_amt;
		else if (stats == "max_health")
			max_health = (new_amt < 0) ? 0 : new_amt;
		else if (stats == "cur_mp")
			cur_mp = (new_amt < 0) ? 0 : new_amt;
		else if (stats == "max_mp")
			max_mp = (new_amt < 0) ? 0 : new_amt;
	}
}

int Character::get_stats(std::string stats)
{
	if (stats == "attack")
		return attack;
	else if (stats == "cur_health")
		return cur_health;
	else if (stats == "max_health")
		return max_health;
	else if (stats == "cur_mp")
		return cur_mp;
	else if (stats == "max_mp")
		return max_mp;
	return -1;
}

void Character::set_name(std::string new_name)
{
	if (name == "")
		name = new_name;
}

std::string Character::get_name()
{
	return name;
}

void Character::move(char dir)
{
	if (dir == 'W' && pos[0] > 0)
		pos[0] -= 1;
	else if (dir == 'A' && pos[1] > 0)
		pos[1] -= 1;
	else if (dir == 'S' && pos[0] < 100)
		pos[0] += 1;
	else if (dir == 'D' && pos[1] < 100)
		pos[1] += 1;
}

bool Character::get_recruited()
{
	return recruited;
}
