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
	// Make the console window size be the screen size
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	// Disable sync with stdio to improve performance
	std::ios_base::sync_with_stdio(false);

	// Default spawn location of player (swordsman)
	teleport_ply(135, 2, false);

	// Generate all the landmarks of the entire world
	board_gen();
}

Game::~Game()
{
}

void Game::start()
{
	Common::Timer speedrun;
	system("cls");

	Common::cursor_vis(false);

	// Get player's name and initialize player's name across the whole game
	std::string tmp_player_name = start_menu();
	swordsman.set_name(tmp_player_name);
	story.set_player_name(tmp_player_name);

	// Initial quick guide on how to start
	story.beforeTalkingToMessenger();

	bool prev_is_map = false;

	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	short prev_block[8]{ -1, -1, 0, 0, -1, -1, 0, 0 };

	const int swi_id[2]{ 19, 20 };
	const bool bandit_puz_i[4]{ false, true, true, false };
	bool bandit_puz_a[4]{};

	int tmp_idx = Common::rand_int(0, 3);
	bandit_puz_a[tmp_idx] = !bandit_puz_i[tmp_idx];
	for (int i = 0; i < 4; ++i) {
		if (i == tmp_idx) continue;
		bandit_puz_a[i] = (Common::rand_int(1, 20) <= 10);
	}

	// Keeps track of the state of certain parts in the game to prevent replaying parts that should only happen once
	bool npc4_r = false;

	int jadesq_s = 0;
	bool jadesq_j1 = false;
	bool jadesq_j2 = false;
	bool jadesq_j3 = false;
	int jadesq_c = 0;

	bool bandit1_b = false;
	bool bandit_camp_t = false;
	bool bandit_trea_r = false;
	bool dun_f1 = false;
	bool dun_f2_d = false;
	bool dun_f2_k = false;
	bool dun_f2_b = false;
	bool dun_f3_b = false;
	bool dkc_3_d = false;

	while (true) {

		// Dont use system("cls") as it causes flicker when the screen is updating
		Common::set_cursor(0, 0);
		board.print_board(prev_is_map);

		Common::set_cursor(0, 31);
		std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-150 (both inclusive)    \n";

		Common::set_cursor(72, 33);
		std::cout << " ";

		Common::set_cursor(0, 32);
		std::cout << "              \nPress or hold (WASD for movement and IJKL for interaction, M for menu)";

		short tmp_target_cell_val = -1;
		short tmp_target_cell[2]{ -1 , -1 };

		prev_is_map = true;

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
		if ((action_inp == "w" || action_inp == "W") && swordsman.get_pos(0) > 0 && board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1)) <= 0) {

			if (prev_block[0] != -1)
				prev_block[3] = 1;
			if (prev_block[4] != -1)
				prev_block[7] += 1;

			if (board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1)) < 0) {
				if (prev_block[0] == -1) {
					prev_block[0] = swordsman.get_pos(0) - 1;
					prev_block[1] = swordsman.get_pos(1);
					prev_block[2] = board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1));
				}
				else {
					prev_block[4] = swordsman.get_pos(0) - 1;
					prev_block[5] = swordsman.get_pos(1);
					prev_block[6] = board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1));
				}
			}

			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('W');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) < 143)
				board.move_cam('W');

			if (prev_block[0] != -1 && prev_block[3] == 1) {
				board.set_board(prev_block[0], prev_block[1], prev_block[2]);
				prev_block[0] = -1;
				prev_block[1] = -1;
				prev_block[2] = 0;
				prev_block[3] = 0;
			}
			else if (prev_block[4] != -1 && prev_block[7] == 1) {
				board.set_board(prev_block[4], prev_block[5], prev_block[6]);
				prev_block[4] = -1;
				prev_block[5] = -1;
				prev_block[6] = 0;
				prev_block[7] = 0;
			}
		}
		else if ((action_inp == "a" || action_inp == "A") && swordsman.get_pos(1) > 0 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1) <= 0) {

			if (prev_block[0] != -1)
				prev_block[3] = 1;
			if (prev_block[4] != -1)
				prev_block[7] += 1;

			if (board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1) < 0) {
				if (prev_block[0] == -1) {
					prev_block[0] = swordsman.get_pos(0);
					prev_block[1] = swordsman.get_pos(1) - 1;
					prev_block[2] = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1);
				}
				else {
					prev_block[4] = swordsman.get_pos(0);
					prev_block[5] = swordsman.get_pos(1) - 1;
					prev_block[6] = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1);
				}
			}

			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('A');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) < 135)
				board.move_cam('A');

			if (prev_block[0] != -1 && prev_block[3] == 1) {
				board.set_board(prev_block[0], prev_block[1], prev_block[2]);
				prev_block[0] = -1;
				prev_block[1] = -1;
				prev_block[2] = 0;
				prev_block[3] = 0;
			}
			else if (prev_block[4] != -1 && prev_block[7] == 1) {
				board.set_board(prev_block[4], prev_block[5], prev_block[6]);
				prev_block[4] = -1;
				prev_block[5] = -1;
				prev_block[6] = 0;
				prev_block[7] = 0;
			}
		}
		else if ((action_inp == "s" || action_inp == "S") && swordsman.get_pos(0) < 150 && board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1)) <= 0) {

			if (prev_block[0] != -1)
				prev_block[3] = 1;
			if (prev_block[4] != -1)
				prev_block[7] += 1;

			if (board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1)) < 0) {
				if (prev_block[0] == -1) {
					prev_block[0] = swordsman.get_pos(0) + 1;
					prev_block[1] = swordsman.get_pos(1);
					prev_block[2] = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));
				}
				else {
					prev_block[4] = swordsman.get_pos(0) + 1;
					prev_block[5] = swordsman.get_pos(1);
					prev_block[6] = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));
				}
			}

			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('S');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) > 7)
				board.move_cam('S');

			if (prev_block[0] != -1 && prev_block[3] == 1) {
				board.set_board(prev_block[0], prev_block[1], prev_block[2]);
				prev_block[0] = -1;
				prev_block[1] = -1;
				prev_block[2] = 0;
				prev_block[3] = 0;
			}
			else if (prev_block[4] != -1 && prev_block[7] == 1) {
				board.set_board(prev_block[4], prev_block[5], prev_block[6]);
				prev_block[4] = -1;
				prev_block[5] = -1;
				prev_block[6] = 0;
				prev_block[7] = 0;
			}
		}
		else if ((action_inp == "d" || action_inp == "D") && swordsman.get_pos(1) < 150 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1) <= 0) {

			if (prev_block[0] != -1)
				prev_block[3] = 1;
			if (prev_block[4] != -1)
				prev_block[7] += 1;

			if (board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1) < 0) {
				if (prev_block[0] == -1) {
					prev_block[0] = swordsman.get_pos(0);
					prev_block[1] = swordsman.get_pos(1) + 1;
					prev_block[2] = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);
				}
				else {
					prev_block[4] = swordsman.get_pos(0);
					prev_block[5] = swordsman.get_pos(1) + 1;
					prev_block[6] = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);
				}
			}

			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('D');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) > 15)
				board.move_cam('D');

			if (prev_block[0] != -1 && prev_block[3] == 1) {
				board.set_board(prev_block[0], prev_block[1], prev_block[2]);
				prev_block[0] = -1;
				prev_block[1] = -1;
				prev_block[2] = 0;
				prev_block[3] = 0;
			} else if (prev_block[4] != -1 && prev_block[7] == 1) {
				board.set_board(prev_block[4], prev_block[5], prev_block[6]);
				prev_block[4] = -1;
				prev_block[5] = -1;
				prev_block[6] = 0;
				prev_block[7] = 0;
			}
		}

		// For player interaction with landmarks (IJKL)
		else if ((action_inp == "i" || action_inp == "I") && swordsman.get_pos(0) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1));
			tmp_target_cell[0] = swordsman.get_pos(0) - 1;
			tmp_target_cell[1] = swordsman.get_pos(1);
		}
		else if ((action_inp == "j" || action_inp == "J") && swordsman.get_pos(1) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1);
			tmp_target_cell[0] = swordsman.get_pos(0);
			tmp_target_cell[1] = swordsman.get_pos(1) - 1;
		}
		else if ((action_inp == "k" || action_inp == "K") && swordsman.get_pos(0) < 150) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));
			tmp_target_cell[0] = swordsman.get_pos(0) + 1;
			tmp_target_cell[1] = swordsman.get_pos(1);
		}
		else if ((action_inp == "l" || action_inp == "L") && swordsman.get_pos(1) < 150) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);
			tmp_target_cell[0] = swordsman.get_pos(0);
			tmp_target_cell[1] = swordsman.get_pos(1) + 1;
		}
		else if ((action_inp == "m" || action_inp == "M")) {
			while (true) {
				system("cls");
				for (int i = 0; i < 5; ++i) {
					Common::color_print(0xE0, "                         ");
				}

				for (int i = 1; i < 30; ++i) {
					Common::color_print(0, i, 0xE0, "  ");
					Common::color_print(0x80, " ");

					if (i == 1 || i == 29) {
						Common::move_cursor('A');
						Common::color_print(0xC0, "  ");
						Common::color_print(121, i, 0xC0, "  ");
					}
					else {
						Common::set_cursor(122, i);
						Common::color_print(0x80, " ");
						Common::color_print(0xE0, "  ");
						continue;
					}
					Common::color_print(123, i, 0xE0, "  ");
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
					Common::color_print(62, i, 0xE0, "  ");
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

					Common::color_print(67, 4 + i, 0x60, " ");

					Common::color_print(68, 5 + i, 0x60, " ");

					Common::color_print(49 + (3 * i), 4, 0x60, " ");

					Common::color_print(59, 3 + (2 * i), 0x60, "    ");

					Common::color_print(59 + (15 * i), 8, 0x60, "    ");
				}

				for (int i = 0; i < 6; ++i) {
					Common::color_print(57, 3 + i, 0x60, "  ");
				}

				Common::color_print(50, 5, 0x60, "  ");

				Common::color_print(28, 14, 0x06, "[1] PARTY");
				Common::set_cursor(11, 15);
				std::cout << "Check your party's current stats and skills.";

				Common::color_print(87, 14, 0x06, "[2] BACKPACK");
				Common::set_cursor(75, 15);
				std::cout << "All of your items are stored in here.";

				Common::color_print(26, 21, 0x06, "[3] WORLD MAP");
				Common::set_cursor(8, 22);
				std::cout << "Have a look at the world you're about to explore.";

				Common::color_print(86, 21, 0x06, "[4] SKILL BOOK");
				Common::set_cursor(73, 22);
				std::cout << "An index of every skill you can encounter.";

				std::string menu_option;
				Common::color_print(23, 27, 0x07, "What would you like to look at? Enter the corresponding number (B for back)");

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
						Common::color_print(0, i, 0xE0, "  ");
						Common::color_print(0x80, " ");

						if (i == 1 || i == 29) {
							Common::move_cursor('A');
							Common::color_print(0xC0, "  ");
							Common::color_print(121, i, 0xC0, "  ");
						}
						else {
							Common::color_print(122, i, 0x80, " ");
							Common::color_print(0xE0, "  ");
							continue;
						}
						Common::color_print(123, i, 0xE0, "  ");
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
							Common::color_print(31 * (i2 + 1), i, 0xE0, "  ");
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
						Common::color_print(70, 3 + i, 0x60, "  ");
					}
					Common::color_print(68, 3, 0x60, "      ");

					Common::color_print(77, 5, 0x60, "    ");

					Common::color_print(5, 13, 0x0B, swordsman.get_name() + " [Swordsman]: ");
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

					if (elf.get_recruited() && elf.get_stats("cur_health") > 0) {
						Common::color_print(35, 13, 0x0A, "ELORA [Elf]: ");
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
					else if (elf.get_recruited()) {
						Common::color_print(35, 13, 0x0A, "ELORA [Elf]: ");
						Common::color_print(0x0F, "DEAD");
					}
					else {
						Common::color_print(46, 18, 0x07, "---");
					}

					if (mage.get_recruited() && mage.get_stats("cur_health") > 0) {
						Common::color_print(66, 13, 0x0D, "ORION [Mage]: ");
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
					else if (mage.get_recruited()) {
						Common::color_print(66, 13, 0x0D, "ORION [Mage]: ");
						Common::color_print(0x0F, "DEAD");
					}
					else {
						Common::color_print(77, 18, 0x07, "---");
					}

					if (assassin.get_recruited() && assassin.get_stats("cur_health") > 0) {
						Common::color_print(97, 13, 0x0C, "BLAISE [Assassin]: ");
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
					else if (assassin.get_recruited()) {
						Common::color_print(97, 13, 0x0C, "BLAISE [Assassin]: ");
						Common::color_print(0x0F, "DEAD");
					}
					else {
						Common::color_print(108, 18, 0x07, "---");
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
						std::cout << "[2]   ATTACK POTION : " << swordsman.get_item_qty("atk_potion");

						Common::set_cursor(53, 20);
						std::cout << "[3]   VITALITY POTION : " << swordsman.get_item_qty("vit_potion");

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
							if (swordsman.get_item_qty("atk_potion") > 0) {
								swordsman.set_item_qty("atk_potion", swordsman.get_item_qty("atk_potion") - 1);
								swordsman.set_stats("attack", swordsman.get_stats("attack") + 5);

								Common::color_print(37, 26, 0x0A, "You have consumed ATTACK POTION! Your attack is now ");
								Common::color_print(0x0A, swordsman.get_stats("attack"));
								Common::color_print(0x0A, "!");
								msg = "You have consumed ATTACK POTION! Your attack is now " + std::to_string(swordsman.get_stats("attack")) + "!";
								tmp_x = 37;
								is_red = false;
							}
							else {
								Common::color_print(44, 26, 0x0C, "You have no ATTACK POTIONS to consume!");
								msg = "You have no ATTACK POTIONS to consume!";
								tmp_x = 44;
								is_red = true;
							}
						}
						else if (item_inp == "3") {
							if (swordsman.get_item_qty("vit_potion") > 0) {
								swordsman.set_item_qty("vit_potion", swordsman.get_item_qty("vit_potion") - 1);
								swordsman.set_stats("max_health", swordsman.get_stats("max_health") + 20);

								Common::color_print(33, 26, 0x0A, "You have consumed VITALITY POTION! Your max health is now ");
								Common::color_print(0x0A, swordsman.get_stats("max_health"));
								Common::color_print(0x0A, "!");
								msg = "You have consumed VITALITY POTION! Your max health is now " + std::to_string(swordsman.get_stats("max_health")) + "!";
								tmp_x = 33;
								is_red = false;
							}
							else {
								Common::color_print(43, 26, 0x0C, "You have no VITALITY POTIONS to consume!");
								msg = "You have no VITALITY POTIONS to consume!";
								tmp_x = 43;
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
					Common::color_print(0x0B, "\n** Use scroll wheel to see whole map\n");
					std::cout << "\n# -> Colored blocks\nP -> Player\nS -> Shop\n? -> Special landmarks\n~ -> Water / Lava\n= -> Non-solid block (allow player to walk through)\n. -> All other landmarks (including empty space)\n\nPress any key to return ";
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

			system("cls");

			Common::write_ani("Welcome to your first BATTLE! For this BATTLE, some guidance will be provided.\n\n"
							  "The box highlighted in LIGHT YELLOW signifies whose turn it is. Currently, it is YOUR turn.\n\n"
							  "The numbers on the left correspond to your SKILLS. SKILLS may cost MP, and are recorded in the SKILL BOOK.\n\n"
							  "Just enter the number of the skill you wish to cast to end your turn!\n\n");

			Common::any_key_press("Press any key to continue");

			start_battle("ambush");

			swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 30);

			trigger_counter++;

			teleport_ply(65, 41);

			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (swordsman.get_pos(0) == 131 && swordsman.get_pos(1) >= 27 && swordsman.get_pos(1) <= 29) {
			story.boardBoat();
			teleport_ply(97, 8);

			prev_is_map = false;
			system("cls");
		}
		else if (swordsman.get_pos(0) == 100 && swordsman.get_pos(1) >= 7 && swordsman.get_pos(1) <= 9) {
			story.boardBoat();
			teleport_ply(133, 28);

			prev_is_map = false;
			system("cls");
		}
		else if (trigger_counter == 2 && swordsman.get_pos(0) == 65 && swordsman.get_pos(1) >= 1 && swordsman.get_pos(1) <= 5) {

			bandit1_b = start_battle("bandit_1");
			trigger_counter++;

			for (int i = 1; i < 6; i++)
				board.set_board(64, i, 0);

			if (!bandit1_b) {
				board.set_board(46, 59, 0);
				board.set_board(8, 31, 78);
				teleport_ply(71, 54);
				swordsman.set_stats("cur_health", 50);
			}
			else {
				for (int i = 54; i < 61; ++i)
					board.set_board(19, i, 6);
			}

			board.set_board(64, 41, 0);

			swordsman.set_active(2, true);
			elf.set_active(2, true);
			mage.set_active(2, true);

			elf.set_recruited(true);

			prev_is_map = false;
			system("cls");
		}
		else if (!bandit_camp_t && swordsman.get_pos(0) == 15 && swordsman.get_pos(1) >= 20 && swordsman.get_pos(1) <= 29) {
			if (!bandit1_b) {
				story.enterCamp_loseBandits();
			}
			else {
				story.enterCamp_winBandits();
			}

			bandit_camp_t = true;
			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (!dun_f1 && swordsman.get_pos(0) == 23 && swordsman.get_pos(1) >= 88 && swordsman.get_pos(1) <= 94) {
			// Dungeon floor 1
			story.excalibur_floor1Start();

			dun_f1 = true;
			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (!dun_f2_d && swordsman.get_pos(0) == 43 && swordsman.get_pos(1) >= 88 && swordsman.get_pos(1) <= 94) {
			story.excalibur_lockedInFloor2();

			for (int i = 0; i < 7; i++)
				board.set_board(42, (88 + i), 6);

			dun_f2_d = true;
			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (!dun_f2_k && swordsman.get_pos(0) == 62 && swordsman.get_pos(1) >= 88 && swordsman.get_pos(1) <= 94) {
			story.excalibur_floor2();

			teleport_ply(swordsman.get_pos(0) - 1, swordsman.get_pos(1));

			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (!dun_f2_b && dun_f2_k && swordsman.get_pos(0) == 62 && swordsman.get_pos(1) >= 88 && swordsman.get_pos(1) <= 94) {
			story.excalibur_doorUnlocked();
			for (int i = 0; i < 7; i++)
				board.set_board(63, (88 + i), 0);

			for (int i = 0; i < 7; i++)
				board.set_board(42, (88 + i), 0);

			dun_f2_b = true;

			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (!dun_f3_b && swordsman.get_pos(0) == 64 && swordsman.get_pos(1) >= 88 && swordsman.get_pos(1) <= 94) {
			story.excalibur_floor3();
			for (int i = 0; i < 7; i++)
				board.set_board(63, (88 + i), 6);

			dun_f3_b = true;
			prev_is_map = false;
			system("cls");
			
		}
		else if (!dkc_3_d && swordsman.get_pos(0) == 41 && swordsman.get_pos(1) >= 126 && swordsman.get_pos(1) <= 135) {
			story.beforeFightDK_main();

			start_battle("dkc_3");

			board.set_board(17, 131, 0);
			board.set_board(17, 129, 0);
			board.set_board(16, 130, 0);

			teleport_ply(139, 121);

			break;

			dkc_3_d = true;
			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (jadesq_s == 1 && !jadesq_j1 && swordsman.get_pos(0) == 93 && swordsman.get_pos(1) == 22) {
			jadesq_c++;
			if (jadesq_c == 3)
				jadesq_s = 2;
			jadesq_j1 = true;
			story.KoE_jadeFound(jadesq_c);
			prev_is_map = false;
			system("cls");
		}
		else if (jadesq_s == 1 && !jadesq_j2 && swordsman.get_pos(0) == 93 && swordsman.get_pos(1) == 1) {
			jadesq_c++;
			if (jadesq_c == 3)
				jadesq_s = 2;
			jadesq_j2 = true;
			story.KoE_jadeFound(jadesq_c);
			prev_is_map = false;
			system("cls");
		}
		else if (jadesq_s == 1 && !jadesq_j3 && swordsman.get_pos(0) == 67 && swordsman.get_pos(1) == 8) {
			jadesq_c++;
			if (jadesq_c == 3)
				jadesq_s = 2;
			jadesq_j3 = true;
			story.KoE_jadeFound(jadesq_c);
			prev_is_map = false;
			system("cls");
		}

		if (tmp_target_cell_val == 3) {
			system("cls");
			bool break_s = false;
			while (!break_s) {
				switch (shop.open_shop(swordsman.get_item_qty("coin"))) {
				case 'B':
				case 'b':
					break_s = true;
					break;
				case '1':
					swordsman.set_item_qty("atk_potion", swordsman.get_item_qty("atk_potion") + 1);
					swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 10);
					break;
				case '2':
					swordsman.set_item_qty("vit_potion", swordsman.get_item_qty("vit_potion") + 1);
					swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 20);
					break;
				case '3':
					swordsman.set_item_qty("hp_potion", swordsman.get_item_qty("hp_potion") + 1);
					swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 5);
					break;
				case '4':
					swordsman.set_item_qty("mp_potion", swordsman.get_item_qty("mp_potion") + 1);
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

				for (int i = 95; i < 100; ++i)
					board.set_board(i, 47, 0);
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
			if (jadesq_s == 0) {
				story.KoE_start();

				Common::cursor_vis(true);
				std::string tmp_inp = Common::input("Do you want to accept this quest ? (Y/N) : ");
				while (tmp_inp != "Y" && tmp_inp != "y" && tmp_inp != "N" && tmp_inp != "n") {
					Common::color_print(43, 7, 0x07, Common::mul_txt(" ", tmp_inp.length()));
					Common::color_print(0, 8, 0x0C, "Invalid Input");
					Common::set_cursor(0, 7);
					tmp_inp = Common::input("Do you want to accept this quest ? (Y/N) : ");
				}

				Common::cursor_vis(false);

				if (tmp_inp == "Y" || tmp_inp == "y") {
					story.KoE_accept();
					jadesq_s = 1;
				}
				else {
					story.KoE_decline();
				}
			}
			else if (jadesq_s == 1) {
				story.KoE_inProgress();
			}
			else if (jadesq_s == 2) {
				story.KoE_complete();
				jadesq_s = 3;
				swordsman.set_item_qty("atk_potion", swordsman.get_item_qty("atk_potion") + 2);
			}
			else {
				story.npc12();
			}

			prev_is_map = false;
			system("cls");
			Common::cursor_vis(false);
		}
		else if (tmp_target_cell_val == 46) {
			Common::cursor_vis(false);
			story.npc13(trigger_counter >= 3);
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 50) {
			Common::cursor_vis(false);
			story.npc4(npc4_r == false);
			if (!npc4_r)
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 10);
			npc4_r = true;
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 22) {
			Common::cursor_vis(false);
			story.npc8_9_10();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 52) {
			Common::cursor_vis(false);
			story.npc6();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 47) {
			Common::cursor_vis(false);
			story.npc1();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 48) {
			Common::cursor_vis(false);
			story.npc2();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 49) {
			Common::cursor_vis(false);
			story.npc3();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 51) {
			Common::cursor_vis(false);
			story.npc5();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 24) {
			Common::cursor_vis(false);
			story.magicSchool_start();
			Common::input("Do you want to accept this quest ? (Y/N) : ");



			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 26 || tmp_target_cell_val == 27) {
			mage.set_recruited(true);

			if (!bandit1_b) {
				story.meetOrion_loseBandits();
				mage.set_stats("cur_health", 20);
				mage.set_stats("cur_mp", 50);
			}
			else {
				story.interactWCampBandits_winBandits();
			}

			start_battle("bandit_2");

			board.set_board(9, 31, 0);
			board.set_board(8, 30, 0);
			board.set_board(8, 32, 0);
			board.set_board(7, 31, 0);

			teleport_ply(8, 31);

			for (int i = 20; i < 30; ++i)
				board.set_board(15, i, 6);

			for (int i = 5; i < 8; ++i)
				board.set_board(i, 49, 0);

			swordsman.set_active(3, true);
			mage.set_active(3, true);
			elf.set_active(3, true);
			assassin.set_active(3, true);

			if (swordsman.get_stats("cur_health") <= 0)
				break;

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 19) {
			// Switch red

			board.set_board(tmp_target_cell[0], tmp_target_cell[1], 20);

			if (board.get_board(3, 59) == (bandit_puz_a[0] ? 20 : 19) && board.get_board(9, 59) == (bandit_puz_a[1] ? 20 : 19) && board.get_board(3, 73) == (bandit_puz_a[2] ? 20 : 19) && board.get_board(9, 73) == (bandit_puz_a[3] ? 20 : 19)) {
				for (int i = 0; i < 7; i++)
					board.set_board((3 + i), 79, 0);
			}
			else {
				for (int i = 0; i < 7; i++)
					board.set_board((3 + i), 79, 6);
			}

			if (!bandit_trea_r && board.get_board(3, 79) == 0) {
				if (elf.get_stats("cur_health") > 0 && mage.get_stats("cur_health") > 0) {
					if (story.meetBlaise_main()) {
						assassin.set_stats("cur_health", 0);
					}
				}
				else if (elf.get_stats("cur_health") <= 0 && mage.get_stats("cur_health") > 0) {
					if (story.meetBlaise_eloraDead()) {
						assassin.set_stats("cur_health", 0);
					}
				}
				else if (elf.get_stats("cur_health") > 0 && mage.get_stats("cur_health") <= 0) {
					story.meetBlaise_orionDead();
				}
				else {
					story.meetBlaise_partyDead();
				}

				assassin.set_recruited(true);
				assassin.set_active(2, true);

				bandit_trea_r = true;

				board.set_board(6, 81, 0);

				for (int i = 20; i < 30; ++i)
					board.set_board(15, i, 0);

				for (int i = 0; i < 7; i++)
					board.set_board(23, (88 + i), 0);

				prev_is_map = false;
				system("cls");
			}
			else {
				prev_is_map = true;
			}
		}
		else if (tmp_target_cell_val == 20) {
			// Switch blue

			board.set_board(tmp_target_cell[0], tmp_target_cell[1], 19);

			if (board.get_board(3, 59) == (bandit_puz_a[0] ? 20 : 19) && board.get_board(9, 59) == (bandit_puz_a[1] ? 20 : 19) && board.get_board(3, 73) == (bandit_puz_a[2] ? 20 : 19) && board.get_board(9, 73) == (bandit_puz_a[3] ? 20 : 19)) {
				for (int i = 0; i < 7; i++)
					board.set_board((3 + i), 79, 0);
			}
			else {
				for (int i = 0; i < 7; i++)
					board.set_board((3 + i), 79, 6);
			}

			if (!bandit_trea_r && board.get_board(3, 79) == 0) {
				if (elf.get_stats("cur_health") > 0 && mage.get_stats("cur_health") > 0) {
					if (story.meetBlaise_main()) {
						assassin.set_stats("cur_health", 0);
					}
				}
				else if (elf.get_stats("cur_health") <= 0 && mage.get_stats("cur_health") > 0) {
					if (story.meetBlaise_eloraDead()) {
						assassin.set_stats("cur_health", 0);
					}
				}
				else if (elf.get_stats("cur_health") > 0 && mage.get_stats("cur_health") <= 0) {
					story.meetBlaise_orionDead();
				}
				else {
					story.meetBlaise_partyDead();
				}

				assassin.set_recruited(true);
				assassin.set_active(2, true);

				bandit_trea_r = true;

				board.set_board(6, 81, 0);

				for (int i = 20; i < 30; ++i)
					board.set_board(15, i, 0);

				for (int i = 0; i < 7; i++)
					board.set_board(23, (88 + i), 0);

				prev_is_map = false;
				system("cls");
			}
			else {
				prev_is_map = true;
			}
		}
		else if (tmp_target_cell_val == 31) {
			story.collectTreasure();
			swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 50);
			board.set_board(6, 91, 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 74) {
			Common::cursor_vis(false);
			story.after_start_menu();
			board.set_board(135, 7, 0);
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 72) {
			Common::cursor_vis(false);
			story.npc19_20();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 75) {
			Common::cursor_vis(false);
			story.npc14(board.get_board(131, 27) == 0);
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 76) {
			Common::cursor_vis(false);
			story.npc15_16();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 77) {
			Common::cursor_vis(false);
			story.npc17_18();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 73) {
			Common::cursor_vis(false);
			story.prologue();

			for (int i = 2; i < 5; i++)
				board.set_board(131, (25 + i), 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 78) {
			Common::cursor_vis(false);
			story.meetOrion_winBandits();

			for (int i = 54; i < 61; ++i)
				board.set_board(19, i, 0);

			board.set_board(46, 59, 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 40) {

			Common::cursor_vis(false);
			story.excalibur_floor1InteractWBones();

			start_battle("dun_f1");

			for (int i = 0; i < 3; i++)
				board.set_board(34, (82 + i), 0);
			for (int i = 0; i < 7; i++)
				board.set_board(42, (88 + i), 0);

			if (swordsman.get_stats("cur_health") <= 0)
				break;

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 70) {

			story.excalibur_foundKey();
			board.set_board(56, 66, 0);
			
			dun_f2_k = true;

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 69) {

			story.excalibur_interactWOlaf();

			mage.set_recruited(false);
			elf.set_recruited(false);
			assassin.set_recruited(false);

			start_battle("dun_f3");

			board.set_board(70, 79, 0);

			if (swordsman.get_stats("cur_health") <= 0)
				break;

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 68) {

			story.excalibur_completed();
			swordsman.set_stats("attack", swordsman.get_stats("attack") + 20);

			board.set_board(73, 79, 0);

			for (int i = 0; i < 7; i++)
				board.set_board(63, (88 + i), 6);

			mage.set_recruited(true);
			elf.set_recruited(true);
			assassin.set_recruited(true);

			for (int i = 0; i < 7; i++)
				board.set_board(82, (88 + i), 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 82) {
			
			int tmp_count = 0;
			for (int i = 0; i < 4; ++i) {
				tmp_count += bandit_puz_a[i];
			}

			if (tmp_count < 2) {
				story.banditTreasureRoomHint(1);
			}
			else if (tmp_count == 2) {
				story.banditTreasureRoomHint(2);
			}
			else {
				story.banditTreasureRoomHint(3);
			}

			board.set_board(3, 50, 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 87) {
			story.excalibur_warning();
			board.set_board(61, 103, 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 83) {
			story.DKC_floor1();

			start_battle("dkc_1");

			for (int i = 0; i < 10; i++)
				board.set_board(64, (126 + i), 0);

			for (int i = 0; i < 3; i++)
				board.set_board(67, (129 + i), 0);

			prev_is_map = false;
			system("cls");

			if (swordsman.get_stats("cur_health") <= 0)
				break;
		}
		else if (tmp_target_cell_val == 84 || tmp_target_cell_val == 86) {
			story.DKC_floor2();

			start_battle("dkc_2");

			for (int i = 0; i < 10; i++)
				board.set_board(41, (126 + i), 0);

			board.set_board(44, 130, 0);
			board.set_board(45, 129, 0);
			board.set_board(45, 131, 0);

			prev_is_map = false;
			system("cls");

			if (swordsman.get_stats("cur_health") <= 0)
				break;
		}
		else if (tmp_target_cell_val == 88) {

			story.fairy_start(swordsman.get_item_qty("coin"));
			Common::cursor_vis(true);

			std::string fairy_inp = Common::input("Enter your choice : ");
			while (fairy_inp != "1" && fairy_inp != "2" && fairy_inp != "3") {
				Common::color_print(0x0C, "Invalid input! Please try again.");
				Common::set_cursor(20, 16);
				Common::mul_txt(" ", fairy_inp.length(), true);
				Common::set_cursor(0, 16);
				fairy_inp = Common::input("Enter your choice : ");
			}

			Common::cursor_vis(false);

			if (fairy_inp == "1" || fairy_inp == "2") {
				if (swordsman.get_item_qty("coin") >= 100) {
					if (fairy_inp == "1") {
						story.fairy_recoverHP();
						swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
						elf.set_stats("cur_health", elf.get_stats("max_health"));
						mage.set_stats("cur_health", mage.get_stats("max_health"));
						assassin.set_stats("cur_health", assassin.get_stats("max_health"));
					}
					else {
						story.fairy_recoverMP();
						swordsman.set_stats("cur_mp", swordsman.get_stats("max_mp"));
						elf.set_stats("cur_mp", elf.get_stats("max_mp"));
						mage.set_stats("cur_mp", mage.get_stats("max_mp"));
						assassin.set_stats("cur_mp", assassin.get_stats("max_mp"));
					}
					swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 100);
				}
				else {
					story.fairy_notEnoughCoins();
				}
			}
			else {
				story.fairy_refuse();
			}

			board.set_board(99, 110, 0);

			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 89) {
			story.npc21();
			prev_is_map = false;
			system("cls");
		}
		else if (tmp_target_cell_val == 90) {
			story.collectTreasure();
			swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") + 50);
			board.set_board(60, 65, 0);
			prev_is_map = false;
			system("cls");
		}
	}

	system("cls");
	std::cout << "Time taken : " << double(speedrun.end()) / 1000000000 << " seconds\n\nPress any key to continue";
	Common::any_key_press();
}

void Game::teleport_ply(int idx1, int idx2, bool clear)
{
	if (clear)
		board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
	swordsman.set_pos(idx1, idx2);
	board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

	// Calculates where to place the top down camera based on the player's (swordsman) position 
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

	const char* skill_name[]{ "Slash", "Fire Slash", "Taunt", "Spiral Spin", "Arcane Bullet", "Healing", "Enchant", "Fireball", "Shoot Arrow", "Raining Arrow", "Piercing Arrow", "Bullet Arrow", "Dagger Poke", "Strength Dart", "Bomb", "Backstab", "Headbutt", "Shield Bash", "Arm Slap", "Demon Slash", "Demon Eye Beam", "Demon Strength", "Fire Breath", "Demon Punch", "Long Live the King", "Demon Summon", "Hellfire" };
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

		Common::color_print(69, 5, 0x60, "   ");

		Common::color_print(71, 4, 0x60, "  ");

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