#include "Character.h"

Character::Character() : attack{}, health{}, pos{}
{
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