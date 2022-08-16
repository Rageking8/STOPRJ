#include "Game.h"
#include "Common.h"
#include <string>
#include <random>
#include <iostream>
#include "Windows.h"

Game::Game()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	std::ios_base::sync_with_stdio(false);

	board.set_board(97, 0, 1);
	player.set_pos(97, 0);

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

	// Map generation
	// Treasure room
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
	for (int i = 62; i < 75; ++i) { // Row walls
		board.set_board(35, i, 2);
	}
	for (int i = 85; i < 98; ++i) { // Row walls
		board.set_board(35, i, 2);
	}
	for (int i = 1; i < 15; ++i) { // Column walls
		board.set_board((20 + i), 62, 2);
		board.set_board((20 + i), 97, 2);
	}
	for (int i = 62; i < 75; ++i) { // Row walls
		board.set_board(20, i, 2);
	}
	for (int i = 85; i < 98; ++i) { // Row walls
		board.set_board(20, i, 2);
	}
	for (int i = 1; i < 5; ++i) { // Column walls
		board.set_board((15 + i), 74, 2);
	}
	for (int i = 1; i < 10; ++i) { // Column walls
		board.set_board((11 + i), 85, 2);
	}
	//Bandit camp
	for (int i = 0; i < 50; ++i) // Row walls
	{
		board.set_board(0, i, 2);
	}
	for (int i = 0; i < 15; i++) // Column walls
	{
		board.set_board(i, 0, 2);
	}
	for (int i = 0; i < 2; i++)
	{
		board.set_board(i, 49, 2);
	}
	for (int i = 0; i < 6; i++)
	{
		board.set_board((10 + i), 49, 2);
	}
	for (int i = 0; i < 20; ++i) // Bottom Row Left walls
	{
		board.set_board(15, i, 2);
	}
	for (int i = 30; i < 66; ++i) // Bottom Row Right walls
	{
		board.set_board(15, i, 2);
	}
	for (int i = 0; i < 4; i++) // Column Entrance left walls
	{
		board.set_board((16 + i), 19, 2);
	}
	//Starting path to Elf Archer Town
	for (int i = 0; i < 59; ++i) // Row walls
	{
		board.set_board(100, i, 2);
	}
	for (int i = 0; i < 24; ++i) // Row walls
	{
		board.set_board(94, i, 2);
	}
	for (int i = 25; i < 48; ++i) // Row walls
	{
		board.set_board(94, i, 2);
	}
	for (int i = 23; i < 26; ++i) // Row walls
	{
		board.set_board(93, i, 2);
	}
	for (int i = 0; i < 7; i++) // Column walls
	{
		board.set_board((88 + i), 47, 2);
	}
	for (int i = 0; i < 37; i++) // Column walls + Archer Town Column right walls
	{
		board.set_board((63 + i), 58, 2);
	}
	//Archer Town
	for (int i = 11; i < 48; ++i) // Row walls
	{
		board.set_board(87, i, 2);
	}
	for (int i = 11; i < 59; ++i) // Row walls
	{
		board.set_board(63, i, 2);
	}
	for (int i = 0; i < 5; i++) // Column up left walls
	{
		board.set_board((63 + i), 11, 2);
	}
	for (int i = 0; i < 12; i++) // Column walls
	{
		board.set_board((75 + i), 11, 2);
	}

	// Fountain border
	for (int i = 0; i < 3; ++i) {
		board.set_board(80, (34 + i), 2);
		board.set_board(84, (34 + i), 2);
	}
	for (int i = 0; i < 2; ++i) {
		board.set_board(81 + (i * 2), 33, 2);
		board.set_board(81 + (i * 2), 37, 2);
	}
	board.set_board(82, 32, 2);
	board.set_board(82, 38, 2);

	// Fountain water
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(81 + i, 34 + i2, 4);
	}
	board.set_board(82, 33, 4);
	board.set_board(82, 37, 4);


	//Path to Mage Town
	for (int i = 6; i < 11; ++i) // Row walls
	{
		board.set_board(67, i, 2);
	}
	for (int i = 0; i < 11; ++i) // Row walls
	{
		board.set_board(75, i, 2);
	}
	for (int i = 0; i < 11; i++) // Column walls
	{
		board.set_board((57 + i), 6, 2);
	}
	for (int i = 0; i < 24; i++) // Column walls
	{
		board.set_board((51 + i), 0, 2);
	}
	for (int i = 0; i < 11; ++i) // Row walls
	{
		board.set_board(51, i, 2);
	}
	for (int i = 6; i < 62; ++i) // Row walls + Mage Town Bottom Row Walls
	{
		board.set_board(57, i, 2);
	}
	// Mage Town
	for (int i = 0; i < 37; i++) // Column Right walls + Path to Demon king Castle
	{
		board.set_board((20 + i), 61, 2);
	}
	for (int i = 0; i < 26; i++) // Column Left walls
	{
		board.set_board((26 + i), 11, 2);
	}
	for (int i = 11; i < 54; ++i) // Top Row walls
	{
		board.set_board(26, i, 2);
	}
	// Path to Bandit camp + Demon king Castle
	for (int i = 0; i < 7; i++) // Column Left walls to bandit
	{
		board.set_board((19 + i), 53, 2);
	}
	for (int i = 19; i < 53; ++i) // Bottom Row walls to bandit
	{
		board.set_board(19, i, 2);
	}
	for (int i = 0; i < 4; i++) // Column Right walls to demon
	{
		board.set_board((12 + i), 66, 2);
	}
	for (int i = 66; i < 85; ++i) // Top Row walls to demon
	{
		board.set_board(12, i, 2);
	}
	for (int i = 61; i < 75; ++i) // Bottom Row walls to demon
	{
		board.set_board(19, i, 2);
	}
	//Bandit camp Leader room/ Treasure room?
	for (int i = 0; i < 9; i++) // Column
	{
		board.set_board((2 + i), 95, 2);
	}
	for (int i = 49; i < 95; ++i) // Row
	{
		board.set_board(2, i, 2);
	}
	for (int i = 50; i < 95; ++i) // Rows
	{
		board.set_board(10, i, 2);
	}
}

Game::~Game()
{
}

void Game::start()
{
	system("cls");
	// Inform user to check that console is full screen for the map to not be distorted
	Common::input("Welcome\n\nEnsure that the console window is full screen\nPress enter to continue ");

	while (true) {
		system("cls");

		/*
		// Used for better performance and reduced flickering (only if got extra time)(need a lot more work)
		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(h, coord);
		*/

		board.print_board();
		std::cout << "Current pos : (" << player.get_pos(1) << ", " << player.get_pos(0) << ")\n";

		std::string action_inp = Common::input("Enter action (WASD for movement and IJKL for interaction, M for menu) : ");

		short tmp_target_cell_val = -1;

		// Loop till action input is valid (WASDIJKL)(non-case sensitive)
		while (!valid_inp(action_inp)) {
			system("cls");
			board.print_board();
			std::cout << "Current pos : (" << player.get_pos(1) << ", " << player.get_pos(0) << ")\n";
			action_inp = Common::input("Invalid action\nEnter action (WASD for movement and IJKL for interaction, M for menu) : ");
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

			tmp_target_cell_val = board.get_board(player.get_pos(0) - 1, player.get_pos(1));

		}
		else if ((action_inp == "j" || action_inp == "J") && player.get_pos(1) > 0) {

			tmp_target_cell_val = board.get_board(player.get_pos(0), player.get_pos(1) - 1);

		}
		else if ((action_inp == "k" || action_inp == "K") && player.get_pos(0) < 100) {

			tmp_target_cell_val = board.get_board(player.get_pos(0) + 1, player.get_pos(1));

		}
		else if ((action_inp == "l" || action_inp == "L") && player.get_pos(1) < 100) {
			
			tmp_target_cell_val = board.get_board(player.get_pos(0), player.get_pos(1) + 1);

		}
		else if ((action_inp == "m" || action_inp == "M")) {
			system("cls");
			std::string menu_option = Common::input("===== Menu =====\n1) Character\n2) Backpack\n3) Map\n\nS) Story testing\n\nEnter an option (B for back) : ");
			while (menu_option != "1" && menu_option != "2" && menu_option != "3" && menu_option != "B" && menu_option != "b" && menu_option != "S") {
				system("cls");
				menu_option = Common::input("===== Menu =====\n1) Character\n2) Backpack\n3) Map\n\nS) Story testing\n\nInvalid Input\nEnter an option (B for back) : ");
			}
			
			if (menu_option == "1") {
				system("cls");
				Common::input("====== Character ======\n1) Attack   " + std::to_string(player.get_stats("attack")) + "\n2) Health   " + std::to_string(player.get_stats("cur_health")) + " / " + std::to_string(player.get_stats("max_health")) + "\n3) MP       " + std::to_string(player.get_stats("mp")) + "\n\nPress enter to return ");
			}
			else if (menu_option == "2") {
				system("cls");
				Common::input("====== Backpack ======\n1) Coin        " + std::to_string(player.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(player.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(player.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(player.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(player.get_item_qty("mp_potion")) + "\n\nPress enter to return ");
			}
			else if (menu_option == "3") {
				system("cls");
				board.print_map();
				Common::input("\nPress enter to return ");
			}
			else if (menu_option == "S") {
				story.prologue();

				story.foundCart();
				story.meetElora();
				story.winElora();
				story.loseElora();
				story.recruitElora();

				story.outsideOrionResidence();
				story.meetOrion();
				story.recruitOrion_main();
				story.meetBlaise_main();

				bool blaiseFateDecided = false, blaiseKilled = false;
				std::string blaiseInput = Common::input("What would you like to do?\n1. Kill BLAISE\n2. Recruit BLAISE\n\n");

				while (blaiseInput != "1" && blaiseInput != "2")
				{
					blaiseInput = Common::input("Invalid Input\nWhat would you like to do?\n1. Kill BLAISE\n2. Recruit BLAISE\n\n");
				}

				if (blaiseInput == "1") {
					story.killBlaise_main();
					blaiseKilled = true;
					blaiseFateDecided = true;
				}
				else {
					story.recruitBlaise_main();
					blaiseFateDecided = true;
				}

				story.beforeFightDK_main();
				story.defeatDK_main();
				if (blaiseKilled == false)
				{
					story.blaiseBetrayal_main();
					story.defeatBlaise_main();
				}
				story.ending_main();
			}
		}

		if (tmp_target_cell_val == 3) {
			switch (shops[0].open_shop(player.get_item_qty("coin"))) {
			case 'B':
			case 'b':
				break;
			case '1':
				player.set_stats("attack", player.get_stats("attack") + 5);
				player.set_item_qty("sword", player.get_item_qty("sword") + 1);
				player.set_item_qty("coin", player.get_item_qty("coin") - 10);
				break;
			case '2':
				player.set_stats("max_health", player.get_stats("max_health") + 10);
				player.set_item_qty("armour", player.get_item_qty("armour") + 1);
				player.set_item_qty("coin", player.get_item_qty("coin") - 20);
				break;
			case '3':
				player.set_item_qty("mp_potion", player.get_item_qty("mp_potion") + 1);
				player.set_item_qty("coin", player.get_item_qty("coin") - 5);
				break;
			case '4':
				player.set_item_qty("hp_potion", player.get_item_qty("hp_potion") + 1);
				player.set_item_qty("coin", player.get_item_qty("coin") - 5);
				break;
			}
		}

	}
}

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L" || inp == "m" || inp == "M");
}
