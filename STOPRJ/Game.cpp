#include "Game.h"
#include <string>
#include <random>
#include <iostream>
#include "Windows.h"

Game::Game()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	board.set_board(100, 80, 1);
	player.set_pos(100, 80);

	int tmp_cam_pos_i1 = 0;
	int tmp_cam_pos_i2 = 0;

	if (player.get_pos(0) < 7) {
		tmp_cam_pos_i1 = 0;
	}
	else if (player.get_pos(0) > 93) {
		tmp_cam_pos_i1 = 86;
	}
	else {
		tmp_cam_pos_i1 = player.get_pos(0) - 7;
	}

	if (player.get_pos(1) < 15) {
		tmp_cam_pos_i2 = 0;
	}
	else if (player.get_pos(1) > 85) {
		tmp_cam_pos_i2 = 86;
	}
	else {
		tmp_cam_pos_i2 = player.get_pos(1) - 15;
	}

	board.set_cam(tmp_cam_pos_i1, tmp_cam_pos_i2);

	board.set_board(99, 85, 1);
	player.set_pos(99, 85);

	//Treasure room
	for (int i = 1; i < 10; ++i) { // Column walls
		board.set_board((90 + i), 69, 2);
		board.set_board((90 + i), 90, 2);
	}
	for (int i = 69; i < 91; ++i) { // Row walls
		board.set_board(100, i, 2);
	}
	for (int i = 85; i < 91; i++) { // Row walls
		board.set_board(91, i, 2);
	}
	for (int i = 69; i < 75; i++) { // Row walls
		board.set_board(91, i, 2);
	}
	for (int i = 1; i < 5; ++i) { // Column walls
		board.set_board((86 + i), 74, 2);
		board.set_board((86 + i), 85, 2);
	}

	// Boss room 3 (Boss Fight/Throne room)
	for (int i = 59; i < 74; ++i) { // Row walls
		board.set_board(87, i, 2);
	}
	for (int i = 85; i < 101; ++i) { // Row walls
		board.set_board(87, i, 2);
	}
	for (int i = 1; i < 25; ++i) { // Column walls
		board.set_board((62 + i), 59, 2);
		board.set_board((62 + i), 100, 2);
	}
	for (int i = 59; i < 75; ++i) { // Row walls
		board.set_board(63, i, 2);
	}
	for (int i = 85; i < 101; ++i) { // Row walls
		board.set_board(63, i, 2);
	}
	for (int i = 1; i < 5; ++i) { // Column walls
		board.set_board((59 + i), 74, 2);
		board.set_board((59 + i), 85, 2);
	}
	// Boss room 2 (Mini-boss)
	for (int i = 62; i < 75; ++i) { // Row walls
		board.set_board(59, i, 2);
	}
	for (int i = 85; i < 98; ++i) { // Row walls
		board.set_board(59, i, 2);
	}
	for (int i = 1; i < 20; ++i) { // Column walls
		board.set_board((39 + i), 62, 2);
		board.set_board((39 + i), 97, 2);
	}
	for (int i = 62; i < 75; ++i) { // Row walls
		board.set_board(40, i, 2);
	}
	for (int i = 85; i < 98; ++i) { // Row walls
		board.set_board(40, i, 2);
	}
	for (int i = 1; i < 5; ++i) { // Column walls
		board.set_board((35 + i), 74, 2);
		board.set_board((35 + i), 85, 2);
	}
	//Boss room 1 (Skeleton Army)
	for (int i = 64; i < 75; ++i) { // Row walls
		board.set_board(35, i, 2);
	}
	for (int i = 85; i < 96; ++i) { // Row walls
		board.set_board(35, i, 2);
	}
	for (int i = 1; i < 15; ++i) { // Column walls
		board.set_board((20 + i), 64, 2);
		board.set_board((20 + i), 95, 2);
	}
	for (int i = 64; i < 75; ++i) { // Row walls
		board.set_board(20, i, 2);
	}
	for (int i = 85; i < 96; ++i) { // Row walls
		board.set_board(20, i, 2);
	}
	for (int i = 1; i < 5; ++i) { // Column walls
		board.set_board((15 + i), 74, 2);
		board.set_board((15 + i), 85, 2);
	}

	board.dump_world();
	while (true);

}

Game::~Game()
{
}

void Game::start()
{
	system("cls");
	// Inform user to check that console is full screen for the map to not be distorted
	input("Ensure that the console window is full screen : ");

	while (true) {
		system("cls");
		board.print_board();
		std::cout << "Current pos : (" << player.get_pos(1) << ", " << player.get_pos(0) << ")\n";

		std::string action_inp = input("Enter action (WASD for movement and IJKL for interaction) : ");

		// Loop till action input is valid (WASDIJKL)(non-case sensitive)
		while (!valid_inp(action_inp)) {
			system("cls");
			board.print_board();
			std::cout << "Current pos : (" << player.get_pos(1) << ", " << player.get_pos(0) << ")\n";
			action_inp = input("Invalid action\nEnter action (WASD for movement and IJKL for interaction) : ");
		}

		// For player movement (WASD)
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
		else if ((action_inp == "s" || action_inp == "S") && player.get_pos(0) < 100 && board.get_board(player.get_pos(0) + 1, player.get_pos(1)) == 0) {
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

		// For player interaction with landmarks (IJKL)
		else if ((action_inp == "i" || action_inp == "I") && player.get_pos(0) > 0) {

		}
		else if ((action_inp == "j" || action_inp == "J") && player.get_pos(1) > 0) {

		}
		else if ((action_inp == "k" || action_inp == "K") && player.get_pos(0) < 100) {

		}
		else if ((action_inp == "l" || action_inp == "L") && player.get_pos(1) < 100) {
			
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

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L");
}
