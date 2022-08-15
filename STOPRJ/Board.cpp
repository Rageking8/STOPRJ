#include "Board.h"
#include <iostream>
#include <string>
#include "Windows.h"

Board::Board()
{
	board_data = new short[101 * 101];
	for (int i = 0; i < (101 * 101); ++i) {
		board_data[i] = 0;
	}

	cam_pos[0] = 43;
	cam_pos[1] = 35;
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
					color_print(9, "PLY");
					break;
				case 2:
					color_print(10, "+++");
					break;
				default:
					std::cout << "   ";
			}
			std::cout << "|";
		}
		std::cout << "\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
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

void Board::color_print(unsigned short color_code, std::string txt)
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color_code);
	std::cout << txt;
	SetConsoleTextAttribute(h, 7);
}
