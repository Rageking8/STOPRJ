#pragma once
#include "Board.h"
#include "Character.h"
#include <string>

class Game
{
public:
	Game();
	~Game();
	void start();

private:
	Board board;
	Character player;

	std::string input(std::string txt);

	int rand_int(int min, int max);
};

