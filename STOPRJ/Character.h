#pragma once
class Character
{
public:
	Character();
	Character(int attack, int health);
	~Character();

private:
	int attack;
	int health;
};
