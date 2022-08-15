#pragma once
#include <string>

class Board
{
public:

	Board();
	~Board();
	void print_board();
	void set_board(int idx1, int idx2, short data);
	short get_board(int idx1, int idx2);
	void move_cam(char dir);

private:
	short* board_data;
	short cam_pos[2];

	void color_print(unsigned short color_code, std::string txt);
};

