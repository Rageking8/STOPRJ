#pragma once
#include <string>

class Board
{
public:

	Board();
	~Board();
	void print_board();
	void set_board(short idx1, short idx2, short data);

private:
	short* board_data;

	void color_print(unsigned short color_code, std::string txt);
};
