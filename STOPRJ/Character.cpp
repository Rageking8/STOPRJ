#include "Character.h"

Character::Character() : attack{}, health{}
{
}

Character::Character(int attack, int health)
{
	this->attack = attack;
	this->health = health;
}

Character::~Character()
{
}
