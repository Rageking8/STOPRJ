#pragma once
#include "Board.h"
#include "Swordsman.h"
#include "Elf.h"
#include "Mage.h"
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
	// All the allies
	Swordsman swordsman;
	Mage mage;
	Elf elf;
	Assassin assassin;

	Board board;

	Shop shop;

	Story story;

	int trigger_counter;

	std::string start_menu();

	// Teleport the player to a new coordinate and move the top down camera accordingly
	void teleport_ply(int idx1, int idx2, bool clear = true);

	// Returns true if the input is a valid action in the main screen of the game, else false
	bool valid_inp(std::string inp);

	// Start a battle, input the id for a specific battle
	bool start_battle(std::string id);

	void print_all_skill();

	void board_gen();

	// Returns true if all characters in an std::string is the space character, else false
	bool all_space(std::string inp);
};

