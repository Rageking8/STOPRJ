#pragma once
#include "Board.h"
#include <string>

class Game
{
public:
	Game();
	~Game();
	void start();

private:
	Board board;

	std::string input(std::string txt);
};

