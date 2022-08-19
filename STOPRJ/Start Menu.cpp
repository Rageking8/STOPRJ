#include "Game.h"
#include "Common.h"

void Game::start_menu()
{

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}
	for (int i = 1; i < 30; ++i) {
		Common::set_cursor(0, i);
		Common::color_print(0xE0, "  ");

		for (int i2 = 0; i2 < 11; ++i2)
			Common::color_print(0x00, "           ");

		Common::set_cursor(123, i);
		Common::color_print(0xE0, "  ");
	}
	Common::set_cursor(0, 30);

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xE0, "                         ");
	}

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

	Common::set_cursor(84, 5);
	Common::color_print(0x60, "      ");

	for (int i = 0; i < 6; ++i) {
		Common::set_cursor(28 + (4 * i), 6);
		Common::color_print(0x60, "  ");

		Common::set_cursor(28 + (4 * i), 9);
		Common::color_print(0x60, "  ");
	}

	Common::set_cursor(46, 7);
	Common::color_print(0x60, "  ");

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

	Common::set_cursor(56, 12);
	Common::color_print(0x60, "     ");

	Common::set_cursor(60, 13);
	Common::color_print(0x60, "  ");

	Common::set_cursor(52, 23);
	Common::input("Press any key to start");

}