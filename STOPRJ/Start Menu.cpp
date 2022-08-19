#include "Game.h"
#include "Common.h"

void Game::start_menu()
{

	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xC0, "                         ");
	}
	for (int i = 1; i < 30; ++i) {
		Common::set_cursor(0, i);
		Common::color_print(0xC0, "  ");

		for (int i2 = 0; i2 < 11; ++i2)
			Common::color_print(0x80, "           ");

		Common::set_cursor(123, i);
		Common::color_print(0xC0, "  ");
	}
	Common::set_cursor(0, 30);
	for (int i = 0; i < 5; ++i) {
		Common::color_print(0xC0, "                         ");
	}

	Common::set_cursor(60, 15);

	Common::input("Start");

}