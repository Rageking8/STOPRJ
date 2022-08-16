#pragma once
#include "Board.h"
#include "Character.h"
#include "Shop.h"
#include "Story.h"
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

	Story story;

	bool valid_inp(std::string inp);
};

