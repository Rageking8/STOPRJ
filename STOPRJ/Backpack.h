#pragma once
#include <string>

class Backpack
{
public:
	Backpack();
	~Backpack();

	int get_item_qty(std::string item);
	void set_item_qty(std::string item, int new_qty);

private:
	int coin;

	int sword;
	int armour;
	int hp_potion;
	int mp_potion;
};

