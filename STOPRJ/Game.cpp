#include "Game.h"
#include "Common.h"
#include <string>
#include <random>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include "conio.h"

Game::Game() : trigger_counter{}
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
	else if (swordsman.get_pos(0) > 143) {
		tmp_cam_pos_i1 = 136;
	}
	else {
		tmp_cam_pos_i1 = swordsman.get_pos(0) - 7;
	}

	if (swordsman.get_pos(1) < 15) {
		tmp_cam_pos_i2 = 0;
	}
	else if (swordsman.get_pos(1) > 135) {
		tmp_cam_pos_i2 = 136;
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
		std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \n";

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
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \nInvalid action\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
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
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \nInvalid action\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
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

			if (swordsman.get_pos(0) < 143)
				board.move_cam('W');
		}
		else if ((action_inp == "a" || action_inp == "A") && swordsman.get_pos(1) > 0 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('A');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) < 135)
				board.move_cam('A');
		}
		else if ((action_inp == "s" || action_inp == "S") && swordsman.get_pos(0) < 150 && board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1)) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('S');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) > 7)
				board.move_cam('S');
		}
		else if ((action_inp == "d" || action_inp == "D") && swordsman.get_pos(1) < 150 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1) == 0) {
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
		else if ((action_inp == "k" || action_inp == "K") && swordsman.get_pos(0) < 150) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));

		}
		else if ((action_inp == "l" || action_inp == "L") && swordsman.get_pos(1) < 150) {
			
			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);

		}
		else if ((action_inp == "m" || action_inp == "M")) {
			system("cls");
			Common::cursor_vis(true);
			std::string menu_option = Common::input("===== Menu =====\n1) Party\n2) Backpack\n3) Map\n4) Skill book\n\nEnter an option (B for back) : ");
			while (menu_option != "1" && menu_option != "2" && menu_option != "3" && menu_option != "4" && menu_option != "B" && menu_option != "b") {
				system("cls");
				menu_option = Common::input("===== Menu =====\n1) Party\n2) Backpack\n3) Map\n4) Skill book\n\nInvalid Input\nEnter an option (B for back) : ");
			}
			
			if (menu_option == "1") {
				system("cls");
				std::cout << "====== Party ======\n\nSwordsman\n1) Attack   " << swordsman.get_stats("attack") << "\n2) Health   " << swordsman.get_stats("cur_health") << " / " << swordsman.get_stats("max_health") <<  "\n3) MP       "  << swordsman.get_stats("cur_mp") <<  " / " << swordsman.get_stats("max_mp") << "\n\n";
				for (int i = 0; i < 4; ++i) {
					if (swordsman.get_skill_list(i).active) {
						std::cout << " - ";
						swordsman.print_color_name(i);
						std::cout << "\n";
					}
				}

				if (/*mage.get_recruited()*/true) {
					std::cout << "\n\nMage\n1) Attack   " << mage.get_stats("attack") << "\n2) Health   " << mage.get_stats("cur_health") << " / " << mage.get_stats("max_health") <<  "\n3) MP       "  << mage.get_stats("cur_mp") <<  " / " << mage.get_stats("max_mp") << "\n";

					for (int i = 0; i < 4; ++i) {
						if (mage.get_skill_list(i).active) {
							std::cout << " - ";
							mage.print_color_name(i);
							std::cout << "\n";
						}
					}
				}

				if (/*elf.get_recruited()*/true) {
					std::cout << "\n\nElf\n1) Attack   " << elf.get_stats("attack") << "\n2) Health   " << elf.get_stats("cur_health") << " / " << elf.get_stats("max_health") << "\n3) MP       " << elf.get_stats("cur_mp") << " / " << elf.get_stats("max_mp") << "\n";

					for (int i = 0; i < 4; ++i) {
						if (elf.get_skill_list(i).active) {
							std::cout << " - ";
							elf.print_color_name(i);
							std::cout << "\n";
						}
					}
				}

				if (/*assassin.get_recruited()*/true) {
					std::cout << "\n\nElf\n1) Attack   " << assassin.get_stats("attack") << "\n2) Health   " << assassin.get_stats("cur_health") << " / " << assassin.get_stats("max_health") << "\n3) MP       " << assassin.get_stats("cur_mp") << " / " << assassin.get_stats("max_mp") << "\n";

					for (int i = 0; i < 4; ++i) {
						if (assassin.get_skill_list(i).active) {
							std::cout << " - ";
							assassin.print_color_name(i);
							std::cout << "\n";
						}
					}
				}

				Common::input("\n\nPress enter to return ");
				system("cls");
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
			else if (menu_option == "4") {
				system("cls");
				print_all_skill();
				system("cls");
			}
			/*else if (menu_option == "S") {
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
			}*/

			prev_is_map = false;
			Common::cursor_vis(false);
		}

		// Ambush by the elf troops
		if (trigger_counter == 1 && swordsman.get_pos(1) == 47 && swordsman.get_pos(0) >= 95 && swordsman.get_pos(0) <= 99) {
			Common::cursor_vis(true);
			story.meetElora();
			start_battle("ambush");
			trigger_counter++;

			prev_is_map = false;

			Common::cursor_vis(false);
		}

		if (tmp_target_cell_val == 3) {
			bool break_s = false;
			while (!break_s) {
				switch (shops[0].open_shop(swordsman.get_item_qty("coin"))) {
				case 'B':
				case 'b':
					break_s = true;
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
			}

			prev_is_map = false;
		}
		else if (tmp_target_cell_val == 5) {
			story.foundCart(trigger_counter == 0);
			if (trigger_counter == 0) {
				trigger_counter = 1;
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 20);

				for (int i = 95; i < 100; ++i) {
					board.set_board(i, 47, 0);
				}
			}

			prev_is_map = false;
		}

	}
}

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L" || inp == "m" || inp == "M");
}

void Game::print_all_skill()
{
	system("cls");

	const char* skill_name[]{ "Slash", "Fire Slash", "Taunt", "Spiral Spin", "Arcane Bullet", "Healing", "Enchant", "Fireball", "Shoot Arrow", "Raining Arrow", "Piercing Arrow", "Bullet Arrow", "Danger Poke", "Strength Dart", "Bomb", "Backstab", "Headbutt", "Shield Bash", "Arm Slap", "Demon Slash", "Demon Eye Beam", "Demon Strength", "Fire Breath", "Demon Punch", "Long live The King", "Demon Summon", "Hellfire" };
	const int power[]{ 5, 10, 5, 60, 3, 50, 10, 100, 5, 10, 30, 60, 5, 10, 45, 125, 10, 15, 30, 30, 90, 10, 100, 40, 50, 20, 100 };
	const int cost[]{ 0, 5, 10, 15, 0, 20, 30, 100, 0, 5, 10, 45, 0, 20, 15, 35, 10, 15, 15, 0, 20, 40, 100, 0, 20, 40, 100 };
	const char* types = "DDADDHADDDDDDADDDDDDDADDHAD";

	std::cout << "Skill Book\n--------------------------------------------\n";
	for (int i = 0; i < 27; ++i) {
		switch (types[i]) {
			case 'D':
				Common::color_print(0x0C, skill_name[i]);
				Common::set_cursor(25, i * 3 + 2);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(0, (i + 1) * 3);
				std::cout << " - Deals ";
				Common::color_print(0x0E, power[i]);
				std::cout << " damage";
				break;
			case 'A':
				Common::color_print(0x09, skill_name[i]);
				Common::set_cursor(25, i * 3 + 2);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(0, (i + 1) * 3);
				std::cout << " - Increase attack by ";
				Common::color_print(0x0E, power[i]);
				break;
			case 'H':
				Common::color_print(0x0A, skill_name[i]);
				Common::set_cursor(25, i * 3 + 2);
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(0, (i + 1) * 3);
				std::cout << " - Increase health by ";
				Common::color_print(0x0E, power[i]);
				break;
		}
		std::cout << "\n--------------------------------------------\n";
	}

	Common::input("Press enter to return ");
}
