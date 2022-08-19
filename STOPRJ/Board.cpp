#include "Board.h"
#include "Common.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

Board::Board() : cam_pos{}
{
	board_data = new short[151 * 151];
	for (int i = 0; i < (151 * 151); ++i) {
		board_data[i] = 0;
	}
}

Board::~Board()
{
	delete[] board_data;
}

void Board::print_board(bool state)
{
	// Use double buffering to reduce all flicker
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	static bool fir = false;
	static short last_state[31 * 15]{};

	int counter = 0;

	if (!fir || !state) {
		std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";

		for (int i = cam_pos[0]; i < (cam_pos[0] + 15); ++i) {
			std::cout << "|";
			for (int i2 = cam_pos[1]; i2 < (cam_pos[1] + 31); ++i2) {

				const short id = get_board(i, i2);

				last_state[counter] = id;
				counter++;

				print_with_id(id);
				std::cout << "|";
			}
			std::cout << "\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
		}

		fir = true;
	}
	else {
		for (int i = cam_pos[0]; i < (cam_pos[0] + 15); ++i) {
			for (int i2 = cam_pos[1]; i2 < (cam_pos[1] + 31); ++i2) {

				const short id = get_board(i, i2);

				if (id == last_state[counter]) {
					last_state[counter] = id;
					counter++;
					continue;
				}

				short x = 1 + (4 * (counter % 31));
				short y = 1 + (2 * (counter / 31));

				SetConsoleCursorPosition(h, COORD{ x, y });

				last_state[counter] = id;
				counter++;

				print_with_id(id);
			}
		}
	}
}

void Board::print_map()
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	bool kingdom_of_elves = false;
	const char* kingdom_of_elves_txt = "Kingdom of Elves";
	for (int i = 28; i < 44; ++i) {
		if (board_data[(77 * 151) + i] != 0) {
			kingdom_of_elves = true;
			break;
		}
	}

	bool mage_town = false;
	const char* mage_town_txt = "Mage Town";
	for (int i = 31; i < 40; ++i) {
		if (board_data[(41 * 151) + i] != 0) {
			mage_town = true;
			break;
		}
	}

	bool bandit_camp = false;
	const char* bandit_camp_txt = "Bandit Camp";
	for (int i = 19; i < 30; ++i) {
		if (board_data[(7 * 151) + i] != 0) {
			bandit_camp = true;
			break;
		}
	}

	for (int i = 0; i < 151; ++i) {
		for (int i2 = 0; i2 < 151; ++i2) {

			if (kingdom_of_elves && i == 78 && (i2 >= 28 && i2 <= 43)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << kingdom_of_elves_txt[i2 - 28];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (!kingdom_of_elves && i == 77 && (i2 >= 28 && i2 <= 43)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << kingdom_of_elves_txt[i2 - 28];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (mage_town && i == 42 && (i2 >= 31 && i2 <= 39)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << mage_town_txt[i2 - 31];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (!mage_town && i == 41 && (i2 >= 31 && i2 <= 39)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << mage_town_txt[i2 - 31];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (bandit_camp && i == 8 && (i2 >= 19 && i2 <= 29)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << bandit_camp_txt[i2 - 19];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (!bandit_camp && i == 7 && (i2 >= 19 && i2 <= 29)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << bandit_camp_txt[i2 - 19];
				SetConsoleTextAttribute(h, 7);
				continue;
			}

			switch (board_data[(i * 151) + i2]) {
				case 1:
					Common::color_print(0X0B, "P");
					break;
				case 2: // Walls
					Common::color_print(0X07, "#");
					break;
				case 3: // Shops
					Common::color_print(0X0C, "S");
					break;
				case 4: // Water
					Common::color_print(0X09, "#");
					break;
				case 5: // Cart
					Common::color_print(0X70, "?");
					break;
				case 6: // Gray block
					Common::color_print(0X08, "#");
					break;
				case 7: // Blue block
					Common::color_print(0X01, "#");
					break;
				case 8: // Green block
					Common::color_print(0X02, "#");
					break;
				case 9: // Aqua block
					Common::color_print(0X03, "#");
					break;
				case 10: // Red block
					Common::color_print(0X04, "#");
					break;
				case 11: // Purple block
					Common::color_print(0X05, "#");
					break;
				case 12: // Yellow block
					Common::color_print(0X06, "#");
					break;
				case 13: // Light Green block
					Common::color_print(0X0A, "#");
					break;
				case 14: // Light Aqua block
					Common::color_print(0X0B, "#");
					break;
				case 15: // Light Red block
					Common::color_print(0X0C, "#");
					break;
				case 16: // Light Purple block
					Common::color_print(0X0D, "#");
					break;
				case 17: // Light Yellow block
					Common::color_print(0X0E, "#");
					break;
				case 18: // Bright White block
					Common::color_print(0X0F, "#");
					break;
				case 19: // Red switch
					Common::color_print(0X70, "?");
					break;
				case 20: // Green switch
					Common::color_print(0X70, "?");
					break;
				case 21: // Elf troop
					Common::color_print(0X70, "?");
					break;
				case 22: // Mage troop
					Common::color_print(0X70, "?");
					break;
				case 23: // Demon King
					Common::color_print(0X70, "?");
					break;
				case 24: // Grand Master Mage
					Common::color_print(0X70, "?");
					break;
				case 26: // Bandit troop/Enemy
					Common::color_print(0X70, "?");
					break;
				case 27: // Bandit Leader
					Common::color_print(0X70, "?");
					break;
				case 28: // Kingdom of Elves Leader House Walls
					Common::color_print(0X0E, "#");
					break;
				case 29: // Kingdom of Elves Leader
					Common::color_print(0X70, "?");
					break;
				case 30: // Grass + Flower
					Common::color_print(0X02, "#");
					break;
				case 31: // Chest
					Common::color_print(0X70, "?");
					break;
				case 32: // Fire wood
					Common::color_print(0X04, "#");
					break;
				case 33: // Fire or Box with '~+~' init
					Common::color_print(0X04, "#");
					break;
				case 34: // Dining Table
					Common::color_print(0X06, "#");
					break;
				case 35: //Chair facing right
					Common::color_print(0X0C, "#");
					break;
				case 36: //Chair facing left
					Common::color_print(0X0C, "#");
					break;
				case 37: // Fire wood 2
					Common::color_print(0X04, "#");
					break;
				case 38: //Stairs/Step left
					Common::color_print(0X08, "#");
					break;
				case 39: //Stairs/Step right
					Common::color_print(0X08, "#");
					break;
				case 40: // Skeleton
					Common::color_print(0X70, "?");
					break;
				case 41: // Demon
					Common::color_print(0X70, "?");
					break;
				default:
					std::cout << ".";
			}
		}
		std::cout << "\n";
	}

}

void Board::set_board(int idx1, int idx2, short data)
{
	board_data[(idx1 * 151) + idx2] = data;
}

short Board::get_board(int idx1, int idx2)
{
	return board_data[(idx1 * 151) + idx2];
}

void Board::set_cam(int idx1, int idx2)
{
	if ((idx1 >= 0 && idx1 <= 150) && (idx2 >= 0 && idx2 <= 150)) {
		cam_pos[0] = idx1;
		cam_pos[1] = idx2;
	}
}

void Board::move_cam(char dir)
{
	if (dir == 'W' && cam_pos[0] > 0)
		cam_pos[0] -= 1;
	else if (dir == 'A' && cam_pos[1] > 0)
		cam_pos[1] -= 1;
	else if (dir == 'S' && cam_pos[0] < 136)
		cam_pos[0] += 1;
	else if (dir == 'D' && cam_pos[1] < 120)
		cam_pos[1] += 1;
}

void Board::print_with_id(short id)
{
	switch (id) {
		case 1:
			Common::color_print(0X0B, "PLY");
			break;
		case 2: // Walls
			Common::color_print(0X70, " ");
			Common::color_print(0XF0, " ");
			Common::color_print(0X70, " ");
			break;
		case 3: // Shops
			Common::color_print(12, "Shp");
			break;
		case 4: // Water
			Common::color_print(0X91, " ~ ");
			break;
		case 5: // Cart
			Common::color_print(0X0E, "Crt");
			break;
		case 6: // Gray block
			Common::color_print(0X80, "   ");
			break;
		case 7: // Blue block
			Common::color_print(0X10, "   ");
			break;
		case 8: // Green block
			Common::color_print(0X20, "   ");
			break;
		case 9: // Aqua block
			Common::color_print(0X30, "   ");
			break;
		case 10: // Red block
			Common::color_print(0X40, "   ");
			break;
		case 11: // Purple block
			Common::color_print(0X50, "   ");
			break;
		case 12: // Yellow block
			Common::color_print(0X60, "   ");
			break;
		case 13: // Light Green block
			Common::color_print(0XA0, "   ");
			break;
		case 14: // Light Aqua block
			Common::color_print(0XB0, "   ");
			break;
		case 15: // Light Red block
			Common::color_print(0XC0, "   ");
			break;
		case 16: // Light Purple block
			Common::color_print(0XD0, "   ");
			break;
		case 17: // Light Yellow block
			Common::color_print(0XE0, "   ");
			break;
		case 18: // Bright White block
			Common::color_print(0XF0, "   ");
			break;
		case 19: // Red switch
			Common::color_print(0X4F, "Swi");
			break;
		case 20: // Green switch
			Common::color_print(0X2F, "Swi");
			break;
		case 21: // Elf troop
			Common::color_print(0X02, " A ");
			break;
		case 22: // Mage troop
			Common::color_print(0X0D, " M ");
			break;
		case 23: // Demon King
			Common::color_print(0X0B, "DmK");
			break;
		case 24: // Grand Master Mage
			Common::color_print(0X05, "GmM");
			break;
		case 25: // Directory sign
			Common::color_print(0x0C, "<->");
			break;
		case 26: // Bandit troop/Enemy
			Common::color_print(0X0C, " B ");
			break;
		case 27: // Bandit Leader "BdL"
			Common::color_print(0X04, "BdL");
			break;
		case 28: // Kingdom of Elves Leader House Walls
			Common::color_print(0XE0, " ");
			Common::color_print(0XF0, " ");
			Common::color_print(0XE0, " ");
			break;
		case 29: // Kingdom of Elves Leader
			Common::color_print(0X0A, "AcL");
			break;
		case 30: // Grass + Flower
			Common::color_print(0X20, " ");
			Common::color_print(0X40, " ");
			Common::color_print(0X20, " ");
			break;
		case 31: // Chest
			Common::color_print(0XE0, " + ");
			break;
		case 32: // Fire wood
			Common::color_print(0X04, " # ");
			break;
		case 33: // Fire or Box with '~+~' init
			Common::color_print(0X4E, "~+~");
			break;
		case 34: // Dining Table
			Common::color_print(0X60, "| |");
			break;
		case 35: // Chair facing right
			Common::color_print(0X40, " ");
			Common::color_print(0XC0, " ");
			Common::color_print(0XC0, " ");
			break;
		case 36: // Chair facing left
			Common::color_print(0XC0, " ");
			Common::color_print(0XC0, " ");
			Common::color_print(0X40, " ");
			break;
		case 37: // Fire wood 2
			Common::color_print(0X04, " = ");
			break;
		case 38: // Stairs/Step left
			Common::color_print(0X70, " ");
			Common::color_print(0X80, "  ");
			break;
		case 39: // Stairs/Step right
			Common::color_print(0X80, "  ");
			Common::color_print(0X70, " ");
			break;
		case 40: // Skeleton
			Common::color_print(0X04, " S ");
			break;
		case 41: // Demon
			Common::color_print(0X05, " D ");
			break;
		default:
			std::cout << "   ";
	}
}
