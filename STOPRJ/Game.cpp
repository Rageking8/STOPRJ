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

	board.set_board(135, 2, 1);
	swordsman.set_pos(135, 2);

	//board.set_board(67, 3, 1);
	//swordsman.set_pos(67, 3);

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

	std::string tmp_player_name = start_menu();

	swordsman.set_name(tmp_player_name);
	story.set_player_name(tmp_player_name);

	Common::cursor_vis(false);

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
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \n";
				Common::color_print(0x0C, "Invalid action");
				std::cout << "\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
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
				std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \n";
				Common::color_print(0x0C, "Invalid action");
				std::cout << "\nPress or hold (WASD for movement and IJKL for interaction, M for menu)";
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
			while (true) {
				system("cls");
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				for (int i = 1; i < 30; ++i) {
					Common::set_cursor(0, i);
					Common::color_print(0xE0, "  ");
					Common::color_print(0x80, " ");

					if (i == 1 || i == 29) {
						Common::move_cursor('A');
						Common::color_print(0xC0, "  ");
						Common::set_cursor(121, i);
						Common::color_print(0xC0, "  ");
					}
					else {
						Common::set_cursor(122, i);
						Common::color_print(0x80, " ");
						Common::color_print(0xE0, "  ");
						continue;
					}
					Common::set_cursor(123, i);
					Common::color_print(0xE0, "  ");
				}

				Common::color_print(2, 2, 0xE0, "  ");
				Common::color_print(4, 1, 0xE0, "  ");

				Common::color_print(2, 28, 0xE0, "  ");
				Common::color_print(4, 29, 0xE0, "  ");

				Common::color_print(119, 1, 0xE0, "  ");
				Common::color_print(121, 2, 0xE0, "  ");

				Common::color_print(119, 29, 0xE0, "  ");
				Common::color_print(121, 28, 0xE0, "  ");

				for (int i = 11; i < 25; ++i) {
					Common::set_cursor(62, i);
					Common::color_print(0xE0, "  ");
				}

				Common::set_cursor(0, 11);
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				Common::set_cursor(0, 18);
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				Common::set_cursor(0, 25);
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				Common::set_cursor(0, 30);
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				for (int i = 0; i < 2; ++i) {
					for (int i2 = 0; i2 < 5; ++i2) {
						Common::set_cursor(73 + (4 * i), 3 + i2);
						Common::color_print(0x60, "  ");
					}

					for (int i2 = 0; i2 < 6; ++i2) {
						Common::set_cursor(47 + (6 * i), 3 + i2);
						Common::color_print(0x60, "  ");

						Common::set_cursor(65 + (4 * i), 3 + i2);
						Common::color_print(0x60, "  ");
					}

					Common::set_cursor(67, 4 + i);
					Common::color_print(0x60, " ");

					Common::set_cursor(68, 5 + i);
					Common::color_print(0x60, " ");

					Common::set_cursor(49 + (3 * i), 4);
					Common::color_print(0x60, " ");

					Common::set_cursor(59, 3 + (2 * i));
					Common::color_print(0x60, "    ");

					Common::set_cursor(59 + (15 * i), 8);
					Common::color_print(0x60, "    ");
				}

				for (int i = 0; i < 6; ++i) {
					Common::set_cursor(57, 3 + i);
					Common::color_print(0x60, "  ");
				}

				Common::set_cursor(50, 5);
				Common::color_print(0x60, "  ");

				Common::set_cursor(28, 14);
				Common::color_print(0x06, "[1] PARTY");
				Common::set_cursor(11, 15);
				std::cout << "Check your party's current stats and skills.";

				Common::set_cursor(87, 14);
				Common::color_print(0x06, "[2] BACKPACK");
				Common::set_cursor(75, 15);
				std::cout << "All of your items are stored in here.";

				Common::set_cursor(26, 21);
				Common::color_print(0x06, "[3] WORLD MAP");
				Common::set_cursor(8, 22);
				std::cout << "Have a look at the world you're about to explore.";

				Common::set_cursor(86, 21);
				Common::color_print(0x06, "[4] SKILL BOOK");
				Common::set_cursor(73, 22);
				std::cout << "An index of every skill you can encounter.";

				std::string menu_option;
				Common::color_print(21, 27, 0x07, "What would you like to look at? Enter the corresponding number (B for back)");

				bool tmp_flag = true;
				while (tmp_flag) {
					Common::set_cursor(94, 26);
					int c = _getch();
					if (c == 224) {
						c = _getch();
						Common::color_print(47, 28, 0x00, "                                ");
						Common::color_print(47, 28, 0x0C, "Invalid input! Please try again.");
						continue;
					}
					switch (c) {
						case 49:
							menu_option = "1";
							tmp_flag = false;
							break;
						case 50:
							menu_option = "2";
							tmp_flag = false;
							break;
						case 51:
							menu_option = "3";
							tmp_flag = false;
							break;
						case 52:
							menu_option = "4";
							tmp_flag = false;
							break;
						case 98:
							menu_option = "b";
							tmp_flag = false;
							break;
						case 66:
							menu_option = "B";
							tmp_flag = false;
							break;
					}
					if (menu_option == "") {
						Common::color_print(47, 28, 0x00, "                                ");
						Common::color_print(47, 28, 0x0C, "Invalid input! Please try again.");
					}
				}

				if (menu_option == "b" || menu_option == "B") {
					prev_is_map = false;
					system("cls");
					break;
				}
				else if (menu_option == "1") {
					system("cls");
					for (int i = 0; i < 5; ++i) {
						Common::color_print(0xE0, "                         ");
					}

					for (int i = 1; i < 30; ++i) {
						Common::set_cursor(0, i);
						Common::color_print(0xE0, "  ");
						Common::color_print(0x80, " ");

						if (i == 1 || i == 29) {
							Common::move_cursor('A');
							Common::color_print(0xC0, "  ");
							Common::set_cursor(121, i);
							Common::color_print(0xC0, "  ");
						}
						else {
							Common::set_cursor(122, i);
							Common::color_print(0x80, " ");
							Common::color_print(0xE0, "  ");
							continue;
						}
						Common::set_cursor(123, i);
						Common::color_print(0xE0, "  ");
					}

					Common::color_print(2, 2, 0xE0, "  ");
					Common::color_print(4, 1, 0xE0, "  ");

					Common::color_print(2, 28, 0xE0, "  ");
					Common::color_print(4, 29, 0xE0, "  ");

					Common::color_print(119, 1, 0xE0, "  ");
					Common::color_print(121, 2, 0xE0, "  ");

					Common::color_print(119, 29, 0xE0, "  ");
					Common::color_print(121, 28, 0xE0, "  ");

					for (int i = 11; i < 25; ++i) {
						for (int i2 = 0; i2 < 3; ++i2) {
							Common::set_cursor(31 * (i2 + 1), i);
							Common::color_print(0xE0, "  ");
						}
					}
					Common::set_cursor(0, 11);
					for (int i = 0; i < 5; ++i) {
						Common::color_print(0xE0, "                         ");
					}
					Common::set_cursor(0, 25);
					for (int i = 0; i < 5; ++i) {
						Common::color_print(0xE0, "                         ");
					}
					Common::set_cursor(0, 30);
					for (int i = 0; i < 5; ++i) {
						Common::color_print(0xE0, "                         ");
					}

					for (int i = 0; i < 2; ++i) {
						for (int i2 = 0; i2 < 3; ++i2) {
							Common::set_cursor(45 + (8 * i2), 3 + (2 * i));
							Common::color_print(0x60, "    ");

							Common::set_cursor(64 + (14 * i), 6 + i2);
							Common::color_print(0x60, "  ");
						}
						for (int i2 = 0; i2 < 5; ++i2) {
							Common::set_cursor(52 + (4 * i), 4 + i2);
							Common::color_print(0x60, "  ");
						}
						for (int i2 = 0; i2 < 6; ++i2) {
							Common::set_cursor(44 + (16 * i), 3 + i2);
							Common::color_print(0x60, "  ");
						}
						for (int i2 = 0; i2 < 2; ++i2) {
							Common::set_cursor(76 + (4 * i), 3 + i2);
							Common::color_print(0x60, "  ");
						}
						Common::set_cursor(48 + (16 * i), 4);
						Common::color_print(0x60, "  ");
					}
					for (int i = 0; i < 6; ++i) {
						Common::set_cursor(70, 3 + i);
						Common::color_print(0x60, "  ");
					}
					Common::set_cursor(68, 3);
					Common::color_print(0x60, "      ");

					Common::set_cursor(77, 5);
					Common::color_print(0x60, "    ");

					Common::set_cursor(5, 13);
					Common::color_print(0x0B, swordsman.get_name() + " [Swordsman]: ");
					Common::set_cursor(7, 14);
					std::cout << "ATTACK : " << swordsman.get_stats("attack");
					Common::set_cursor(7, 15);
					std::cout << "HEALTH : " << swordsman.get_stats("cur_health") << " / " << swordsman.get_stats("max_health");
					Common::set_cursor(7, 16);
					std::cout << "MP : " << swordsman.get_stats("cur_mp") << " / " << swordsman.get_stats("max_mp");

					Common::set_cursor(7, 18);
					std::cout << "SKILLS : ";
					for (int i = 0; i < 4; ++i) {
						if (swordsman.get_skill_list(i).active) {
							Common::set_cursor(6, 19 + i);
							std::cout << " - ";
							swordsman.print_color_name(i);
						}
					}

					if (/*mage.get_recruited() == */true) {
						Common::set_cursor(66, 13);
						Common::color_print(0x0D, "ORION [Mage]: ");
						Common::set_cursor(68, 14);
						std::cout << "ATTACK : " << mage.get_stats("attack");
						Common::set_cursor(68, 15);
						std::cout << "HEALTH : " << mage.get_stats("cur_health") << " / " << mage.get_stats("max_health");
						Common::set_cursor(68, 16);
						std::cout << "MP : " << mage.get_stats("cur_mp") << " / " << mage.get_stats("max_mp");

						Common::set_cursor(68, 18);
						std::cout << "SKILLS : ";
						for (int i = 0; i < 4; ++i) {
							if (mage.get_skill_list(i).active) {
								Common::set_cursor(68, 19 + i);
								std::cout << " - ";
								mage.print_color_name(i);
							}
						}
					}
					else {
						Common::set_cursor(77, 18);
						Common::color_print(0x0C, "---");
					}

					if (/*elf.get_recruited() == */true) {
						Common::set_cursor(35, 13);
						Common::color_print(0x0A, "ELORA [Archer]: ");
						Common::set_cursor(37, 14);
						std::cout << "ATTACK : " << elf.get_stats("attack");
						Common::set_cursor(37, 15);
						std::cout << "HEALTH : " << elf.get_stats("cur_health") << " / " << elf.get_stats("max_health");
						Common::set_cursor(37, 16);
						std::cout << "MP : " << elf.get_stats("cur_mp") << " / " << elf.get_stats("max_mp");

						Common::set_cursor(37, 18);
						std::cout << "SKILLS : ";
						for (int i = 0; i < 4; ++i) {
							if (elf.get_skill_list(i).active) {
								Common::set_cursor(37, 19 + i);
								std::cout << " - ";
								elf.print_color_name(i);
								std::cout << "\n";
							}
						}
					}
					else {
						Common::set_cursor(46, 18);
						Common::color_print(0x0C, "---");
					}

					if (/*assassin.get_recruited() == */true) {
						Common::set_cursor(97, 13);
						Common::color_print(0x0C, "BLAISE [Assassin]: ");
						Common::set_cursor(99, 14);
						std::cout << "ATTACK : " << assassin.get_stats("attack");
						Common::set_cursor(99, 15);
						std::cout << "HEALTH : " << assassin.get_stats("cur_health") << " / " << assassin.get_stats("max_health");
						Common::set_cursor(99, 16);
						std::cout << "MP : " << assassin.get_stats("cur_mp") << " / " << assassin.get_stats("max_mp");

						Common::set_cursor(99, 18);
						std::cout << "SKILLS : ";
						for (int i = 0; i < 4; ++i) {
							if (assassin.get_skill_list(i).active) {
								Common::set_cursor(99, 19 + i);
								std::cout << " - ";
								assassin.print_color_name(i);
								std::cout << "\n";
							}
						}
					}
					else {
						Common::color_print(108, 18, 0x0C, "---");
					}

					Common::color_print(52, 27, 0x07, "Press any key to return ");

					Common::any_key_press();

					system("cls");
				}
				else if (menu_option == "2") {
					std::string msg = "";
					short tmp_x = 0;
					bool is_red = false;

					while (true) {
						system("cls");
						for (int i = 0; i < 5; ++i) {
							Common::color_print(0xE0, "                         ");
						}

						for (int i = 1; i < 30; ++i) {
							Common::set_cursor(0, i);
							Common::color_print(0xE0, "  ");
							Common::color_print(0x80, " ");

							if (i == 1 || i == 29) {
								Common::move_cursor('A');
								Common::color_print(0xC0, "  ");
								Common::set_cursor(121, i);
								Common::color_print(0xC0, "  ");
							}
							else {
								Common::set_cursor(122, i);
								Common::color_print(0x80, " ");
								Common::color_print(0xE0, "  ");
								continue;
							}
							Common::set_cursor(123, i);
							Common::color_print(0xE0, "  ");
						}

						Common::color_print(2, 2, 0xE0, "  ");
						Common::color_print(4, 1, 0xE0, "  ");

						Common::color_print(2, 28, 0xE0, "  ");
						Common::color_print(4, 29, 0xE0, "  ");

						Common::color_print(119, 1, 0xE0, "  ");
						Common::color_print(121, 2, 0xE0, "  ");

						Common::color_print(119, 29, 0xE0, "  ");
						Common::color_print(121, 28, 0xE0, "  ");

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

						Common::set_cursor(34, 8);
						Common::color_print(0x60, "   ");

						for (int i = 0; i < 2; ++i) {
							Common::set_cursor(36 + (32 * i), 4);
							Common::color_print(0x60, "  ");

							Common::set_cursor(36, 6 + i);
							Common::color_print(0x60, "  ");

							for (int i2 = 0; i2 < 2; ++i2) {
								Common::set_cursor(34 + (32 * i), 3 + (2 * i2));
								Common::color_print(0x60, "   ");

								Common::set_cursor(41 + (32 * i), 3 + (2 * i2));
								Common::color_print(0x60, "    ");

								Common::set_cursor(49 + (32 * i), 3 + (5 * i2));
								Common::color_print(0x60, "    ");

								Common::set_cursor(52 + (32 * i), 4 + (3 * i2));
								Common::color_print(0x60, "  ");

								Common::set_cursor(58 + (32 * i), 5 + i2);
								Common::color_print(0x60, "  ");

								Common::set_cursor(59 + (32 * i), 4 + (3 * i2));
								Common::color_print(0x60, "  ");

								Common::set_cursor(60 + (32 * i), 3 + (5 * i2));
								Common::color_print(0x60, "  ");
							}
							for (int i2 = 0; i2 < 4; ++i2) {
								Common::set_cursor(48 + (32 * i), 4 + i2);
								Common::color_print(0x60, "  ");
							}
							for (int i2 = 0; i2 < 5; ++i2) {
								Common::set_cursor(40 + (32 * i), 4 + i2);
								Common::color_print(0x60, "  ");

								Common::set_cursor(44 + (32 * i), 4 + i2);
								Common::color_print(0x60, "  ");
							}
							for (int i2 = 0; i2 < 6; ++i2) {
								Common::set_cursor(32 + (32 * i), 3 + i2);
								Common::color_print(0x60, "  ");

								Common::set_cursor(56 + (32 * i), 3 + i2);
								Common::color_print(0x60, "  ");
							}
						}

						Common::set_cursor(56, 13);
						Common::color_print(0x06, "CURRENT STASH:");

						Common::set_cursor(53, 18);
						std::cout << "[1]   COINS : " << swordsman.get_item_qty("coin");

						Common::set_cursor(53, 19);
						std::cout << "[2]   SWORD : " << swordsman.get_item_qty("sword");

						Common::set_cursor(53, 20);
						std::cout << "[3]   ARMOUR : " << swordsman.get_item_qty("armour");

						Common::set_cursor(53, 21);
						std::cout << "[4]   HP POTION : " << swordsman.get_item_qty("hp_potion");

						Common::set_cursor(53, 22);
						std::cout << "[5]   MP POTION : " << swordsman.get_item_qty("mp_potion");

						Common::set_cursor(28, 25);

						std::string item_inp;
						std::cout << "Enter the corresponding number to consume/equip an item (B for back)";

						Common::color_print(34, 26, 0x00, Common::mul_txt(" ", 67));
						Common::color_print(tmp_x, 26, (is_red ? 0x0C : 0x0A), msg);

						while (true) {
							Common::set_cursor(94, 26);
							int c = _getch();
							if (c == 224) {
								c = _getch();
								Common::color_print(34, 26, 0x00, Common::mul_txt(" ", 67));
								Common::color_print(48, 26, 0x0C, "Invalid input! Please try again.");
								continue;
							}
							switch (c) {
							case 49:
								item_inp = "1";
								break;
							case 50:
								item_inp = "2";
								break;
							case 51:
								item_inp = "3";
								break;
							case 52:
								item_inp = "4";
								break;
							case 53:
								item_inp = "5";
								break;
							case 98:
								item_inp = "b";
								break;
							case 66:
								item_inp = "B";
								break;
							}
							if (item_inp == "") {
								Common::color_print(34, 26, 0x00, Common::mul_txt(" ", 67));
								Common::color_print(48, 26, 0x0C, "Invalid input! Please try again.");
							}
							else {
								break;
							}
						}

						if (item_inp == "1") {
							Common::set_cursor(37, 26);
							Common::color_print(0x0C, "You cannot use your COINS here. Please go to a SHOP.");
							msg = "You cannot use your COINS here. Please go to a SHOP.";
							tmp_x = 37;
							is_red = true;
						}
						else if (item_inp == "2") {
							if (swordsman.get_item_qty("sword") > 0) {
								swordsman.set_item_qty("sword", swordsman.get_item_qty("sword") - 1);
								swordsman.set_stats("attack", swordsman.get_stats("attack") + 5);

								Common::color_print(40, 26, 0x0A, "You have equipped a SWORD! Your attack is now ");
								Common::color_print(0x0A, swordsman.get_stats("attack"));
								Common::color_print(0x0A, "!");
								msg = "You have equipped a SWORD! Your attack is now " + std::to_string(swordsman.get_stats("attack")) + "!";
								tmp_x = 40;
								is_red = false;
							}
							else {
								Common::color_print(49, 26, 0x0C, "You have no SWORDS to equip!");
								msg = "You have no SWORDS to equip!";
								tmp_x = 49;
								is_red = true;
							}
						}
						else if (item_inp == "3") {
							if (swordsman.get_item_qty("armour") > 0) {
								swordsman.set_item_qty("armour", swordsman.get_item_qty("armour") - 1);
								swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") + 10);
								swordsman.set_stats("max_health", swordsman.get_stats("max_health") + 10);

								Common::color_print(37, 26, 0x0A, "You have equipped ARMOUR! Your max health is now ");
								Common::color_print(0x0A, swordsman.get_stats("max_health"));
								Common::color_print(0x0A, "!");
								msg = "You have equipped ARMOUR! Your max health is now " + std::to_string(swordsman.get_stats("max_health")) + "!";
								tmp_x = 37;
								is_red = false;
							}
							else {
								Common::color_print(49, 26, 0x0C, "You have no ARMOUR to equip!");
								msg = "You have no ARMOUR to equip!";
								tmp_x = 49;
								is_red = true;
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
								Common::color_print(34, 26, 0x0A, "You have consumed HP POTION! Your current health is now ");
								Common::color_print(0x0A, swordsman.get_stats("cur_health"));
								Common::color_print(0x0A, "!");
								msg = "You have consumed HP POTION! Your current health is now " + std::to_string(swordsman.get_stats("cur_health")) + "!";
								tmp_x = 34;
								is_red = false;
							}
							else {
								Common::color_print(46, 26, 0x0C, "You have no HP POTIONS to consume!");
								msg = "You have no HP POTIONS to consume!";
								tmp_x = 46;
								is_red = true;
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
								Common::color_print(37, 26, 0x0A, "You have consumed MP POTION! Your current MP is now ");
								Common::color_print(0x0A, swordsman.get_stats("cur_mp"));
								Common::color_print(0x0A, "!");
								msg = "You have consumed MP POTION! Your current MP is now " + std::to_string(swordsman.get_stats("cur_mp")) + "!";
								tmp_x = 37;
								is_red = false;
							}
							else {
								Common::color_print(46, 26, 0x0C, "You have no MP POTIONS to consume!");
								msg = "You have no MP POTIONS to consume!";
								tmp_x = 46;
								is_red = true;
							}
						}
						else if (item_inp == "b" || item_inp == "B") {
							break;
						}
					}
				}

				else if (menu_option == "3") {
					system("cls");
					board.print_map();
					std::cout << "\n# -> Colored blocks\nP -> Player\nS -> Shop\n? -> Special landmarks\n~ -> Water / Lava\n. -> All other landmarks (including empty space)\n\nPress any key to return ";
					Common::any_key_press();
					system("cls");
				}
				else if (menu_option == "4") {
					system("cls");
					print_all_skill();
					system("cls");
				}

				prev_is_map = false;
				Common::cursor_vis(false);
			}
		}

		// Ambush by the elf troops
		if (trigger_counter == 1 && swordsman.get_pos(1) == 47 && swordsman.get_pos(0) >= 95 && swordsman.get_pos(0) <= 99) {
			story.meetElora();
			start_battle("ambush");
			trigger_counter++;

			teleport_ply(65, 41);

			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (swordsman.get_pos(0) == 132 && swordsman.get_pos(1) >= 25 && swordsman.get_pos(1) <= 31) {
			teleport_ply(97, 8);
		}
		else if (swordsman.get_pos(1) == 5 && swordsman.get_pos(0) >= 95 && swordsman.get_pos(0) <= 99) {
			teleport_ply(133, 28);
		}
		else if (trigger_counter == 2 && swordsman.get_pos(0) == 65 && swordsman.get_pos(1) >= 1 && swordsman.get_pos(1) <= 5) {

			start_battle("bandit_1");
			trigger_counter++;

			for (int i = 1; i < 6; i++)
				board.set_board(64, i, 0);

			prev_is_map = false;
			system("cls");
		}

		if (tmp_target_cell_val == 3) {
			system("cls");
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
			Common::cursor_vis(false);
			system("cls");
		}
		else if (tmp_target_cell_val == 5) {
			Common::cursor_vis(false);
			story.foundCart(trigger_counter == 0);
			if (trigger_counter == 0) {
				trigger_counter = 1;
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 20);

				for (int i = 95; i < 100; ++i) {
					board.set_board(i, 47, 0);
				}
			}

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 21) {
			Common::cursor_vis(false);
			story.npc11();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 29) {
			Common::cursor_vis(false);
			story.eloraQuest_inProgress();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 45) {
			Common::cursor_vis(false);
			story.npc12();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 46) {
			Common::cursor_vis(false);
			story.npc13();
			prev_is_map = false;
			system("cls");
		}
	}
}

void Game::teleport_ply(int idx1, int idx2)
{
	board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
	swordsman.set_pos(idx1, idx2);
	board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

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
}

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L" || inp == "m" || inp == "M");
}

void Game::print_all_skill()
{
	system("cls");

	const char* skill_name[]{ "Slash", "Fire Slash", "Taunt", "Spiral Spin", "Arcane Bullet", "Healing", "Enchant", "Fireball", "Shoot Arrow", "Raining Arrow", "Piercing Arrow", "Bullet Arrow", "Danger Poke", "Strength Dart", "Bomb", "Backstab", "Headbutt", "Shield Bash", "Arm Slap", "Demon Slash", "Demon Eye Beam", "Demon Strength", "Fire Breath", "Demon Punch", "Long Live the King", "Demon Summon", "Hellfire" };
	const int power[]{ 5, 10, 5, 60, 3, 50, 10, 100, 5, 10, 30, 60, 5, 10, 45, 125, 10, 15, 30, 30, 90, 10, 100, 40, 50, 20, 100 };
	const int cost[]{ 0, 5, 10, 15, 0, 20, 30, 100, 0, 5, 10, 45, 0, 20, 15, 35, 10, 15, 15, 0, 20, 40, 100, 0, 20, 40, 100 };
	const char* types = "DDADDHADDDDDDADDDDDDDADDHAD";

	int page_num = 0;

	std::string error_msg = "";

	while (true) {
		system("cls");

		Common::cursor_vis(false);

		for (int i = 0; i < 5; ++i) {
			Common::color_print(0xE0, "                         ");
		}

		for (int i = 1; i < 30; ++i) {
			Common::set_cursor(0, i);
			Common::color_print(0xE0, "  ");
			Common::color_print(0x80, " ");

			if (i == 1 || i == 29) {
				Common::move_cursor('A');
				Common::color_print(0xC0, "  ");
				Common::set_cursor(121, i);
				Common::color_print(0xC0, "  ");
			}
			else {
				Common::set_cursor(122, i);
				Common::color_print(0x80, " ");
				Common::color_print(0xE0, "  ");
				continue;
			}
			Common::set_cursor(123, i);
			Common::color_print(0xE0, "  ");
		}

		Common::color_print(2, 2, 0xE0, "  ");
		Common::color_print(4, 1, 0xE0, "  ");

		Common::color_print(2, 28, 0xE0, "  ");
		Common::color_print(4, 29, 0xE0, "  ");

		Common::color_print(119, 1, 0xE0, "  ");
		Common::color_print(121, 2, 0xE0, "  ");

		Common::color_print(119, 29, 0xE0, "  ");
		Common::color_print(121, 28, 0xE0, "  ");

		for (int i = 11; i < 30; ++i) {
			Common::set_cursor(62, i);
			Common::color_print(0xE0, "  ");
		}

		Common::set_cursor(0, 11);

		for (int i = 0; i < 5; ++i) {
			Common::color_print(0xE0, "                         ");
		}

		Common::set_cursor(0, 30);

		for (int i = 0; i < 5; ++i) {
			Common::color_print(0xE0, "                         ");
		}

		Common::set_cursor(69, 5);
		Common::color_print(0x60, "   ");

		Common::set_cursor(71, 4);
		Common::color_print(0x60, "  ");

		for (int i = 0; i < 2; ++i) {
			Common::set_cursor(28, 3 + (5 * i));
			Common::color_print(0x60, "    ");

			Common::set_cursor(28 + (2 * i), 5 + i);
			Common::color_print(0x60, "  ");

			Common::set_cursor(47 + (8 * i), 8);
			Common::color_print(0x60, "      ");

			Common::set_cursor(69, 3 + (5 * i));
			Common::color_print(0x60, "   ");

			Common::set_cursor(71, 6 + i);
			Common::color_print(0x60, "  ");

			for (int i2 = 0; i2 < 2; ++i2) {
				Common::set_cursor(27 + (4 * i), 4 + (3 * i2));
				Common::color_print(0x60, "  ");

				Common::set_cursor(37 + (56 * i), 5 + i2);
				Common::color_print(0x60, "  ");

				Common::set_cursor(38 + (56 * i), 4 + (3 * i2));
				Common::color_print(0x60, "  ");

				Common::set_cursor(39 + (56 * i), 3 + (5 * i2));
				Common::color_print(0x60, "  ");

				Common::set_cursor(76 + (8 * i), 3 + (5 * i2));
				Common::color_print(0x60, "    ");
			}

			for (int i2 = 0; i2 < 6; ++i2) {
				Common::set_cursor(35 + (56 * i), 3 + i2);
				Common::color_print(0x60, "  ");

				Common::set_cursor(43 + (24 * i), 3 + i2);
				Common::color_print(0x60, "  ");

				Common::set_cursor(47 + (8 * i), 3 + i2);
				Common::color_print(0x60, "  ");
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int i2 = 0; i2 < 4; ++i2) {
				Common::set_cursor(75 + (4 * i), 4 + i2);
				Common::color_print(0x60, "  ");
			}
		}

		for (int i = 0 + (10 * page_num); i < 5 + (10 * page_num); ++i) {
			switch (types[i]) {
			case 'D':
				Common::set_cursor(11, 10 + ((i + 1 - (10 * page_num)) * 3));
				Common::color_print(0x0C, skill_name[i]);
				Common::set_cursor(36, 10 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(11, 11 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " - Deals ";
				Common::color_print(0x0E, power[i]);
				std::cout << " damage";
				break;
			case 'A':
				Common::set_cursor(11, 10 + ((i + 1 - (10 * page_num)) * 3));
				Common::color_print(0x09, skill_name[i]);
				Common::set_cursor(36, 10 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(11, 11 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " - Increase attack by ";
				Common::color_print(0x0E, power[i]);
				break;
			case 'H':
				Common::set_cursor(11, 10 + ((i + 1 - (10 * page_num)) * 3));
				Common::color_print(0x0A, skill_name[i]);
				Common::set_cursor(36, 10 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(11, 11 + ((i + 1 - (10 * page_num)) * 3));
				std::cout << " - Increase health by ";
				Common::color_print(0x0E, power[i]);
				break;
			}
			Common::set_cursor(8, 12 + ((i + (1 - 10 * page_num)) * 3));
			Common::color_print(0x0F, "-----------------------------------------------");
		}

		for (int i = 5 + (10 * page_num); i < 10 + (10 * page_num); ++i) {
			switch (types[i]) {
			case 'D':
				Common::set_cursor(73, 10 + ((i - 4 - (10 * page_num)) * 3));
				Common::color_print(0x0C, skill_name[i]);
				Common::set_cursor(98, 10 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(73, 11 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " - Deals ";
				Common::color_print(0x0E, power[i]);
				std::cout << " damage";
				break;
			case 'A':
				Common::set_cursor(73, 10 + ((i - 4 - (10 * page_num)) * 3));
				Common::color_print(0x09, skill_name[i]);
				Common::set_cursor(98, 10 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(73, 11 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " - Increase attack by ";
				Common::color_print(0x0E, power[i]);
				break;
			case 'H':
				Common::set_cursor(73, 10 + ((i - 4 - (10 * page_num)) * 3));
				Common::color_print(0x0A, skill_name[i]);
				Common::set_cursor(98, 10 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " ( Cost : ";
				Common::color_print(0x0E, cost[i]);
				std::cout << " MP )";
				Common::set_cursor(73, 11 + ((i - 4 - (10 * page_num)) * 3));
				std::cout << " - Increase health by ";
				Common::color_print(0x0E, power[i]);
				break;
			}
			Common::set_cursor(70, 12 + ((i - 5) + (1 - 10 * page_num)) * 3);
			Common::color_print(0x0F, "-----------------------------------------------");
		}

		Common::set_cursor(8, 28);
		std::cout << "A = Prev Page || D = Next Page || B = Close Book";

		Common::color_print(70, 29, 0x0C, error_msg);

		std::string skillBook_inp;

		Common::set_cursor(70, 28);
		std::cout << "Enter your choice                  (Page " << (page_num + 1) << " / 3)";

		while (true) {
			int c = _getch();
			if (c == 224) {
				c = _getch();
				Common::color_print(70, 29, 0x00, "                              ");
				Common::color_print(70, 29, 0x0C, "Invalid input!");
				continue;
			}
			switch (c) {
				case 97:
					skillBook_inp = "a";
					break;
				case 100:
					skillBook_inp = "d";
					break;
				case 65:
					skillBook_inp = "A";
					break;
				case 68:
					skillBook_inp = "D";
					break;
				case 98:
					skillBook_inp = "b";
					break;
				case 66:
					skillBook_inp = "B";
					break;
			}
			if (skillBook_inp == "") {
				Common::color_print(70, 29, 0x00, "                              ");
				Common::color_print(70, 29, 0x0C, "Invalid input!");
			}
			else {
				break;
			}
		}

		if (skillBook_inp == "A" || skillBook_inp == "a") {
			if (page_num == 0) {
				Common::color_print(70, 29, 0x0C, "You can't flip past that page!");
				error_msg = "You can't flip past that page!";
			}
			else {
				Common::color_print(70, 29, 0x00, "                              ");
				error_msg = "";
				page_num--;
			}
		}

		else if (skillBook_inp == "D" || skillBook_inp == "d") {
			if (page_num == 2) {
				Common::color_print(70, 29, 0x0C, "You can't flip past that page!");
				error_msg = "You can't flip past that page!";
			}
			else {
				Common::color_print(70, 29, 0x00, "                              ");
				error_msg = "";
				page_num++;
			}
		}
		else if (skillBook_inp == "B" || skillBook_inp == "b") {
			break;
		}
	}
}

bool Game::all_space(std::string inp)
{
	bool ret = true;
	for (const auto i : inp) {
		if (i != ' ') {
			ret = false;
			break;
		}
	}
	return ret;
}