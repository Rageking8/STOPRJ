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
}

Board::~Board()
{
	delete[] board_data;
}

void Board::print_board()
{
	std::cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	for (int i = 0; i < 15; ++i) {
		std::cout << "|";
		for (int i2 = 0; i2 < 31; ++i2) {
			std::cout << "   |";
		}
		std::cout << "\n+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
	}
}

void Board::set_board(short idx1, short idx2, short data)
{
	board_data[(idx1 * 101) + idx2] = data;
}

short Board::get_board(short idx1, short idx2)
{
	return board_data[(idx1 * 101) + idx2];
}

void Board::color_print(unsigned short color_code, std::string txt)
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color_code);
	std::cout << txt;
	SetConsoleTextAttribute(h, 7);
}
