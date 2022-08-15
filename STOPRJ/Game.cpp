#include "Game.h"
#include <iostream>
#include <string>
#include <random>

Game::Game()
{
	board.set_board(100, 50, 1);
	player.set_pos(100, 50);

	for (int i = 0; i < 500; ++i) {
		int rand_1 = rand_int(0, 100);
		int rand_2 = rand_int(0, 100);
		if (rand_1 != 100 || rand_2 != 50) {
			board.set_board(rand_1, rand_2, 2);
		}
	}
}

Game::~Game()
{
}

void Game::start()
{
	system("cls");
	input("Ensure that the console window is full screen : ");

	while (true) {
		system("cls");
		board.print_board();
		std::cout << "Current pos : (" << player.get_pos(1) << ", " << player.get_pos(0) << ")\n";

		std::string action_inp = input("Enter action : ");

		while (action_inp != "w" && action_inp != "a" && action_inp != "s" && action_inp != "d" && action_inp != "W" && action_inp != "A" && action_inp != "S" && action_inp != "D") {
			action_inp = input("Invalid action\nEnter action : ");
		}

		if ((action_inp == "w" || action_inp == "W") && player.get_pos(0) > 0 && board.get_board(player.get_pos(0) - 1, player.get_pos(1)) == 0) {
			board.set_board(player.get_pos(0), player.get_pos(1), 0);
			player.move('W');
			board.set_board(player.get_pos(0), player.get_pos(1), 1);

			if (player.get_pos(0) < 93)
				board.move_cam('W');
		}
		else if ((action_inp == "a" || action_inp == "A") && player.get_pos(1) > 0 && board.get_board(player.get_pos(0), player.get_pos(1) - 1) == 0) {
			board.set_board(player.get_pos(0), player.get_pos(1), 0);
			player.move('A');
			board.set_board(player.get_pos(0), player.get_pos(1), 1);

			if (player.get_pos(1) < 85)
				board.move_cam('A');
		}
		else if ((action_inp == "s" || action_inp == "S") && player.get_pos(1) < 100 && board.get_board(player.get_pos(0) + 1, player.get_pos(1)) == 0) {
			board.set_board(player.get_pos(0), player.get_pos(1), 0);
			player.move('S');
			board.set_board(player.get_pos(0), player.get_pos(1), 1);

			if (player.get_pos(0) > 7)
				board.move_cam('S');
		}
		else if ((action_inp == "d" || action_inp == "D") && player.get_pos(1) < 100 && board.get_board(player.get_pos(0), player.get_pos(1) + 1) == 0) {
			board.set_board(player.get_pos(0), player.get_pos(1), 0);
			player.move('D');
			board.set_board(player.get_pos(0), player.get_pos(1), 1);

			if (player.get_pos(1) > 15)
				board.move_cam('D');
		}

	}
}

std::string Game::input(std::string txt)
{
	std::string ret;
	std::cout << txt;
	std::getline(std::cin, ret);
	return ret;
}

int Game::rand_int(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}
