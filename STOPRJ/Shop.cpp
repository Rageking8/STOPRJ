#include "Shop.h"
#include "Character.h"
#include "Common.h"
#include "conio.h"
#include <iostream>
#include <string>

Shop::Shop()
{
	stock[0] = 1;
	stock[1] = 1;
	stock[2] = 10;
	stock[3] = 10;
}

Shop::~Shop()
{
}

char Shop::open_shop(int player_coins)
{
	Common::set_cursor(0, 0);
	const char* items[]{ "SWORD", "ARMOUR", "MP POTION", "HP POTION" };
	const char* description[]{ "Increases base attack by 5.      ", "Increases max HP by 10.      ", "Restores 50 MP.      ", "Restores 50 HP.      " };
	int price[]{ 10, 20, 5, 5 };

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}
	for (int i = 1; i < 30; ++i) {
		Common::set_cursor(0, i);
		Common::color_print(0xE0, "  ");

		if (i == 1 || i == 29) {
			Common::color_print(0xE0, "  ");
			Common::set_cursor(121, i);
			Common::color_print(0xE0, "    ");
		}
		else {
			Common::set_cursor(123, i);
			Common::color_print(0xE0, "  ");
		}
	}

	Common::set_cursor(0, 11);

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}

	Common::set_cursor(0, 15);

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}

	Common::set_cursor(0, 30);

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}

	for (int i = 0; i < 2; ++i) {
		Common::set_cursor(49, 3 + (5 * i));
		Common::color_print(0x60, "    ");

		Common::set_cursor(48, 4 + (3 * i));
		Common::color_print(0x60, "  ");
		std::cout << "  ";
		Common::color_print(0x60, "  ");

		Common::set_cursor(49 + (2 * i), 5 + (1 * i));
		Common::color_print(0x60, "  ");

		for (int i2 = 0; i2 < 6; ++i2) {
			Common::set_cursor(56 + (4 * i), 3 + (1 * i2));
			Common::color_print(0x60, "  ");

			Common::set_cursor(72, 3 + (1 * i2));
			Common::color_print(0x60, "  ");
		}

		Common::set_cursor(65, 3 + (5 * i));
		Common::color_print(0x60, "    ");

		for (int i2 = 0; i2 < 4; ++i2) {
			Common::set_cursor(64 + (4 * i), 4 + (1 * i2));
			Common::color_print(0x60, "  ");
		}

		Common::set_cursor(56 + (16 * i), 5);
		Common::color_print(0x60, "     ");
	}

	Common::set_cursor(72, 3);
	Common::color_print(0x60, "     ");

	Common::set_cursor(76, 4);
	Common::color_print(0x60, "  ");

	Common::set_cursor(55, 13);
	Common::color_print(0x06, "CURRENT SUPPLY:\n");

	for (int i = 0; i < 4; i++) {
		Common::set_cursor(41, 17 + (2 * i));
		std::cout << (i + 1) << ") " << items[i] << " [" << stock[i] << "] : " << price[i] << "G - " << description[i];
	}

	Common::set_cursor(47, 25);
	std::cout << "You currently have " << player_coins << "G on hand.       ";

	Common::set_cursor(28, 26);
	std::string shop_inp = "";
	std::cout << "What would you like to buy? Enter your choice here (B for back) :  ";

	bool tmp_flag = true;
	while (tmp_flag) {
		Common::set_cursor(94, 26);
		int c = _getch();
		if (c == 224) {
			c = _getch();
			Common::set_cursor(28, 27);
			Common::color_print(0x0c, "Invalid input! Please try again.");
			continue;
		}
		switch (c) {
			case 49:
				shop_inp = "1";
				tmp_flag = false;
				break;
			case 50:
				shop_inp = "2";
				tmp_flag = false;
				break;
			case 51:
				shop_inp = "3";
				tmp_flag = false;
				break;
			case 52:
				shop_inp = "4";
				tmp_flag = false;
				break;
			case 98:
				shop_inp = "b";
				tmp_flag = false;
				break;
			case 66:
				shop_inp = "B";
				tmp_flag = false;
				break;
		}
		if (shop_inp == "") {
			Common::set_cursor(28, 27);
			Common::color_print(0x0c, "Invalid input! Please try again.");
		}
	}

	if (shop_inp[0] >= '1' && shop_inp[0] <= '4') {
		int temp_idx = shop_inp[0] - '1';

		char ret = ' ';

		if (stock[temp_idx] <= 0) {
			Common::set_cursor(28, 27);
			Common::color_print(0x0c, "Sorry, we are out of that item's stock! ");
		}
		else if (player_coins >= price[temp_idx]) {
			player_coins -= price[temp_idx];
			stock[temp_idx] -= 1;

			for (int i = 0; i < 4; i++) {
				Common::set_cursor(41, 17 + (2 * i));
				std::cout << (i + 1) << ") " << items[i] << " [" << stock[i] << "] : " << price[i] << "G - " << description[i];
			}

			Common::set_cursor(47, 25);
			std::cout << "You currently have " << player_coins << "G on hand.       ";

			Common::set_cursor(37, 27);
			Common::color_print(0x0a, "You have bought ");
			Common::color_print(0x0a, items[temp_idx]);
			Common::color_print(0x0a, "! ");

			ret = temp_idx + '1';
		}
		else if (player_coins < price[temp_idx]) {
			Common::set_cursor(28, 27);
			Common::color_print(0x0c, "You do not have enough money to buy that! ");
		}
		return ret;
	}
	else {
		return 'b';
	}
}
