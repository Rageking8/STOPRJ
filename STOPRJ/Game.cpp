#include "Game.h"
#include "Common.h"
#include <string>
#include <random>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

Game::Game()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	std::ios_base::sync_with_stdio(false);

	board.set_board(97, 0, 1);
	swordsman.set_pos(97, 0);

	int tmp_cam_pos_i1 = 0;
	int tmp_cam_pos_i2 = 0;

	if (swordsman.get_pos(0) < 7) {
		tmp_cam_pos_i1 = 0;
	}
	else if (swordsman.get_pos(0) > 93) {
		tmp_cam_pos_i1 = 86;
	}
	else {
		tmp_cam_pos_i1 = swordsman.get_pos(0) - 7;
	}

	if (swordsman.get_pos(1) < 15) {
		tmp_cam_pos_i2 = 0;
	}
	else if (swordsman.get_pos(1) > 85) {
		tmp_cam_pos_i2 = 86;
	}
	else {
		tmp_cam_pos_i2 = swordsman.get_pos(1) - 15;
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
	// Bandit Camp inside walls
	for (int i = 0; i < 3; i++)
	{
		board.set_board((1 + i), 15, 6);
	}
	for (int i = 0; i < 9; i++)
	{
		board.set_board((6 + i), 15, 6);
	}
	for (int i = 1; i < 6; i++)
	{
		board.set_board(10, i, 6);
	}
	for (int i = 10; i < 15; i++)
	{
		board.set_board(10, i, 6);
	}
	//Campfire
	board.set_board(9, 36, 17);
	board.set_board(8, 36, 10);
	board.set_board(10, 36, 10);
	board.set_board(9, 35, 10);
	board.set_board(9, 37, 10);
	//Pond
	for (int i = 20; i < 30; i++)
	{
		board.set_board(1, i, 7);
	}
	for (int i = 21; i < 29; i++)
	{
		board.set_board(2, i, 7);
	}
	for (int i = 23; i < 27; i++)
	{
		board.set_board(3, i, 4);
	}
	//Beds in the dormitory
	//Bed 1
	board.set_board(2, 1, 18);
	board.set_board(2, 2, 10);
	board.set_board(2, 3, 10);
	//Bed 2
	board.set_board(7, 1, 18);
	board.set_board(7, 2, 10);
	board.set_board(7, 3, 10);
	//Bed 3
	board.set_board(9, 1, 18);
	board.set_board(9, 2, 10);
	board.set_board(9, 3, 10);
	//Bed 4
	board.set_board(2, 14, 18);
	board.set_board(2, 13, 10);
	board.set_board(2, 12, 10);
	//Bed 5
	board.set_board(7, 14, 18);
	board.set_board(7, 13, 10);
	board.set_board(7, 12, 10);
	//Bed 6
	board.set_board(9, 14, 18);
	board.set_board(9, 13, 10);
	board.set_board(9, 12, 10);
	// Training Targets
	board.set_board(12, 3, 15);
	board.set_board(14, 3, 15);
	// Bandits/Enemies
	// 1st encounter
	board.set_board(7, 31, 26);
	board.set_board(6, 30, 26);
	board.set_board(6, 32, 26);
	// 2nd encounter
	board.set_board(1, 41, 27);
	board.set_board(2, 40, 26);
	board.set_board(2, 42, 26);
	//Bandit camp Leader room/ Treasure room?
	for (int i = 0; i < 9; i++) // Column
	{
		board.set_board((2 + i), 95, 2);
	}
	for (int i = 49; i < 95; ++i) // Row
	{
		board.set_board(2, i, 2);
	}
	for (int i = 50; i < 95; ++i) // Row
	{
		board.set_board(10, i, 2);
	}
	//for (int i = 0; i < 3; i++) // Door(unlocks after player defeats the boss)
	//{
	//	board.set_board((5 + i), 49, 6);
	//}
	for (int i = 0; i < 2; i++) //  Door wall
	{
		board.set_board((3 + i), 49, 2);
	}
	for (int i = 0; i < 2; i++) // Door wall
	{
		board.set_board((8 + i), 49, 2);
	}
	for (int i = 0; i < 7; i++) // Cage Walls(unlocks after player solve the puzzle)
	{
		board.set_board((3 + i), 79, 6);
	}
	// Switches
	board.set_board(3, 59, 10);
	board.set_board(3, 73, 10);
	board.set_board(9, 59, 10);
	board.set_board(9, 73, 10);

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

	board.set_board(63, 11, 2);
	board.set_board(67, 11, 2);

	for (int i = 0; i < 12; i++) // Column walls
	{
		board.set_board((75 + i), 11, 2);
	}

	// Fountain border (Archer Town)
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

	// Fountain water (Archer Town)
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(81 + i, 34 + i2, 4);
	}
	board.set_board(82, 33, 4);
	board.set_board(82, 37, 4);

	board.set_board(94, 24, 5);

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
	// Stone Fences/ Barrier from player walking thru
	board.set_board(51, 50, 6);
	board.set_board(51, 32, 6);
	board.set_board(55, 55, 6);
	board.set_board(56, 55, 6);
	board.set_board(30, 55, 6);

	for (int i = 36; i < 40; i++) // Row
	{
		board.set_board(51, i, 6);
	}
	for (int i = 43; i < 47; i++)// Row
	{
		board.set_board(51, i, 6);
	}
	for (int i = 0; i < 5; i++) // Column
	{
		board.set_board((52 + i), 51, 6);
		board.set_board((52 + i), 31, 6);
	}
	for (int i = 0; i < 4; i++) // Column
	{
		board.set_board((34 + i), 55, 6);
		board.set_board((41 + i), 55, 6);
		board.set_board((48 + i), 55, 6);
	}
	// Fountain border (Mage Town)
	for (int i = 0; i < 3; ++i) {
		board.set_board(30, (40 + i), 2);
		board.set_board(34, (40 + i), 2);
	}
	for (int i = 0; i < 2; ++i) {
		board.set_board(31 + (i * 2), 39, 2);
		board.set_board(31 + (i * 2), 43, 2);
	}
	board.set_board(32, 38, 2);
	board.set_board(32, 44, 2);

	// Fountain water (Mage Town)
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(31 + i, 40 + i2, 4);
	}
	board.set_board(32, 39, 4);
	board.set_board(32, 43, 4);
	//Mage Academy/School Walls
	for (int i = 12; i < 28; ++i) // Row 
	{
		board.set_board(51, i, 6);
	}
	for (int i = 12; i < 27; ++i) // Row 
	{
		board.set_board(29, i, 10);
	}
	for (int i = 12; i < 18; ++i) // Row 
	{
		board.set_board(43, i, 6);
	}
	for (int i = 21; i < 27; ++i) // Row 
	{
		board.set_board(43, i, 6);
	}
	for (int i = 12; i < 18; ++i) // Row 
	{
		board.set_board(35, i, 10);
	}
	for (int i = 21; i < 27; ++i) // Row 
	{
		board.set_board(35, i, 10);
	}
	for (int i = 0; i < 7; i++) // Column  walls
	{
		board.set_board((36 + i), 17, 10);
		board.set_board((36 + i), 21, 10);
	}
	for (int i = 0; i < 16; i++) // Column  walls
	{
		board.set_board((35 + i), 27, 6);
	}
	for (int i = 0; i < 3; i++) // Column  walls
	{
		board.set_board((27 + i), 27, 6);
	}
	// Houses in Mage Town
	// House 2
	board.set_board(38, 55, 9);
	board.set_board(40, 55, 9);
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(37, i, 9);
		board.set_board(41, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
	{
		board.set_board((38 + i), 60, 9);
	}
	// House 3
	board.set_board(45, 55, 9);
	board.set_board(47, 55, 9);
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(44, i, 9);
		board.set_board(48, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
	{
		board.set_board((45 + i), 60, 9);
	}
	// House 4
	board.set_board(52, 55, 9);
	board.set_board(54, 55, 9);
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(51, i, 9);
		board.set_board(55, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
	{
		board.set_board((52 + i), 60, 9);
	}
	// House 5
	board.set_board(51, 49, 9);
	board.set_board(51, 47, 9);
	for (int i = 46; i < 51; ++i) // Row 
	{
		board.set_board(56, i, 9);
	}
	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 46, 9);
		board.set_board((52 + i), 50, 9);
	}
	// House 6
	board.set_board(51, 42, 9);
	board.set_board(51, 40, 9);
	for (int i = 39; i < 44; ++i) // Row 
	{
		board.set_board(56, i, 9);
	}
	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 39, 9);
		board.set_board((52 + i), 43, 9);
	}
	// House 7
	board.set_board(51, 35, 9);
	board.set_board(51, 33, 9);
	for (int i = 32; i < 37; ++i) // Row 
	{
		board.set_board(56, i, 9);
	}
	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 32, 9);
		board.set_board((52 + i), 36, 9);
	}

	// NPCs
	// Open-Area
	board.set_board(39, 59, 22); // inside house 2 #1
	board.set_board(53, 59, 22); // inside house 4 #2
	board.set_board(55, 34, 22); // inside house 7 #3
	board.set_board(52, 24, 22); // First Mage NPC to greet at the start #4
	board.set_board(43, 42, 22); // Second Mage NPC Saying random stuff #5
	board.set_board(34, 39, 22); // Third Mage NPC Saying a wish at the fountain #6
	//Grand Master Mage(GMM)
	board.set_board(32, 12, 24); // Grand Master Mage Named "Pendolf" #7
	// Training Area
	board.set_board(45, 23, 22); // #8
	board.set_board(47, 23, 22); // #9
	board.set_board(49, 23, 22); // #10

	//Target Block/Dummies
	board.set_board(45, 14, 13);
	board.set_board(47, 14, 13);
	board.set_board(49, 14, 13);

	// Mage Town Shophouse
	board.set_board(31, 55, 17);
	board.set_board(33, 55, 17);
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(30, i, 17);
		board.set_board(34, i, 17);
	}
	for (int i = 0; i < 3; i++) // Column  walls
	{
		board.set_board((31 + i), 60, 17);
	}
	//Shop Icon
	board.set_board(32, 59, 3);
	//Grass
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(35, i, 8);
		board.set_board(36, i, 8);
		board.set_board(42, i, 8);
		board.set_board(43, i, 8);
		board.set_board(49, i, 8);
		board.set_board(50, i, 8);
		board.set_board(56, i, 8);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board((52 + i), 37, 8);
		board.set_board((52 + i), 38, 8);
		board.set_board((52 + i), 44, 8);
		board.set_board((52 + i), 45, 8);
	}

	// Path to Bandit camp + Demon king Castle
	board.set_board(16, 57, 25); // Directory sign
	for (int i = 0; i < 7; i++) // Column Left walls to bandit
	{
		if (i == 3 || i == 4) continue;
		board.set_board((19 + i), 53, 2);
	}

	for (int i = 16; i < 51; ++i) { // Column right against the left world boundary
		board.set_board(i, 0, 2);
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


	// Note: do not overide
	for (int i = 95; i < 100; ++i) {
		board.set_board(i, 47, 6);
	}

	//start_battle("ambush");
	//while (true);
}

Game::~Game()
{
}

void Game::start()
{
	system("cls");
	// Inform user to check that console is full screen for the map to not be distorted
	Common::input("Welcome\n\nEnsure that the console window is full screen\nPress enter to continue ");

	story.prologue();

	bool prev_is_map = false;

	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true) {

		// Dont use system("cls") as it causes flicker when the screen is updating
		SetConsoleCursorPosition(h, COORD{ 0, 0 });
		board.print_board(prev_is_map);

		SetConsoleCursorPosition(h, COORD{ 0, 31 });
		std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \n";

		SetConsoleCursorPosition(h, COORD{ 72, 33 });
		std::cout << " ";

		SetConsoleCursorPosition(h, COORD{ 0, 32 });
		std::string action_inp = Common::input("              \nEnter action (WASD for movement and IJKL for interaction, M for menu) : ");

		short tmp_target_cell_val = -1;

		prev_is_map = true;

		// Loop till action input is valid (WASDIJKL)(non-case sensitive)
		while (!valid_inp(action_inp)) {

			SetConsoleCursorPosition(h, COORD{ 72, 33 });
			Common::mul_txt(" ", action_inp.length(), true);

			SetConsoleCursorPosition(h, COORD{ 0, 31 });
			std::cout << "Current pos : (" << swordsman.get_pos(1) << ", " << swordsman.get_pos(0) << ") | Range of x and y coord : 0-100 (both inclusive)    \n";
			action_inp = Common::input("Invalid action\nEnter action (WASD for movement and IJKL for interaction, M for menu) : ");
		}

		// For player movement (WASD)
		if ((action_inp == "w" || action_inp == "W") && swordsman.get_pos(0) > 0 && board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1)) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('W');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) < 93)
				board.move_cam('W');
		}
		else if ((action_inp == "a" || action_inp == "A") && swordsman.get_pos(1) > 0 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('A');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) < 85)
				board.move_cam('A');
		}
		else if ((action_inp == "s" || action_inp == "S") && swordsman.get_pos(0) < 100 && board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1)) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('S');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(0) > 7)
				board.move_cam('S');
		}
		else if ((action_inp == "d" || action_inp == "D") && swordsman.get_pos(1) < 100 && board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1) == 0) {
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 0);
			swordsman.move('D');
			board.set_board(swordsman.get_pos(0), swordsman.get_pos(1), 1);

			if (swordsman.get_pos(1) > 15)
				board.move_cam('D');
		}

		// For player interaction with landmarks (IJKL)
		else if ((action_inp == "i" || action_inp == "I") && swordsman.get_pos(0) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) - 1, swordsman.get_pos(1));

		}
		else if ((action_inp == "j" || action_inp == "J") && swordsman.get_pos(1) > 0) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) - 1);

		}
		else if ((action_inp == "k" || action_inp == "K") && swordsman.get_pos(0) < 100) {

			tmp_target_cell_val = board.get_board(swordsman.get_pos(0) + 1, swordsman.get_pos(1));

		}
		else if ((action_inp == "l" || action_inp == "L") && swordsman.get_pos(1) < 100) {
			
			tmp_target_cell_val = board.get_board(swordsman.get_pos(0), swordsman.get_pos(1) + 1);

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
				Common::input("====== Character ======\n1) Attack   " + std::to_string(swordsman.get_stats("attack")) + "\n2) Health   " + std::to_string(swordsman.get_stats("cur_health")) + " / " + std::to_string(swordsman.get_stats("max_health")) + "\n3) MP       " + std::to_string(swordsman.get_stats("cur_mp")) + " / " + std::to_string(swordsman.get_stats("max_mp")) + "\n\nPress enter to return ");
			}
			else if (menu_option == "2") {
				system("cls");
				Common::input("====== Backpack ======\n1) Coin        " + std::to_string(swordsman.get_item_qty("coin")) + "\n2) Sword       " + std::to_string(swordsman.get_item_qty("sword")) + "\n3) Armour      " + std::to_string(swordsman.get_item_qty("armour")) + "\n4) HP Potion   " + std::to_string(swordsman.get_item_qty("hp_potion")) + "\n5) MP Potion   " + std::to_string(swordsman.get_item_qty("mp_potion")) + "\n\nPress enter to return ");
			}
			else if (menu_option == "3") {
				system("cls");
				board.print_map();
				Common::input("\n# -> Colored blocks\nP -> Player\nS -> Shop\n? -> Special landmarks\n. -> All other landmarks (including empty space)\n\nPress enter to return ");
				system("cls");
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

			prev_is_map = false;
		}

		// Ambush by the archer troops
		if (swordsman.get_pos(1) == 47) {
			switch (swordsman.get_pos(0)) {
				case 95:
				case 96:
				case 97:
				case 98:
				case 99:
					board.set_board(96, 46, 21);
					board.set_board(97, 45, 21);
					board.set_board(98, 46, 21);

					board.set_board(95, 49, 21);
					board.set_board(94, 50, 21);
					board.set_board(95, 51, 21);

					break;
			}
		}

		if (tmp_target_cell_val == 3) {
			switch (shops[0].open_shop(swordsman.get_item_qty("coin"))) {
			case 'B':
			case 'b':
				break;
			case '1':
				swordsman.set_stats("attack", swordsman.get_stats("attack") + 5);
				swordsman.set_item_qty("sword", swordsman.get_item_qty("sword") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 10);
				break;
			case '2':
				swordsman.set_stats("max_health", swordsman.get_stats("max_health") + 10);
				swordsman.set_item_qty("armour", swordsman.get_item_qty("armour") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 20);
				break;
			case '3':
				swordsman.set_item_qty("mp_potion", swordsman.get_item_qty("mp_potion") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 5);
				break;
			case '4':
				swordsman.set_item_qty("hp_potion", swordsman.get_item_qty("hp_potion") + 1);
				swordsman.set_item_qty("coin", swordsman.get_item_qty("coin") - 5);
				break;
			}

			prev_is_map = false;
		}
		else if (tmp_target_cell_val == 5) {
			story.foundCart();
			for (int i = 95; i < 100; ++i) {
				board.set_board(i, 47, 0);
			}

			prev_is_map = false;
		}

	}
}

bool Game::valid_inp(std::string inp)
{
	return (inp == "w" || inp == "a" || inp == "s" || inp == "d" || inp == "W" || inp == "A" || inp == "S" || inp == "D" || inp == "i" || inp == "j" || inp == "k" || inp == "l" || inp == "I" || inp == "J" || inp == "K" || inp == "L" || inp == "m" || inp == "M");
}

void Game::start_battle(std::string id)
{
	system("cls");
	Character enemy[4];

	if (id == "ambush") {
		for (int i = 0; i < 2; ++i) {
			enemy[i].set_name("Archer Troop");
			enemy[i].set_stats("cur_health", 10);
			enemy[i].set_stats("max_health", 10);
			enemy[i].set_stats("cur_mp", 20);
			enemy[i].set_stats("max_mp", 20);
			enemy[i].init_skill("shoot_arrow", "raining_arrow", "piercing_arrow", "bullet_arrow");
		}
	}

	bool slot_active[8]{};

	for (int i = 0; i < 4; ++i) {
		if (enemy[i].get_name() != "") {
			slot_active[i] = true;
		}
	}
	slot_active[4] = (swordsman.get_stats("cur_health") > 0);
	slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
	slot_active[6] = (archer.get_recruited() && (archer.get_stats("cur_health") > 0));
	slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

	for (int i = 0; i < 4; ++i) {
		std::cout << (slot_active[i] ? "|======================| " : "                         ");
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::string tmp_name = enemy[i].get_name();
			std::cout << "| " << tmp_name << Common::mul_txt(" ", 21 - tmp_name.length()) << "| ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::string tmp_attack = std::to_string(enemy[i].get_stats("attack"));
			std::cout << "| Attack : " << tmp_attack << Common::mul_txt(" ", 12 - tmp_attack.length()) << "| ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::string tmp_cur_health = std::to_string(enemy[i].get_stats("cur_health"));
			std::string tmp_max_health = std::to_string(enemy[i].get_stats("max_health"));
			std::cout << "| Health : " << tmp_cur_health << " / " << tmp_max_health << Common::mul_txt(" ", 12 - (tmp_cur_health.length() + 3 + tmp_max_health.length())) << "| ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::string tmp_cur_mp = std::to_string(enemy[i].get_stats("cur_mp"));
			std::string tmp_max_mp = std::to_string(enemy[i].get_stats("max_mp"));
			std::cout << "| MP : " << tmp_cur_mp << " / " << tmp_max_mp << Common::mul_txt(" ", 16 - (tmp_cur_mp.length() + 3 + tmp_max_mp.length())) << "| ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::cout << "|                      | ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n";

	for (int i = 0; i < 4; ++i) {
		for (int i2 = 0; i2 < 4; ++i2) {
			if (slot_active[i2] && enemy[i2].get_skill_list(i).active) {
				std::string tmp_skill_name = enemy[i2].get_skill_list(i).name;
				std::cout << "| > " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
			}
			else if (slot_active[i2]) {
				std::cout << "|                      | ";
			}
			else {
				std::cout << "                         ";
			}
		}
		std::cout << "\n";
	}

	for (int i = 0; i < 4; ++i) {
		if (slot_active[i]) {
			std::cout << "|======================| ";
		}
		else {
			std::cout << "                         ";
		}
	}

	std::cout << "\n\n\n\n\n";

	if (slot_active[4])
		std::cout << "|======================| ";
	else
		std::cout << "                         ";

	if (slot_active[5])
		std::cout << "|======================| ";
	else
		std::cout << "                         ";

	if (slot_active[6])
		std::cout << "|======================| ";
	else
		std::cout << "                         ";

	if (slot_active[7])
		std::cout << "|======================| ";
	else
		std::cout << "                         ";

	std::cout << "\n";

	if (slot_active[4]) {
		std::string tmp_name = swordsman.get_name();
		std::cout << "| " << tmp_name << Common::mul_txt(" ", 21 - tmp_name.length()) << "| ";
	}
	else {
		std::cout << "                         ";
	}

	if (slot_active[5]) {
		std::string tmp_name = mage.get_name();
		std::cout << "| " << tmp_name << Common::mul_txt(" ", 21 - tmp_name.length()) << "| ";
	}
	else {
		std::cout << "                         ";
	}

	if (slot_active[6]) {
		std::string tmp_name = archer.get_name();
		std::cout << "| " << tmp_name << Common::mul_txt(" ", 21 - tmp_name.length()) << "| ";
	}
	else {
		std::cout << "                         ";
	}

	if (slot_active[7]) {
		std::string tmp_name = assassin.get_name();
		std::cout << "| " << tmp_name << Common::mul_txt(" ", 21 - tmp_name.length()) << "| ";
	}
	else {
		std::cout << "                         ";
	}

	std::cout << "\n";
}
