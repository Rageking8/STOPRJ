#pragma once
#include "Board.h"
#include "Character.h"
#include "Shop.h"
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

	Shop shops[2];

	std::string input(std::string txt);

	int rand_int(int min, int max);
	bool valid_inp(std::string inp);
};

