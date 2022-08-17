#include "Board.h"
#include "Common.h"
#include <iostream>
#include "Windows.h"

Board::Board() : cam_pos{}
{
	board_data = new short[101 * 101];
	for (int i = 0; i < (101 * 101); ++i) {
		board_data[i] = 0;
	}
}

Board::~Board()
{
	delete[] board_data;
}

void Board::print_board()
{
	std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	for (int i = cam_pos[0]; i < (cam_pos[0] + 15); ++i) {
		std::cout << "|";
		for (int i2 = cam_pos[1]; i2 < (cam_pos[1] + 31); ++i2) {
						switch (get_board(i, i2)) {
				case 1:
					Common::color_print(0X0B, "PLY");
					break;
				case 2: // Walls
					Common::color_print(0X70, "   ");
					break;
				case 3: // Shops
					Common::color_print(12, "Shp");
					break;
				case 4: // Water
					Common::color_print(0X90, "   ");
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
					Common::color_print(0X04, "Swi");
					break;
				case 20: // Green switch
					Common::color_print(0X02, "Swi");
					break;
				case 21: // Archer troop
					Common::color_print(0X07, " A ");
					break;
				case 22: // Mage troop
					Common::color_print(0X0D, " M ");
					break;
				case 23: // Demon King
					Common::color_print(0X0B, "DmK");
					break;
				default:
					std::cout << "   ";
			}
			std::cout << "|";
		}
		std::cout << "\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	}
}

void Board::print_map()
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	bool archer_town = false;
	const char* archer_town_txt = "Archer Town";
	for (int i = 30; i < 41; ++i) {
		if (board_data[(76 * 101) + i] != 0) {
			archer_town = true;
			break;
		}
	}

	bool mage_town = false;
	const char* mage_town_txt = "Mage Town";
	for (int i = 31; i < 40; ++i) {
		if (board_data[(41 * 101) + i] != 0) {
			mage_town = true;
			break;
		}
	}

	bool bandit_camp = false;
	const char* bandit_camp_txt = "Bandit Camp";
	for (int i = 19; i < 30; ++i) {
		if (board_data[(7 * 101) + i] != 0) {
			bandit_camp = true;
			break;
		}
	}

	for (int i = 0; i < 101; ++i) {
		for (int i2 = 0; i2 < 101; ++i2) {

			if (archer_town && i == 77 && (i2 >= 30 && i2 <= 40)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << archer_town_txt[i2 - 30];
				SetConsoleTextAttribute(h, 7);
				continue;
			}
			else if (!archer_town && i == 76 && (i2 >= 30 && i2 <= 40)) {
				SetConsoleTextAttribute(h, 14);
				std::cout << archer_town_txt[i2 - 30];
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

			if (board_data[(i * 101) + i2] == 1)
				Common::color_print(9, "P");
			else if (board_data[(i * 101) + i2] == 2)
				std::cout << "#";
			else if (board_data[(i * 101) + i2] == 3)
				Common::color_print(12, "S");
			else
				std::cout << ".";
		}
		std::cout << "\n";
	}

}

void Board::set_board(int idx1, int idx2, short data)
{
	board_data[(idx1 * 101) + idx2] = data;
}

short Board::get_board(int idx1, int idx2)
{
	return board_data[(idx1 * 101) + idx2];
}

void Board::set_cam(int idx1, int idx2)
{
	if ((idx1 >= 0 && idx1 <= 100) && (idx2 >= 0 && idx2 <= 100)) {
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
	else if (dir == 'S' && cam_pos[0] < 86)
		cam_pos[0] += 1;
	else if (dir == 'D' && cam_pos[1] < 70)
		cam_pos[1] += 1;
}
