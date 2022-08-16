#pragma once

class Shop
{
	int stock[4];

public:
	Shop();
	~Shop();

	char open_shop(int player_coins);
};

