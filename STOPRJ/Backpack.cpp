#include "Backpack.h"

Backpack::Backpack() : coin{}, atk_potion{}, vit_potion{}, hp_potion{}, mp_potion{}
{
}

Backpack::~Backpack()
{
}

int Backpack::get_item_qty(std::string item)
{
	if (item == "coin")
		return coin;
	else if (item == "atk_potion")
		return atk_potion;
	else if (item == "vit_potion")
		return vit_potion;
	else if (item == "hp_potion")
		return hp_potion;
	else if (item == "mp_potion")
		return mp_potion;
	return -1;
}

void Backpack::set_item_qty(std::string item, int new_qty)
{
	if (item == "coin" && new_qty >= 0 && new_qty <= 1000)
		coin = new_qty;
	else if (item == "atk_potion" && new_qty >= 0 && new_qty <= 1000)
		atk_potion = new_qty;
	else if (item == "vit_potion" && new_qty >= 0 && new_qty <= 1000)
		vit_potion = new_qty;
	else if (item == "hp_potion" && new_qty >= 0 && new_qty <= 1000)
		hp_potion = new_qty;
	else if (item == "mp_potion" && new_qty >= 0 && new_qty <= 1000)
		mp_potion = new_qty;
}
