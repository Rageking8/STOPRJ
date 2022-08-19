#include "Shop.h"
#include "Common.h"
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
	system("cls");

	const char* items[]{ "Sword       ", "Armor       ", "MP Potion   ", "HP Potion   " };
	const char* description[]{ "   It raises your base attack   ", "   It raises your max health    ", "   It restores your MP          ", "   It restores your HP          " };
	int price[]{ 10, 20, 5, 5 };

	std::cout << "========================================= Shop =========================================\n||       ||   ITEM        ||   Description                  ||   Price   ||   Stock   ||\n";
	for (int i = 0; i < 4; i++) {
		std::cout << "||   " << (i + 1) << "   ||   " << items[i] << "||" << description[i] << "||   " << price[i] << "G" << (i < 2 ? "     " : "      ") << "||   " << stock[i] << (i < 2 ? "       " : "      ") << "||\n";
	}
	std::cout << "========================================================================================\n\nYou have " << player_coins << "G\n\nEnter which to buy ( B for back ) : ";

	std::string shop_inp;
	std::getline(std::cin, shop_inp);
	while (shop_inp != "1" && shop_inp != "2" && shop_inp != "3" && shop_inp != "4" && shop_inp != "B" && shop_inp != "b") {
		std::cout << "Invalid shop input\nEnter which to buy ( B for back ) : ";
		std::getline(std::cin, shop_inp);
	}

	if (shop_inp[0] >= '1' && shop_inp[0] <= '4') {
		int temp_idx = shop_inp[0] - '1';

		char ret = ' ';

		if (stock[temp_idx] <= 0) {
			std::cout << "Sorry we are out of stock for that item\n";
		}
		else if (player_coins >= price[temp_idx]) {
			system("cls");
			player_coins -= price[temp_idx];
			stock[temp_idx] -= 1;
			std::cout << "========================================= Shop =========================================\n||       ||   ITEM        ||   Description                  ||   Price   ||   Stock   ||\n";
			for (int i = 0; i < 4; i++) {
				std::cout << "||   " << (i + 1) << "   ||   " << items[i] << "||" << description[i] << "||   " << price[i] << "G" << (i < 2 ? "     " : "      ") << "||   " << stock[i] << (i < 2 ? "       " : "      ") << "||\n";
			}
			std::cout << "========================================================================================\n\n";
			std::cout << "You have bought " << items[temp_idx] << "\nYou have " << player_coins << "G left\n";

			ret = temp_idx + '1';
		}
		else {
			std::cout << "You do not have enough money to buy that!\n";
		}

		Common::input("\nPress enter to return ");

		return ret;
	}
	else {
		return 'b';
	}

}
