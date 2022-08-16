#pragma once

class Shop
{
public:
	Shop();
	~Shop();

	char open_shop(int player_coins);

private:
	int stock[4];
};

