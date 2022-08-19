#pragma once
#include "Board.h"
#include "Swordsman.h"
#include "Mage.h"
#include "Elf.h"
#include "Assassin.h"
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
	Swordsman swordsman;
	Mage mage;
	Elf elf;
	Assassin assassin;

	Board board;

	Shop shops[2];

	Story story;

	int trigger_counter;

	void start_menu();

	bool valid_inp(std::string inp);
	void start_battle(std::string id);

	void print_all_skill();

	void board_gen();

	bool all_space(std::string inp);
};

