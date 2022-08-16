#include "Character.h"

Character::Character() : attack{}, cur_health{ 50 }, max_health{ 50 }, mp{}, pos{}
{
	set_item_qty("coin", 50);
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
	if (stats == "attack" && (new_amt >= 0 && new_amt <= 1000))
		attack = new_amt;
	else if (stats == "cur_health" && (new_amt >= 0 && new_amt <= 1000))
		cur_health = new_amt;
	else if (stats == "max_health" && (new_amt >= 0 && new_amt <= 1000))
		max_health = new_amt;
	else if (stats == "mp" && (new_amt >= 0 && new_amt <= 1000))
		mp = new_amt;
}

int Character::get_stats(std::string stats)
{
	if (stats == "attack")
		return attack;
	else if (stats == "cur_health")
		return cur_health;
	else if (stats == "max_health")
		return max_health;
	else if (stats == "mp")
		return mp;
	return -1;
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