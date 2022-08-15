#pragma once
class Character
{
public:
	Character();
	~Character();

	void set_pos(int idx1, int idx2);
	int get_pos(int idx);
	void move(char dir);

private:
	int attack;
	int health;

	int pos[2];
};
