#include "Game.h"
#include "Common.h"
#include <string>
#include <random>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include "conio.h"

Game::Game()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	std::ios_base::sync_with_stdio(false);

	board.set_board(97, 0, 1);
	swordsman.set_pos(97, 0);

	int tmp_cam_pos_i1 = 0;
	int tmp_cam_pos_i2 = 0;

	if (swordsman.get_pos(0) < 7) {
		tmp_cam_pos_i1 = 0;
	}
	else if (swordsman.get_pos(0) > 93) {
		tmp_cam_pos_i1 = 86;
	}
	else {
		tmp_cam_pos_i1 = swordsman.get_pos(0) - 7;
	}

	if (swordsman.get_pos(1) < 15) {
		tmp_cam_pos_i2 = 0;
	}
	else if (swordsman.get_pos(1) > 85) {
		tmp_cam_pos_i2 = 86;
	}
	else {
		tmp_cam_pos_i2 = swordsman.get_pos(1) - 15;
	}

	board.set_cam(tmp_cam_pos_i1, tmp_cam_pos_i2);

	board_gen();

	// Note: do not overide
	for (int i = 95; i < 100; ++i) {
		board.set_board(i, 47, 6);
	}

}

Game::~Game()
{
}

void Game::start()
{
	system("cls");

	Common::cursor_vis(false);

	start_menu();

	//story.prologue();

	bool prev_is_map = false;

	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true) {

		// Dont use system("cls") as it causes flicker when the screen is updating
		Common::set_cursor(0, 0);
		board.print_board(prev_is_map);

		Common::set_cursor(0, 31);
		std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \n";

		Common::set_cursor(72, 33);
		std::cout << " ";

		Common::set_cursor(0, 32);
		//std::string action_inp = Common::input("              \nEnter action (WASD for movement and IJKL for interaction, M for menu) : ");
		std::cout << "              \nPress or hold (WASD for movement and IJKL for interaction, M for menu)";

		short tmp_target_cell_val = -1;

		prev_is_map = true;

		// //Loop till action input is valid (WASDIJKL)(non-case sensitive)
		//while (!valid_inp(action_inp)) {

		//	SetConsoleCursorPosition(h, COORD{ 72, 33 });
		//	Common::mul_txt(" ", action_inp.length(), true);

		//	SetConsoleCursorPosition(h, COORD{ 0, 31 });
		//	std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \n";
		//	action_inp = Common::input("Invalid action\nEnter action (WASD for movement and IJKL for interaction, M for menu) : ");
		//}

		std::string action_inp = "";

		while (true) {
			int c = _getch();
			if (c == 224) {
				c = _getch();
				Common::set_cursor(0, 31);
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \nInvalid action\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
				continue;
			}
			switch (c) {
				case 119:
					action_inp = "w";
					break;
				case 97:
					action_inp = "a";
					break;
				case 115:
					action_inp = "s";
					break;
				case 100:
					action_inp = "d";
					break;
				case 87:
					action_inp = "W";
					break;
				case 65:
					action_inp = "A";
					break;
				case 83:
					action_inp = "S";
					break;
				case 68:
					action_inp = "D";
					break;
				case 105:
					action_inp = "i";
					break;
				case 106:
					action_inp = "j";
					break;
				case 107:
					action_inp = "k";
					break;
				case 108:
					action_inp = "l";
					break;
				case 73:
					action_inp = "I";
					break;
				case 74:
					action_inp = "J";
					break;
				case 75:
					action_inp = "K";
					break;
				case 76:
					action_inp = "L";
					break;
				case 109:
					action_inp = "m";
					break;
				case 77:
					action_inp = "M";
					break;
			}

			if (action_inp == "") {
				Common::set_cursor(0, 31);
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \nInvalid action\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
			}
			else {
				break;
			}
		}

		// For player movement (WASD)
		if ((action_inp == "w" || action_inp == "W") && swordsman.get_pos(0) > 0 && board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1)) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('W');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) < 93)
				board.move_cam('W');
		}
		else if ((action_inp == "a" || action_inp == "A") && swordsman.get_pos(1) > 0 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('A');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) < 85)
				board.move_cam('A');
		}
		else if ((action_inp == "s" || action_inp == "S") && swordsman.get_pos(0) < 100 && board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1)) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('S');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) > 7)
				board.move_cam('S');
		}
		else if ((action_inp == "d" || action_inp == "D") && swordsman.get_pos(1) < 100 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('D');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) > 15)
				board.move_cam('D');
		}

		// For player interaction with landmarks (IJKL)
		else if ((action_inp == "i" || action_inp == "I") && swordsman.get_pos(0) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1));

		}
		else if ((action_inp == "j" || action_inp == "J") && swordsman.get_pos(1) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1);

		}
		else if ((action_inp == "k" || action_inp == "K") && swordsman.get_pos(0) < 100) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));

		}
		else if ((action_inp == "l" || action_inp == "L") && swordsman.get_pos(1) < 100) {
			
			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);

		}
		else if ((action_inp == "m" || action_inp == "M")) {
			system("cls");
			Common::cursor_vis(true);
			std::string menu_option = Common::input("===== Menu =====\n1) Character\n2) Backpack\n3) Map\n\nS) Story testing\n\nEnter an option (B for back) : ");
			while (menu_option != "1" && menu_option != "2" && menu_option != "3" && menu_option != "B" && menu_option != "b" && menu_option != "S") {
				system("cls");
				menu_option = Common::input("===== Menu =====\n1) Character\n2) Backpack\n3) Map\n\nS) Story testing\n\nInvalid Input\nEnter an option (B for back) : ");
			}
			
			if (menu_option == "1") {
				system("cls");
				Common::input("====== Character ======\n1) Attack   " + std::to_string(swordsman.get_stats("attack")) + "\n2) Health   " + std::to_string(swordsman.get_stats("cur_health")) + " / " + std::to_string(swordsman.get_stats("max_health")) + "\n3) MP       " + std::to_string(swordsman.get_stats("cur_mp")) + " / " + std::to_string(swordsman.get_stats("max_mp")) + "\n\nPress enter to return ");
			}
			else if (menu_option == "2") {
				system("cls");
				std::string item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nInput the corresponding item number to consume/equip it, or press enter to return : ");
				while (item_inp == "1" || item_inp == "2" || item_inp == "3" || item_inp == "4" || item_inp == "5") {
					if (item_inp == "1") {
						system("cls");
						item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou cannot use your coins here. Please use them at a SHOP : ");
					}
					else if (item_inp == "2") {
						if (swordsman.get_item_qty("sword") > 0) {
							swordsman.set_item_qty("sword", swordsman.get_item_qty("sword") - 1);
							swordsman.set_stats("attack", swordsman.get_stats("attack") + 5);
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have equipped a sword! Your attack is now " + std::to_string(swordsman.get_stats("attack")) + "!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
						else {
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have no swords to equip!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
					}
					else if (item_inp == "3") {
						if (swordsman.get_item_qty("armour") > 0) {
							swordsman.set_item_qty("armour", swordsman.get_item_qty("armour") - 1);
							swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") + 10);
							swordsman.set_stats("max_health", swordsman.get_stats("max_health") + 10);
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have equipped armour! Your max HP is now " + std::to_string(swordsman.get_stats("max_health")) + "!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
						else {
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have no armour to equip!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
					}
					else if (item_inp == "4") {
						if (swordsman.get_item_qty("hp_potion") > 0) {
							swordsman.set_item_qty("hp_potion", swordsman.get_item_qty("hp_potion") - 1);
							if (swordsman.get_stats("max_health") - swordsman.get_stats("cur_health") <= 50) {
								swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
							}
							else {
								swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") + 50);
							}
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have consumed a HP potion! Your current HP is now " + std::to_string(swordsman.get_stats("cur_health")) + "!\nInput the corresponding item number to consume / equip it, or press enter to return : ");
						}
						else {
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have no HP potions to use!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
					}
					else if (item_inp == "5") {
						if (swordsman.get_item_qty("mp_potion") > 0) {
							swordsman.set_item_qty("mp_potion", swordsman.get_item_qty("mp_potion") - 1);
							if (swordsman.get_stats("max_mp") - swordsman.get_stats("cur_mp") <= 50) {
								swordsman.set_stats("cur_mp", swordsman.get_stats("max_mp"));
							}
							else {
								swordsman.set_stats("cur_mp", swordsman.get_stats("cur_mp") + 50);
							}
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have consumed a MP potion! Your current MP is now " + std::to_string(swordsman.get_stats("cur_mp")) + "!\nInput the corresponding item number to consume / equip it, or press enter to return : ");
						}
						else {
							system("cls");
							item_inp = Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nYou have no MP potions to use!\nInput the corresponding item number to consume/equip it, or press enter to return : ");
						}
					}
				}
			}
			else if (menu_option == "3") {
				system("cls");
				board.print_map();
				Common::input("\n# -> Colored blocks\nP -> Player\nS -> Shop\n? -> Special landmarks\n. -> All other landmarks (including empty space)\n\nPress enter to return ");
				system("cls");
			}
			else if (menu_option == "S") {
				story.prologue();

				story.foundCart();
				story.meetElora();
				story.winElora();
				story.loseElora();
				story.recruitElora();

				story.outsideOrionResidence();
				story.meetOrion();
				story.recruitOrion_main();
				story.meetBlaise_main();

				bool blaiseFateDecided = false, blaiseKilled = false;
				std::string blaiseInput = Common::input("What would you like to do?\n1. Kill BLAISE\n2. Recruit BLAISE\n\n");

				while (blaiseInput != "1" && blaiseInput != "2")
				{
					blaiseInput = Common::input("Invalid Input\nWhat would you like to do?\n1. Kill BLAISE\n2. Recruit BLAISE\n\n");
				}

				if (blaiseInput == "1") {
					story.killBlaise_main();
					blaiseKilled = true;
					blaiseFateDecided = true;
				}
				else {
					story.recruitBlaise_main();
					blaiseFateDecided = true;
				}

				story.beforeFightDK_main();
				story.defeatDK_main();
				if (blaiseKilled == false)
				{
					story.blaiseBetrayal_main();
					story.defeatBlaise_main();
				}
				story.ending_main();
			}

			prev_is_map = false;
			Common::cursor_vis(false);
		}

		// Ambush by the archer troops
		if (swordsman.get_pos(1) == 47 && swordsman.get_pos(0) >= 95 && swordsman.get_pos(0) <= 99) {
			Common::cursor_vis(true);
			start_battle("ambush");

			prev_is_map = false;

			Common::cursor_vis(false);
		}

		if (tmp_target_cell_val == 3) {
			switch (shops[0].open_shop(swordsman.get_item_qty("coin"))) {
			case 'B':
			case 'b':
				break;
			case '1':
				swordsman.set_item_qty("sword", swordsman.get_item_qty("sword") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 10);
				break;
			case '2':
				swordsman.set_item_qty("armour", swordsman.get_item_qty("armour") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 20);
				break;
			case '3':
				swordsman.set_item_qty("mp_potion", swordsman.get_item_qty("mp_potion") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 5);
				break;
			case '4':
				swordsman.set_item_qty("hp_potion", swordsman.get_item_qty("hp_potion") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 5);
				break;
			}

			prev_is_map = false;
		}
		else if (tmp_target_cell_val == 5) {
			story.foundCart();
			for (int i = 95; i < 100; ++i) {
				board.set_board(i, 47, 0);
			}

			prev_is_map = false;
		}

	}
}

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L" || inp == "m" || inp == "M");
}

void Game::start_battle(std::string id)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	Character enemy[4];

	if (id == "ambush") {
		for (int i = 0; i < 4; ++i) {
			enemy[i].set_name("Archer Troop");
			enemy[i].set_stats("cur_health", 10);
			enemy[i].set_stats("max_health", 10);
			enemy[i].set_stats("cur_mp", 20);
			enemy[i].set_stats("max_mp", 20);
			enemy[i].init_skill("shoot_arrow", "raining_arrow", "piercing_arrow", "bullet_arrow");
		}
	}

	bool slot_active[8]{};

	for (int i = 0; i < 4; ++i) {
		if (enemy[i].get_name() != "") {
			slot_active[i] = true;
		}
	}
	slot_active[4] = (swordsman.get_stats("cur_health") > 0);
	slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
	slot_active[6] = (archer.get_recruited() && (archer.get_stats("cur_health") > 0));
	slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

	int current_turn = -1;
	for (int i = 4; i < 8; ++i) {
		if (slot_active[i]) {
			current_turn = i;
			break;
		}
	}

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (slot_active[i]) {
				if (current_turn == i)
					SetConsoleTextAttribute(h, 0x09);

				Common::set_cursor(i * 25, 0);
				std::cout << "|======================| ";
				Common::set_cursor(i * 25, 1);
				std::cout << "| " << enemy[i].get_name() << Common::mul_txt(" ", 21 - enemy[i].get_name().length()) << "| ";
				Common::set_cursor(i * 25, 2);
				std::cout << "| Attack : " << enemy[i].get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(enemy[i].get_stats("attack"))) << "| ";
				Common::set_cursor(i * 25, 3);
				std::cout << "| Health : " << enemy[i].get_stats("cur_health") << " / " << enemy[i].get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(enemy[i].get_stats("cur_health")) + 3 + Common::int_len(enemy[i].get_stats("max_health")))) << "| ";
				Common::set_cursor(i * 25, 4);
				std::cout << "| MP : " << enemy[i].get_stats("cur_mp") << " / " << enemy[i].get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(enemy[i].get_stats("cur_mp")) + 3 + Common::int_len(enemy[i].get_stats("max_mp")))) << "| ";
				Common::set_cursor(i * 25, 5);
				std::cout << "|                      | ";

				for (int i2 = 0; i2 < 4; ++i2) {
					Common::set_cursor(i * 25, 6 + i2);
					if (enemy[i].get_skill_list(i2).active) {
						std::string tmp_skill_name = enemy[i].get_skill_list(i2).name;
						std::cout << "| " << i2 + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
					}
					else {
						std::cout << "|                      | ";
					}
				}

				Common::set_cursor(i * 25, 10);
				std::cout << "|======================| ";

				if (current_turn == i)
					SetConsoleTextAttribute(h, 0x07);
			}
		}

		if (slot_active[4]) {
			if (current_turn == 4)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(0, 15);
			std::cout << "|======================| ";
			Common::set_cursor(0, 16);
			std::cout << "| " << swordsman.get_name() << Common::mul_txt(" ", 21 - swordsman.get_name().length()) << "| ";
			Common::set_cursor(0, 17);
			std::cout << "| Attack : " << swordsman.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(swordsman.get_stats("attack"))) << "| ";
			Common::set_cursor(0, 18);
			std::cout << "| Health : " << swordsman.get_stats("cur_health") << " / " << swordsman.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(swordsman.get_stats("cur_health")) + 3 + Common::int_len(swordsman.get_stats("max_health")))) << "| ";
			Common::set_cursor(0, 19);
			std::cout << "| MP : " << swordsman.get_stats("cur_mp") << " / " << swordsman.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(swordsman.get_stats("cur_mp")) + 3 + Common::int_len(swordsman.get_stats("max_mp")))) << "| ";
			Common::set_cursor(0, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(0, 21 + i);
				if (swordsman.get_skill_list(i).active) {
					std::string tmp_skill_name = swordsman.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(0, 25);
			std::cout << "|======================| ";

			if (current_turn == 4)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[5]) {
			if (current_turn == 5)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(25, 15);
			std::cout << "|======================| ";
			Common::set_cursor(25, 16);
			std::cout << "| " << mage.get_name() << Common::mul_txt(" ", 21 - mage.get_name().length()) << "| ";
			Common::set_cursor(25, 17);
			std::cout << "| Attack : " << mage.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(mage.get_stats("attack"))) << "| ";
			Common::set_cursor(25, 18);
			std::cout << "| Health : " << mage.get_stats("cur_health") << " / " << mage.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(mage.get_stats("cur_health")) + 3 + Common::int_len(mage.get_stats("max_health")))) << "| ";
			Common::set_cursor(25, 19);
			std::cout << "| MP : " << mage.get_stats("cur_mp") << " / " << mage.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(mage.get_stats("cur_mp")) + 3 + Common::int_len(mage.get_stats("max_mp")))) << "| ";
			Common::set_cursor(25, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(25, 21 + i);
				if (mage.get_skill_list(i).active) {
					std::string tmp_skill_name = mage.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(25, 25);
			std::cout << "|======================| ";

			if (current_turn == 5)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[6]) {
			if (current_turn == 6)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(50, 15);
			std::cout << "|======================| ";
			Common::set_cursor(50, 16);
			std::cout << "| " << archer.get_name() << Common::mul_txt(" ", 21 - archer.get_name().length()) << "| ";
			Common::set_cursor(50, 17);
			std::cout << "| Attack : " << archer.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(archer.get_stats("attack"))) << "| ";
			Common::set_cursor(50, 18);
			std::cout << "| Health : " << archer.get_stats("cur_health") << " / " << archer.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(archer.get_stats("cur_health")) + 3 + Common::int_len(archer.get_stats("max_health")))) << "| ";
			Common::set_cursor(50, 19);
			std::cout << "| MP : " << archer.get_stats("cur_mp") << " / " << archer.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(archer.get_stats("cur_mp")) + 3 + Common::int_len(archer.get_stats("max_mp")))) << "| ";
			Common::set_cursor(50, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(50, 21 + i);
				if (archer.get_skill_list(i).active) {
					std::string tmp_skill_name = archer.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(50, 25);
			std::cout << "|======================| ";

			if (current_turn == 6)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[7]) {
			if (current_turn == 7)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(75, 15);
			std::cout << "|======================| ";
			Common::set_cursor(75, 16);
			std::cout << "| " << assassin.get_name() << Common::mul_txt(" ", 21 - assassin.get_name().length()) << "| ";
			Common::set_cursor(75, 17);
			std::cout << "| Attack : " << assassin.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(assassin.get_stats("attack"))) << "| ";
			Common::set_cursor(75, 18);
			std::cout << "| Health : " << assassin.get_stats("cur_health") << " / " << assassin.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(assassin.get_stats("cur_health")) + 3 + Common::int_len(assassin.get_stats("max_health")))) << "| ";
			Common::set_cursor(75, 19);
			std::cout << "| MP : " << assassin.get_stats("cur_mp") << " / " << assassin.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(assassin.get_stats("cur_mp")) + 3 + Common::int_len(assassin.get_stats("max_mp")))) << "| ";
			Common::set_cursor(75, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(75, 21 + i);
				if (assassin.get_skill_list(i).active) {
					std::string tmp_skill_name = assassin.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(75, 25);
			std::cout << "|======================| ";

			if (current_turn == 7)
				SetConsoleTextAttribute(h, 0x07);
		}

		Common::set_cursor(0, 27);
		if (current_turn > 3) {
			// Allies turn

			bool cast_skill = true;

			std::string skill_input = Common::input("                             \nEnter which skill to cast (S for skill book) : ");
			while ((skill_input != "1" && skill_input != "2" && skill_input != "3" && skill_input != "4" && skill_input != "S" && skill_input != "s") ||
				((skill_input != "S" && skill_input != "s") &&

					((current_turn == 4 && (!swordsman.get_skill_list(std::stoi(skill_input) - 1).active || swordsman.get_stats("cur_mp") < swordsman.get_skill_list(std::stoi(skill_input) - 1).cost)) ||
						
						(current_turn == 5 && (!mage.get_skill_list(std::stoi(skill_input) - 1).active || mage.get_stats("cur_mp") < mage.get_skill_list(std::stoi(skill_input) - 1).cost)) ||
						
						(current_turn == 6 && (!archer.get_skill_list(std::stoi(skill_input) - 1).active || archer.get_stats("cur_mp") < archer.get_skill_list(std::stoi(skill_input) - 1).cost)) ||
						
						(current_turn == 7 && (!assassin.get_skill_list(std::stoi(skill_input) - 1).active || assassin.get_stats("cur_mp") < assassin.get_skill_list(std::stoi(skill_input) - 1).cost))))) {

				Common::set_cursor(47, 28);
				for (unsigned i = 0; i < skill_input.length(); ++i)
					std::cout << " ";
				Common::set_cursor(0, 27);
				skill_input = Common::input("Invalid skill / Not enough MP\nEnter which skill to cast (S for skill book) : ");
			}

			if (skill_input == "S" || skill_input == "s") {
				print_all_skill();
				system("cls");
				cast_skill = false;
			}
			else {
				int tmp_pow = 0;
				char tmp_skill_type = ' ';

				if (current_turn == 4) {
					if (swordsman.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = swordsman.get_stats("attack") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (swordsman.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						swordsman.set_stats("attack", swordsman.get_stats("attack") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power);
						if (swordsman.get_stats("cur_health") > swordsman.get_stats("max_health"))
							swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
					}

					swordsman.set_stats("cur_mp", swordsman.get_stats("cur_mp") - swordsman.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 5) {
					if (mage.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = mage.get_stats("attack") + mage.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (mage.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						mage.set_stats("attack", mage.get_stats("attack") + mage.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						mage.set_stats("cur_health", mage.get_stats("cur_health") + mage.get_skill_list(std::stoi(skill_input) - 1).power);
						if (mage.get_stats("cur_health") > mage.get_stats("max_health"))
							mage.set_stats("cur_health", mage.get_stats("max_health"));
					}

					mage.set_stats("cur_mp", mage.get_stats("cur_mp") - mage.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 6) {
					if (archer.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = archer.get_stats("attack") + archer.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (archer.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						archer.set_stats("attack", archer.get_stats("attack") + archer.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						archer.set_stats("cur_health", archer.get_stats("cur_health") + archer.get_skill_list(std::stoi(skill_input) - 1).power);
						if (archer.get_stats("cur_health") > archer.get_stats("max_health"))
							archer.set_stats("cur_health", archer.get_stats("max_health"));
					}
					archer.set_stats("cur_mp", archer.get_stats("cur_mp") - archer.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 7) {
					if (assassin.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = assassin.get_stats("attack") + assassin.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (assassin.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						assassin.set_stats("attack", assassin.get_stats("attack") + assassin.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						assassin.set_stats("cur_health", assassin.get_stats("cur_health") + assassin.get_skill_list(std::stoi(skill_input) - 1).power);
						if (assassin.get_stats("cur_health") > assassin.get_stats("max_health"))
							assassin.set_stats("cur_health", assassin.get_stats("max_health"));
					}
					assassin.set_stats("cur_mp", assassin.get_stats("cur_mp") - assassin.get_skill_list(std::stoi(skill_input) - 1).cost);
				}

				if (tmp_skill_type == 'D') {
					int tmp_active_enemy[4]{};
					int current_idx = 0;
					for (int i = 0; i < 4; ++i) {
						if (slot_active[i]) {
							tmp_active_enemy[current_idx] = i;
							current_idx++;
						}
					}
					int tmp_rand_enemy = tmp_active_enemy[Common::rand_int(0, current_idx - 1)];

					enemy[tmp_rand_enemy].set_stats("cur_health", enemy[tmp_rand_enemy].get_stats("cur_health") - tmp_pow);

					if (enemy[tmp_rand_enemy].get_stats("cur_health") <= 0) {
						for (int i = 0; i < 11; ++i) {
							Common::set_cursor(tmp_rand_enemy * 25, i);
							std::cout << "                         ";
						}
					}

					for (int i = 0; i < 4; ++i)
						slot_active[i] = (enemy[i].get_name() != "" && enemy[i].get_stats("cur_health") > 0);
					slot_active[4] = (swordsman.get_stats("cur_health") > 0);
					slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
					slot_active[6] = (archer.get_recruited() && (archer.get_stats("cur_health") > 0));
					slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

					if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
						// Enemy all dead

						system("cls");
						std::cout << "You Won";
						break;
					}
					else if (!slot_active[4] && !slot_active[5] && !slot_active[6] && !slot_active[7]) {
						// Ally all dead

						system("cls");
						std::cout << "You lose";
						break;
					}
				}

				int tmp_active_ally[4]{};
				int current_idx = 0;
				for (int i = 4; i < 8; ++i) {
					if (slot_active[i]) {
						tmp_active_ally[current_idx] = i;
						current_idx++;
					}
				}
				for (int i = 0; i < current_idx; ++i) {
					if (tmp_active_ally[i] == current_turn && i < current_idx - 1) {
						current_turn = tmp_active_ally[i + 1];
						break;
					}
					else if (tmp_active_ally[i] == current_turn && i == current_idx - 1) {
						for (int i2 = 0; i2 < 4; ++i2) {
							if (slot_active[i2]) {
								current_turn = i2;
								break;
							}
						}
					}
				}
			}

		}
		else if (current_turn >= 0) {
			// Enemy turn

			int tmp_active_ally[4]{};
			int current_idx = 0;
			for (int i = 4; i < 8; ++i) {
				if (slot_active[i]) {
					tmp_active_ally[current_idx] = i;
					current_idx++;
				}
			}
			int tmp_rand_ally = tmp_active_ally[Common::rand_int(0, current_idx - 1)];

			for (int i = 3; i >= 0; --i) {
				if (enemy[current_turn].get_skill_list(i).cost <= enemy[current_turn].get_stats("cur_mp") && enemy[current_turn].get_skill_list(i).active) {
					if (enemy[current_turn].get_skill_list(i).skill_type == 'A') {
						enemy[current_turn].set_stats("attack", enemy[current_turn].get_stats("attack") + enemy[current_turn].get_skill_list(i).power);
					}
					else if (enemy[current_turn].get_skill_list(i).skill_type == 'H') {
						enemy[current_turn].set_stats("cur_health", enemy[current_turn].get_stats("cur_health") + enemy[current_turn].get_skill_list(i).power);
						if (enemy[current_turn].get_stats("cur_health") > enemy[current_turn].get_stats("max_health"))
							enemy[current_turn].set_stats("cur_health", enemy[current_turn].get_stats("max_health"));
					}
					else {
						switch (tmp_rand_ally) {
							case 4:
								swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

								if (swordsman.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(0, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 5:
								mage.set_stats("cur_health", mage.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

								if (mage.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(25, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 6:
								archer.set_stats("cur_health", archer.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

								if (archer.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(50, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 7:
								assassin.set_stats("cur_health", assassin.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

								if (assassin.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(75, i2);
										std::cout << "                         ";
									}
								}
								break;
						}
					}
					break;
				}
			}

			for (int i = 0; i < 4; ++i)
				slot_active[i] = (enemy[i].get_name() != "" && enemy[i].get_stats("cur_health") > 0);
			slot_active[4] = (swordsman.get_stats("cur_health") > 0);
			slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
			slot_active[6] = (archer.get_recruited() && (archer.get_stats("cur_health") > 0));
			slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

			if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
				// Enemy all dead

				system("cls");
				std::cout << "You Won";
				break;
			}
			else if (!slot_active[4] && !slot_active[5] && !slot_active[6] && !slot_active[7]) {
				// Ally all dead

				system("cls");
				std::cout << "You lose";
				break;
			}

			int tmp_active_enemy[4]{};
			current_idx = 0;
			for (int i = 0; i < 4; ++i) {
				if (slot_active[i]) {
					tmp_active_enemy[current_idx] = i;
					current_idx++;
				}
			}
			for (int i = 0; i < current_idx; ++i) {
				if (tmp_active_enemy[i] == current_turn && i < current_idx - 1) {
					current_turn = tmp_active_enemy[i + 1];
					break;
				}
				else if (tmp_active_enemy[i] == current_turn && i == current_idx - 1) {
					for (int i2 = 4; i2 < 8; ++i2) {
						if (slot_active[i2]) {
							current_turn = i2;
							break;
						}
					}
				}
			}

			Sleep(1000);
		}

		Common::set_cursor(47, 28);
		std::cout << " ";
	}
}

void Game::print_all_skill()
{
	system("cls");

	const char* skill_name[]{ "Slash", "Fire Slash", "Taunt", "Spiral Spin", "Arcane Bullet", "Healing", "Enchant", "Fireball", "Shoot Arrow", "Raining Arrow", "Piercing Arrow", "Bullet Arrow", "Danger Poke", "Strength Dart", "Bomb", "Backstab", "Headbutt", "Shield Bash", "Arm Slap", "Demon Slash", "Demon Eye Beam", "Demon Strength", "Fire Breath", "Demon Punch", "Long live The King", "Demon Summon", "Hellfire" };
	const int power[]{ 5, 10, 5, 60, 3, 50, 10, 100, 5, 10, 30, 60, 5, 10, 45, 125, 10, 15, 30, 30, 90, 10, 100, 40, 50, 20, 100 };
	const int cost[]{ 0, 5, 10, 15, 0, 20, 30, 100, 0, 5, 10, 45, 0, 20, 15, 35, 10, 15, 15, 0, 20, 40, 100, 0, 20, 40, 100 };
	const char* types = "DDADDHADDDDDDADDDDDDDADDHAD";

	std::cout << "Skill Book\n\n";
	for (int i = 0; i < 27; ++i) {
		switch (types[i]) {
			case 'D':
				Common::color_print(0x0C, skill_name[i]);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )\n - Deals ";
				Common::color_print(0x0E, power[i]);
				std::cout << " damage";
				break;
			case 'A':
				Common::color_print(0x09, skill_name[i]);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )\n - Increase attack by ";
				Common::color_print(0x0E, power[i]);
				break;
			case 'H':
				Common::color_print(0x0A, skill_name[i]);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )\n - Increase health by ";
				Common::color_print(0x0E, power[i]);
				break;
		}
		std::cout << "\n\n";
	}

	Common::input("Press enter to return ");
}
