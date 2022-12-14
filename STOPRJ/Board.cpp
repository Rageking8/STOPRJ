#include "Board.h"
#include "Common.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

Board::Board() : cam_pos{}
{
	board_data = new short[151 * 151]{};
}

Board::~Board()
{
	delete[] board_data;
}

void Board::print_board(bool state)
{
	// Use double buffering to reduce all flicker
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	auto draw_hr = [] {
		DWORD n;
		WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+―――+\n", 127, &n, nullptr);
	};

	static bool fir = false;
	static short last_state[31 * 15]{};

	int counter = 0;

	if (!fir || !state) {
		draw_hr();
		for (int i = cam_pos[0]; i < (cam_pos[0] + 15); ++i) {
			std::cout << "|";
			for (int i2 = cam_pos[1]; i2 < (cam_pos[1] + 31); ++i2) {

				const short id = get_board(i, i2);

				last_state[counter] = id;
				counter++;

				print_with_id(id);
				std::cout << "|";
			}
			std::cout << "\n";
			draw_hr();
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
	//Common::Timer t;
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	// Detect if there is space there for town.kingdom label, else init it to be rendered down
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

	int cluster = 0;

	for (int i = 0; i < 151; ++i) {
		for (int i2 = 0; i2 < 151; ++i2) {

			// Optimize map printing (~200% faster than without this code)
			if (board_data[(i * 151) + i2] == 0) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 0) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				// Important. Using for loop to print will negate all performance gains
				std::string tmp_str = Common::mul_txt(".", cluster);
				std::cout << tmp_str;

				cluster = 0;
				continue;
			}
			else if (board_data[(i * 151) + i2] == 4) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 4) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				std::string tmp_str = Common::mul_txt("~", cluster);
				Common::color_print(0x09, tmp_str);
				cluster = 0;
				continue;
			}
			else if (board_data[(i * 151) + i2] == 7) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 7) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				std::string tmp_str = Common::mul_txt("~", cluster);
				Common::color_print(0x01, tmp_str);
				cluster = 0;
				continue;
			}
			else if (board_data[(i * 151) + i2] == 2) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 2) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				std::string tmp_str = Common::mul_txt("#", cluster);
				std::cout << tmp_str;
				cluster = 0;
				continue;
			}
			else if (board_data[(i * 151) + i2] == 42) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 42) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				std::string tmp_str = Common::mul_txt("#", cluster);
				Common::color_print(0x0A, tmp_str);
				cluster = 0;
				continue;
			}
			else if (board_data[(i * 151) + i2] == 60) {
				cluster++;
				while (i2 < 150) {
					if (board_data[(i * 151) + i2 + 1] == 60) {
						cluster++;
						i2++;
						continue;
					}
					break;
				}

				std::string tmp_str = Common::mul_txt("~", cluster);
				Common::color_print(0x04, tmp_str);
				cluster = 0;
				continue;
			}

			switch (board_data[(i * 151) + i2]) {
				case -86: //Bridge
					Common::color_print(0X06, "=");
					break;
				case -85: // Door Vertical
					Common::color_print(0X0E, "=");
					break;
				case -84: // Door Horizontal
					Common::color_print(0X0E, "=");
					break;
				case -67: // Green Carpet hori
					Common::color_print(0X02, "=");
					break;
				case -66: // Gren Carpet vert
					Common::color_print(0X02, "=");
					break;
				case -65: // Dungeon Walls
					Common::color_print(0X08, "#");
					break;
				case -64: // Red Carpet hori
					Common::color_print(0X04, "=");
					break;
				case -63: // Red Carpet vert
					Common::color_print(0X04, "=");
					break;
				case -61: // Gold Coins
					Common::color_print(0X06, "$");
					break;
				case -55: // Lavender
					Common::color_print(0X05, "=");
					break;
				case -54: // Rose
					Common::color_print(0X04, "=");
					break;
				case -53: // Sunflower
					Common::color_print(0X06, "=");
					break;
				case -42: // Grass Block
					Common::color_print(0X0A, "=");
					break;
				case -39: //Stairs/Step right
					Common::color_print(0X08, "=");
					break;
				case -38: //Stairs/Step left
					Common::color_print(0X08, "=");
					break;
				case -36: //Chair facing left
					Common::color_print(0X0C, "=");
					break;
				case -35: //Chair facing right
					Common::color_print(0X0C, "=");
					break;
				case -30: // Grass + Flower
					Common::color_print(0X02, "=");
					break;
				case -1:
					Common::color_print(0x70, "#");
					break;
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
					Common::color_print(0X09, "~");
					break;
				case 5: // Cart
					Common::color_print(0X70, "?");
					break;
				case 6: // Gray block
					Common::color_print(0X08, "#");
					break;
				case 7: // Blue block
					Common::color_print(0X01, "~");
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
				case 20: // Blue switch
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
				case 37: // Fire wood 2
					Common::color_print(0X04, "#");
					break;
				case 40: // Skeleton
					Common::color_print(0X70, "?");
					break;
				case 41: // Demon
					Common::color_print(0X70, "?");
					break;
				case 43: // Redwood tree trunk
					Common::color_print(0X0C, "#");
					break;
				case 44: // Redwood tree leaves
					Common::color_print(0X0A, "#");
					break;
				case 45: // Elf troop 2 - house
					Common::color_print(0X70, "?");
					break;
				case 46: // Elf troop 3 - exit
					Common::color_print(0X70, "?");
					break;
				case 47: // Mage troop 2 - inside house 1 #1
					Common::color_print(0X70, "?");
					break;
				case 48: // Mage troop 3 - inside house 3 #2
					Common::color_print(0X70, "?");
					break;
				case 49: // Mage troop 4 - inside house 6 #3
					Common::color_print(0X70, "?");
					break;
				case 50: // Mage troop 5 - First Mage NPC to greet at the start #4
					Common::color_print(0X70, "?");
					break;
				case 51: // Mage troop 6 - Second Mage NPC Saying random stuff #5
					Common::color_print(0X70, "?");
					break;
				case 52: // Mage troop 7 - Third Mage NPC Saying a wish at the fountain #6
					Common::color_print(0X70, "?");
					break;
				case 56: // Cage
					Common::color_print(0X08, "#");
					break;
				case 60: // Lava
					Common::color_print(0X04, "~");
					break;
				case 61: // Gold Coins
					Common::color_print(0X06, "$");
					break;
				case 62: // Demon kinng castle walls
					Common::color_print(0X04, "#");
					break;
				case 65: // Dungeon Walls
					Common::color_print(0X08, "#");
					break;
				case 68: // Excalibur Sword
					Common::color_print(0X70, "?");
					break;
				case 69: // Guardian
					Common::color_print(0X70, "?");
					break;
				case 70: // Key
					Common::color_print(0X70, "?");
					break;
				case 71: // Dungeon maze Walls
					Common::color_print(0X08, "#");
					break;
				case 72: // NPCs in Moris Empire
					Common::color_print(0X70, "?"); // Guards
					break;
				case 73: // Emperor
					Common::color_print(0X70, "?");
					break;
				case 74: // NPCs in Moris Empire
					Common::color_print(0X70, "?"); // Messenger
					break;
				case 75: // NPCs in Moris Empire
					Common::color_print(0X70, "?"); // Docks
					break;
				case 76: // NPCs in Moris Empire
					Common::color_print(0X70, "?"); // Fountain
					break;
				case 77: // NPCs in Moris Empire
					Common::color_print(0X70, "?"); // Garden
					break;
				case 78: // Orions Heros
					Common::color_print(0X70, "?");
					break;
				case 79: // Blaise
					Common::color_print(0X70, "?");
					break;
				case 80: // fish right
					Common::color_print(0X0C, "#");
					break;
				case 81: // fish right
					Common::color_print(0X0C, "#");
					break;
				case 82: // Bandit camp treasure room note
					Common::color_print(0X70, "?");
					break;
				case 83: // Lava Skeleton boss room 1
					Common::color_print(0X70, "?");
					break;
				case 84: // Lava Skeleton boss room 2
					Common::color_print(0X70, "?");
					break;
				case 85: // Lava Skeleton boss room 3
					Common::color_print(0X70, "?");
					break;
				case 86: // Demon boss room 2
					Common::color_print(0X70, "?");
					break;
				case 87: // Dungeon romm 2 note
					Common::color_print(0X70, "?");
					break;
				case 88: // Fairy
					Common::color_print(0X70, "?");
					break;
				case 89: // Boat NPC below kingdom of elves
					Common::color_print(0X70, "?");
					break;
				case 90: // Chest in maze
					Common::color_print(0X70, "?");
					break;
				default:
					std::cout << ".";
			}
		}
		std::cout << "\n";
	}

	if (kingdom_of_elves) {
		Common::color_print(28, 78, 0x0E, kingdom_of_elves_txt);
	}
	else {
		Common::color_print(28, 77, 0x0E, kingdom_of_elves_txt);
	}
	
	if (mage_town) {
		Common::color_print(31, 42, 0x0E, mage_town_txt);
	}
	else {
		Common::color_print(31, 41, 0x0E, mage_town_txt);
	}

	if (bandit_camp) {
		Common::color_print(19, 8, 0x0E, bandit_camp_txt);
	}
	else {
		Common::color_print(19, 7, 0x0E, bandit_camp_txt);
	}

	Common::set_cursor(0, 151);

	//std::cout << t.end();
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
		case -86: // Bridge
			Common::color_print(0XE0, "|");
			Common::color_print(0X60, "-");
			Common::color_print(0XE0, "|");
			break;
		case -85: // Door Vertical
			Common::color_print(0X0E, "[-]");
			break;
		case -84: // Door Horizontal
			Common::color_print(0X0E, "[|]");
			break;
		case -67: // Green Carpet hori
			Common::color_print(0X20, "___");
			break;
		case -66: // Gren Carpet vert
			Common::color_print(0X20, " | ");
			break;
		case -65: // Dungeon Walls
			Common::color_print(0X80, "#");
			Common::color_print(0X70, "#");
			Common::color_print(0X80, "#");
			break;
		case -64: // Red Carpet hori
			Common::color_print(0X40, "___");
			break;
		case -63: // Red Carpet vert
			Common::color_print(0X40, " | ");
			break;
		case -61: // Gold Coins
			Common::color_print(0X6F, " $ ");
			break;
		case -55: // Lavender
			Common::color_print(0X00, " ");
			Common::color_print(0X5D, "#");
			Common::color_print(0X00, " ");
			break;
		case -54: // Rose
			Common::color_print(0X00, " ");
			Common::color_print(0X4C, "@");
			Common::color_print(0X00, " ");
			break;
		case -53: // Sunflower
			Common::color_print(0X00, " ");
			Common::color_print(0X60, "*");
			Common::color_print(0X00, " ");
			break;
		case -42: // Grass Block
			Common::color_print(0XA2, " + ");
			break;
		case -39: // Stairs/Step right
			Common::color_print(0X80, "  ");
			Common::color_print(0X70, " ");
			break;
		case -38: // Stairs/Step left
			Common::color_print(0X70, " ");
			Common::color_print(0X80, "  ");
			break;
		case -36: // Chair facing left
			Common::color_print(0XC0, " ");
			Common::color_print(0XC0, " ");
			Common::color_print(0X40, " ");
			break;
		case -35: // Chair facing right
			Common::color_print(0X40, " ");
			Common::color_print(0XC0, " ");
			Common::color_print(0XC0, " ");
			break;
		case -30: // Grass + Flower
			Common::color_print(0X20, " ");
			Common::color_print(0X4E, "*");
			Common::color_print(0X20, " ");
			break;
		case -25: // Directory sign
			Common::color_print(0x0C, "<->");
			break;
		case -2: // Grass walkable
			Common::color_print(0X0A, "+++");
			break;
		case -1:
			Common::color_print(0x70, "TTT");
			break;
		case 1:
			Common::color_print(0X0B, "PLY");
			break;
		case 2: // Walls
			Common::color_print(0X70, " ");
			Common::color_print(0XF0, "-");
			Common::color_print(0X70, " ");
			break;
		case 3: // Shops
			Common::color_print(12, "Shp");
			break;
		case 4: // Water
			Common::color_print(0X9F, " ~ ");
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
		case 20: // Blue switch 
			Common::color_print(0X1F, "Swi");
			break;
		case 21: // Elf troop 1
			Common::color_print(0X02, " E ");
			break;
		case 22: // Mage troop 1 training
			Common::color_print(0X0D, " M ");
			break;
		case 23: // Demon King
			Common::color_print(0X0B, "DmK");
			break;
		case 24: // Grand Master Mage
			Common::color_print(0X05, "GmM");
			break;
		case 26: // Bandit troop/Enemy
			Common::color_print(0X0C, " B ");
			break;
		case 27: // Bandit Leader "BdL"
			Common::color_print(0X04, "BdL");
			break;
		case 28: // Elf Leader House Walls
			Common::color_print(0XE0, " ");
			Common::color_print(0XF0, " ");
			Common::color_print(0XE0, " ");
			break;
		case 29: // Kingdom of Elves Leader
			Common::color_print(0X0A, "Elr");
			break;
		case 31: // Chest
			Common::color_print(0XE0, " $ ");
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
		case 37: // Fire wood 2
			Common::color_print(0X04, " = ");
			break;
		case 40: // Skeleton in dungeon
			Common::color_print(0X04, " S ");
			break;
		case 41: // Demon boss room 3
			Common::color_print(0X05, " D ");
			break;
		case 43: // Redwood tree trunk
			Common::color_print(0XC4, " @ ");
			break;
		case 44: // Redwood tree leaves
			Common::color_print(0XA0, "   ");
			break;
		case 45: // Elf troop 2 - house
			Common::color_print(0X02, " E ");
			break;
		case 46: // Elf troop 3 - exit
			Common::color_print(0X02, " E ");
			break;
		case 47: // Mage troop 2 - inside house 1 #1
			Common::color_print(0X0D, " M ");
			break;
		case 48: // Mage troop 3 - inside house 3 #2
			Common::color_print(0X0D, " M ");
			break;
		case 49: // Mage troop 4 - inside house 6 #3
			Common::color_print(0X0D, " M ");
			break;
		case 50: // Mage troop 5 - First Mage NPC to greet at the start #4
			Common::color_print(0X0D, " M ");
			break;
		case 51: // Mage troop 6 - Second Mage NPC Saying random stuff #5
			Common::color_print(0X0D, " M ");
			break;
		case 52: // Mage troop 7 - Third Mage NPC Saying a wish at the fountain #6
			Common::color_print(0X0D, " M ");
			break;
		case 56: // Cage
			Common::color_print(0X80, " ");
			Common::color_print(0X78, "=");
			Common::color_print(0X80, " ");
			break;
		case 57: // Missing Mage in forest-Entrance #1 
			Common::color_print(0X0D, " M ");
			break;
		case 58: // Missing Mage in forest-Cage #2
			Common::color_print(0X0D, " M ");
			break;
		case 59: // Missing Mage in forest-Garden #3
			Common::color_print(0X0D, " M ");
			break;
		case 60: // Lava
			Common::color_print(0X46, " ~ ");
			break;
		case 61: // Gold Coins
			Common::color_print(0X6F, " + ");
			break;
		case 62: // Demon King Castle Walls
			Common::color_print(0X40, "=");
			Common::color_print(0XC0, "=");
			Common::color_print(0X40, "=");
			break;
		case 65: // Dungeon Walls
			Common::color_print(0X80, "#");
			Common::color_print(0X70, "#");
			Common::color_print(0X80, "#");
			break;
		case 68: // Excalibur Sword
			Common::color_print(0XB0, "_");
			Common::color_print(0X0F, "|");
			Common::color_print(0XB0, "_");
			break;
		case 69: // Olaf the stone giant
			Common::color_print(0X03, "Olf");
			break;
		case 70: // Key
			Common::color_print(0X00, " ");
			Common::color_print(0XE0, "?");
			Common::color_print(0X00, " ");
			break;
		case 71: // Dungeon maze Walls
			Common::color_print(0X80, "#");
			Common::color_print(0X70, "#");
			Common::color_print(0X80, "#");
			break;
		case 72: // NPCs in Moris Empire
			Common::color_print(0X0E, "GuR"); // Guards
			break;
		case 73: // Emperor
			Common::color_print(0X06, "EMP");
			break;
		case 74: // NPCs in Moris Empire
			Common::color_print(0X09, "MoR"); // Messenger
			break;
		case 75: // NPCs in Moris Empire
			Common::color_print(0X09, "PaU"); // Docks
			break;
		case 76: // NPCs in Moris Empire
			Common::color_print(0X09, "MoR"); // Fountain
			break;
		case 77: // NPCs in Moris Empire
			Common::color_print(0X09, "MoR"); // Garden
			break;
		case 78: // Orions Hero
			Common::color_print(0X0D, "Ori");
			break;
		case 79: // Blaise
			Common::color_print(0X0C, "Bls");
			break;
		case 80: // fish right
			Common::color_print(0X40, ">");
			Common::color_print(0X60, "|");
			Common::color_print(0X40, "*");
			break;
		case 81: // fish right
			Common::color_print(0X40, "*");
			Common::color_print(0X60, "|");
			Common::color_print(0X40, "<");
			break;
		case 82: // Bandit camp treasure room note
			Common::color_print(0XE0, "|N|");
			break;
		case 83: // Lava Skeleton boss room 1
			Common::color_print(0X04, " S ");
			break;
		case 84: // Lava Skeleton boss room 2
			Common::color_print(0X04, " S ");
			break;
		case 85: // Lava Skeleton boss room 3
			Common::color_print(0X04, " S ");
			break;
		case 86: // Demon boss room 2
			Common::color_print(0X05, " D ");
			break;
		case 87: // Dungeon romm 2 note
			Common::color_print(0XE0, "|N|");
			break;
		case 88: // Fairy
			Common::color_print(0X0D, "<F>");
			break;
		case 89: // Boat NPC below kingdom of elves
			Common::color_print(0X09, "PaU");
			break;
		case 90: // Chest in Maze
			Common::color_print(0XE0, " $ ");
			break;
		default:
			std::cout << "   ";
	}
}
