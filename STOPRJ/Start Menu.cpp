#include "Game.h"
#include "Common.h"
#include "conio.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

std::string Game::start_menu()
{

	Common::print_frame();

	// first word
	for (int i = 0; i < 3; ++i) {
		Common::set_cursor(29 + (8 * i), 5);
		Common::color_print(0x60, "    ");

		Common::set_cursor(52 + (8 * i), 5);
		Common::color_print(0x60, "      ");

		Common::set_cursor(80, 8 + i);
		Common::color_print(0x60, "  ");
	}

	for (int i = 0; i < 4; ++i) {
		for (int i2 = 0; i2 < 5; ++i2) {
			Common::set_cursor(68 + (8 * i), 6 + i2);
			Common::color_print(0x60, "  ");
		}

		Common::set_cursor(96, 6 + i);
		Common::color_print(0x60, "  ");
	}

	Common::color_print(84, 5, 0x60, "      ");

	for (int i = 0; i < 6; ++i) {
		Common::set_cursor(28 + (4 * i), 6);
		Common::color_print(0x60, "  ");

		Common::set_cursor(28 + (4 * i), 9);
		Common::color_print(0x60, "  ");
	}

	Common::color_print(46, 7, 0x60, "  ");

	for (int i = 0; i < 2; ++i) {
		Common::set_cursor(29 + (8 * i), 10);
		Common::color_print(0x60, "    ");

		Common::set_cursor(29 + (2 * i), 7 + i);
		Common::color_print(0x60, "  ");

		Common::set_cursor(36, 7 + i);
		Common::color_print(0x60, "  ");

		Common::set_cursor(76 + (16 * i), 5);
		Common::color_print(0x60, "     ");

		Common::set_cursor(68 + (16 * i), 10);
		Common::color_print(0x60, "      ");

		Common::set_cursor(68 + (16 * i), 7);
		Common::color_print(0x60, "      ");

		Common::set_cursor(76 + (16 * i), 7 + (3 * i));
		Common::color_print(0x60, "     ");

		for (int i2 = 0; i2 < 4; ++i2) {
			Common::set_cursor(44 + (4 * i), 7 + i2);
			Common::color_print(0x60, "  ");
		}

		for (int i2 = 0; i2 < 5; ++i2) {
			Common::set_cursor(54 + (8 * i), 6 + i2);
			Common::color_print(0x60, "  ");
		}
	};

	Common::set_cursor(80, 6);
	Common::color_print(0x60, "  ");

	// second word
	for (int i = 0; i < 2; ++i) {
		for (int i2 = 0; i2 < 6; ++i2) {
			Common::set_cursor(40 + (4 * i), 12 + i2);
			Common::color_print(0x60, "  ");

			Common::set_cursor(48 + (24 * i), 12 + i2);
			Common::color_print(0x60, "  ");
		}

		for (int i2 = 0; i2 < 2; ++i2) {
			Common::set_cursor(48 + (24 * i), 12 + (2 * i2));
			Common::color_print(0x60, "      ");
		}

		Common::set_cursor(48 + (24 * i), 17);
		Common::color_print(0x60, "      ");

		Common::set_cursor(40 + (16 * i), 14);
		Common::color_print(0x60, "     ");

		Common::set_cursor(65, 12 + (5 * i));
		Common::color_print(0x60, "    ");

		for (int i2 = 0; i2 < 4; ++i2) {
			Common::set_cursor(64 + (4 * i), 13 + i2);
			Common::color_print(0x60, "  ");
		}

		Common::set_cursor(81, 12 + (5 * i));
		Common::color_print(0x60, "    ");

		Common::set_cursor(80, 13 + (3 * i));
		Common::color_print(0x60, "  ");

		Common::set_cursor(84, 13 + (3 * i));
		Common::color_print(0x60, "  ");

		Common::set_cursor(81 + (2 * i), 14 + (1 * i));
		Common::color_print(0x60, "  ");
	}

	for (int i = 0; i < 3; ++i) {
		Common::set_cursor(60, 15 + i);
		Common::color_print(0x60, "  ");
	}

	for (int i = 0; i < 6; ++i) {
		Common::set_cursor(56, 12 + i);
		Common::color_print(0x60, "  ");
	}

	Common::color_print(56, 12, 0x60, "     ");

	Common::color_print(60, 13, 0x60, "  ");

	Common::color_print(49, 23, 0x0A, ">> ");
	Common::color_print(0x0F, "Press any key to start");
	Common::color_print(0x0A, " <<");

	int c = _getch();
	if (c == 224) {
		c = _getch();
	}

	Common::color_print(49, 23, 0x0F, "                            ");


	for (int i = 22; i < 27; ++i) {
		Common::color_print(34, i, 0x90, " ");
		Common::color_print(90, i, 0x90, " ");
		if (i == 22 || i == 26)
			Common::color_print(35, i, 0xE0, "   ");
	}
	for (int i = 0; i < 13; ++i) {
		Common::color_print((i * 4) + 38, 22, 0xE0, "    ");
		Common::color_print((i * 4) + 38, 26, 0xE0, "    ");
	}

	Common::cursor_vis(true);

	Common::color_print(37, 24, 0x07, "Enter name (alphanumeric, max 10) : ");

	short tmp_char_c = 0;
	std::string ret_name = "";

	// Once user press enter proceed
	while (true) {

		// Get input and properly handle edge cases
		int c = _getch();
		if (c == 224) {
			c = _getch();
		}

		// Handle enter
		if (c == 13 && ret_name.length() > 0) {
			break;
		}
		// Handle backspace
		else if (c == 8 && ret_name.length() > 0) {
			ret_name.pop_back();
			Common::move_cursor('A');
			std::cout << " ";
			Common::move_cursor('A');
		}
		// Handle digits (0-9)
		else if (c > 47 && c < 58 && ret_name.length() < 10) {
			std::cout << char((c - 48) + '0');
			ret_name += char((c - 48) + '0');
			tmp_char_c++;
		}
		// Handle letters (a-z)
		else if (c > 96 && c < 123 && ret_name.length() < 10) {
			std::cout << char((c - 97) + 'a');
			ret_name += char((c - 97) + 'a');
			tmp_char_c++;
		}
		// Handle letters (A-Z)
		else if (c > 64 && c < 91 && ret_name.length() < 10) {
			std::cout << char((c - 65) + 'A');
			ret_name += char((c - 65) + 'A');
			tmp_char_c++;
		}
	}

	Common::cursor_vis(false);

	return ret_name;
}
