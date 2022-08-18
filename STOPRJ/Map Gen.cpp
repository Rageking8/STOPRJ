#include "Game.h"

void Game::board_gen()
{

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
		board.set_board(36, i, 2);
	}
	for (int i = 85; i < 98; ++i) { // Row walls
		board.set_board(36, i, 2);
	}
	for (int i = 1; i < 16; ++i) { // Column walls
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
	// Demon king Castle Landmarks/Decorations
	// Gates/Door
	for (int i = 0; i < 9; i++) // add 1 to cover the gate
	{
		board.set_board(19, (75 + i), 6); // Gate 1 (Ask player if they are ready to enter the castle)
		board.set_board(38, (75 + i), 6); // Gate 2 (After 1st battle)
		board.set_board(61, (75 + i), 6); // Gate 3 (After 2nd battle)
		board.set_board(89, (75 + i), 6); // Gate 4 (After boss battle)
	}
	//Rooms "Carpet"
	for (int i = 0; i < 15; i++) // Room 1 (Skeleton Infantry Room) 
	{
		board.set_board((21 + i), 74, 10);
		board.set_board((21 + i), 85, 10);
	}
	for (int i = 0; i < 18; i++) // Room 2 (Mini-Boss/Demon Room)
	{
		board.set_board((41 + i), 71, 10);
		board.set_board((41 + i), 88, 10);
	}
	for (int i = 0; i < 23; i++) // Room 3 (Boss/Throne Room)
	{
		board.set_board((64 + i), 66, 10);
		board.set_board((64 + i), 93, 10);
	}
	//Gold Pile in Treasure room
	for (int i = 71; i < 89; i++)
	{
		board.set_board(99, i, 12);
	}
	for (int i = 73; i < 87; i++)
	{
		board.set_board(98, i, 12);
	}
	for (int i = 75; i < 85; i++)
	{
		board.set_board(97, i, 12);
	}
	for (int i = 0; i < 6; i++)
	{
		board.set_board((93 + i), 78, 12);
		board.set_board((93 + i), 81, 12);
	}
	board.set_board(96, 77, 12);
	board.set_board(96, 82, 12);
	board.set_board(94, 77, 12);
	board.set_board(93, 82, 12);
	board.set_board(95, 76, 12);
	board.set_board(95, 83, 12);
	// Chests
	board.set_board(96, 79, 31);
	board.set_board(96, 80, 31);

	// Boss/Throne Room 3
	// Dining area
	// Table
	for (int i = 0; i < 5; i++)
	{
		// #1
		board.set_board((64 + i), 62, 34); board.set_board((64 + i), 63, 34);
		// #2
		board.set_board((73 + i), 62, 34); board.set_board((73 + i), 63, 34);
		// #3
		board.set_board((82 + i), 62, 34); board.set_board((82 + i), 63, 34);
		// #4
		board.set_board((64 + i), 96, 34); board.set_board((64 + i), 97, 34);
		// #5
		board.set_board((73 + i), 96, 34); board.set_board((73 + i), 97, 34);
		// #6
		board.set_board((82 + i), 96, 34); board.set_board((82 + i), 97, 34);
	}
	//Fire
	for (int i = 0; i < 2; i++)
	{// Left Side
		board.set_board(70, (62 + i), 33);
		board.set_board(71, (62 + i), 33);
		board.set_board(79, (62 + i), 33);
		board.set_board(80, (62 + i), 33);
		//Right Side
		board.set_board(70, (96 + i), 33);
		board.set_board(71, (96 + i), 33);
		board.set_board(79, (96 + i), 33);
		board.set_board(80, (96 + i), 33);
	}
	//Chairs
	for (int i = 0; i < 5; i += 2)
	{// Left side
		//Facing Right
		board.set_board((64 + i), 61, 35);
		board.set_board((73 + i), 61, 35);
		board.set_board((82 + i), 61, 35);
		//Facing left
		board.set_board((64 + i), 64, 36);
		board.set_board((73 + i), 64, 36);
		board.set_board((82 + i), 64, 36);
		//Right side
		//Facing right
		board.set_board((64 + i), 95, 35);
		board.set_board((73 + i), 95, 35);
		board.set_board((82 + i), 95, 35);
		//facing left
		board.set_board((64 + i), 98, 36);
		board.set_board((73 + i), 98, 36);
		board.set_board((82 + i), 98, 36);
	}
	// Mini-Boss/ Bathroom Room 2
	//Water/Bathtub/Onsen
	for (int i = 0; i < 18; i++)
	{
		board.set_board((41 + i), 63, 4); board.set_board((41 + i), 64, 4); board.set_board((41 + i), 65, 4);//Left side
		board.set_board((41 + i), 66, 6); //Wall
		board.set_board((41 + i), 94, 4); board.set_board((41 + i), 95, 4); board.set_board((41 + i), 96, 4);//Right side
		board.set_board((41 + i), 93, 6); //Wall
	}
	// Stairs
	for (int i = 0; i < 2; i++)
	{
		board.set_board(44, (67 + i), 38); board.set_board(45, (67 + i), 38); board.set_board(54, (67 + i), 38); board.set_board(55, (67 + i), 38); // Left side
		board.set_board(44, (91 + i), 39); board.set_board(45, (91 + i), 39); board.set_board(54, (91 + i), 39); board.set_board(55, (91 + i), 39); // right side
	}
	// Skeleton Infantry/ Sleeping Quarters Room 2
	//Beds
	for (int i = 0; i < 15; i += 4)
	{
		board.set_board((21 + i), 63, 18); board.set_board((22 + i), 63, 18); // Left side
		board.set_board((21 + i), 96, 18); board.set_board((22 + i), 96, 18); // Right side
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 15; j += 4)
		{
			board.set_board((21 + j), (64 + i), 10); board.set_board((22 + j), (64 + i), 10); // Left side
			board.set_board((21 + j), (94 + i), 10); board.set_board((22 + j), (94 + i), 10); // Right side
		}
	}
	//Bedside table
	for (int i = 0; i < 13; i += 4)
	{
		board.set_board((23 + i), 63, 34);
		board.set_board((23 + i), 96, 34);
	}
	//Enemies 
	//Demon king
	board.set_board(86, 79, 23); // room 3
	//Demon enemy
	board.set_board(57, 79, 41); //room 2
	board.set_board(85, 78, 41); // room 3
	//Skeleton
	board.set_board(85, 80, 40); // room 3
	board.set_board(58, 78, 40); // room 2
	board.set_board(58, 80, 40); // room 2
	for (int i = 0; i < 3; i++)
	{
		board.set_board(35, (78 + i), 40); // room 1
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
	board.set_board(9, 36, 33);
	board.set_board(8, 36, 37);
	board.set_board(10, 36, 37);
	board.set_board(9, 35, 37);
	board.set_board(9, 37, 37);
	board.set_board(8, 35, 32);
	board.set_board(10, 37, 32);
	board.set_board(8, 37, 32);
	board.set_board(10, 35, 32);
	//Pond
	for (int i = 20; i < 30; i++)
	{
		board.set_board(1, i, 4);
	}
	for (int i = 21; i < 29; i++)
	{
		board.set_board(2, i, 4);
	}
	for (int i = 23; i < 27; i++)
	{
		board.set_board(3, i, 4);
	}
	// Table in dormitory
	for (int i = 0; i < 2; i++)
	{
		board.set_board(4, (1 + i), 34);
		board.set_board(5, (1 + i), 34);
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
	// Chest
	for (int i = 0; i < 3; i++)
	{
		board.set_board(5, (90 + i), 12);
		board.set_board(7, (90 + i), 12);
	}
	board.set_board(6, 91, 31);
	board.set_board(6, 92, 12);
	// Switches
	board.set_board(3, 59, 19);
	board.set_board(3, 73, 19);
	board.set_board(9, 59, 19);
	board.set_board(9, 73, 19);

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
	for (int i = 0; i < 12; i++) // Column walls
	{
		board.set_board((75 + i), 11, 2);
	}
	board.set_board(63, 11, 2);
	board.set_board(67, 11, 2);
	board.set_board(68, 11, 2);

	//Archer Leader House
	board.set_board(64, 41, 29); // Archer Leader
	for (int i = 34; i < 58; i++)
	{
		board.set_board(75, i, 28);
	}
	for (int i = 0; i < 8; i++)
	{
		board.set_board((64 + i), 34, 28); // Column House wall
		board.set_board((67 + i), 50, 17); // Bedroom wall
		board.set_board((64 + i), 39, 8); // Green Carpet 
		board.set_board((67 + i), 43, 8); // "
		board.set_board((64 + i), 31, 6); // Fence
	}
	for (int i = 35; i < 39; i++) // Green Carpet
	{
		board.set_board(71, i, 8);
	}
	board.set_board(71, 33, 6); // Fence
	board.set_board(71, 32, 6); // Fence
	// Flower Beds
	for (int i = 0; i < 7; i++)
	{
		board.set_board((64 + i), 33, 30);
		board.set_board((64 + i), 32, 30);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board(80, (12 + i), 30);
		board.set_board(81, (12 + i), 30);
		board.set_board(81, (53 + i), 30);
	}

	// Dining table
	for (int i = 0; i < 5; i++)
	{
		board.set_board((69 + i), 46, 34);
		board.set_board((69 + i), 47, 34);
	}
	// Chair
	board.set_board(69, 45, 35);
	board.set_board(69, 48, 36);
	board.set_board(71, 45, 35);
	board.set_board(71, 48, 36);
	board.set_board(73, 45, 35);
	board.set_board(73, 48, 36);
	// King Bed
	for (int i = 53; i < 56; i++)
	{
		board.set_board(74, i, 18);
		board.set_board(73, i, 10);
		board.set_board(72, i, 10);
	}
	//Shophouse
	for (int i = 15; i < 20; i++)
	{
		board.set_board(64, i, 17);
	}
	for (int i = 0; i < 4; i++)
	{
		board.set_board((65 + i), 15, 17);
		board.set_board((65 + i), 19, 17);
		board.set_board((79 + i), 17, 6); // Fence between house 1 & 2
	}
	board.set_board(69, 18, 17);
	board.set_board(69, 16, 17);
	board.set_board(65, 17, 3); // Shop Icon in Archer
	//Pond
	for (int i = 0; i < 3; i++)
	{
		board.set_board((64 + i), 22, 6);
	}
	for (int i = 23; i < 31; i++)
	{
		board.set_board(64, i, 4);
		board.set_board(65, i, 4);
		board.set_board(66, i, 6);
	}
	//Houses
	for (int i = 0; i < 5; i++)
	{
		board.set_board((82 + i), 12, 15); // house 1
		board.set_board((75 + i), 12, 15); // house 2
		board.set_board((76 + i), 57, 15); // house 3
	}
	for (int i = 0; i < 4; i++)
	{
		board.set_board(82, (13 + i), 15); board.set_board(86, (13 + i), 15); //house 1
		board.set_board(83, 17, 15); board.set_board(85, 17, 15);
		board.set_board(75, (13 + i), 15); board.set_board(79, (13 + i), 15); //house 2
		board.set_board(76, 17, 15); board.set_board(78, 17, 15);
		board.set_board(76, (53 + i), 15); board.set_board(80, (53 + i), 15); //house 3
		board.set_board(77, 52, 15); board.set_board(79, 52, 15);
	}



	// Fountain border (Archer Town)
	for (int i = 0; i < 3; ++i) {
		board.set_board(79, (34 + i), 2);
		board.set_board(83, (34 + i), 2);
	}
	for (int i = 0; i < 2; ++i) {
		board.set_board(80 + (i * 2), 33, 2);
		board.set_board(80 + (i * 2), 37, 2);
	}
	board.set_board(81, 32, 2);
	board.set_board(81, 38, 2);

	// Fountain water (Archer Town)
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(80 + i, 34 + i2, 4);
	}
	board.set_board(81, 33, 4);
	board.set_board(81, 37, 4);
	//NPCs in Archer Town
	board.set_board(83, 38, 21);
	board.set_board(77, 56, 21);
	board.set_board(70, 11, 21);

	board.set_board(94, 24, 5); // Cart Landmark

	//Path to Mage Town
	for (int i = 6; i < 12; ++i) // Row walls
	{
		board.set_board(69, i, 2);
	}
	for (int i = 0; i < 11; ++i) // Row walls
	{
		board.set_board(75, i, 2);
	}
	for (int i = 0; i < 13; i++) // Column walls
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
		board.set_board(35, i, 30);
		board.set_board(36, i, 30);
		board.set_board(42, i, 30);
		board.set_board(43, i, 30);
		board.set_board(49, i, 30);
		board.set_board(50, i, 30);
		board.set_board(56, i, 30);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board((52 + i), 37, 30);
		board.set_board((52 + i), 38, 30);
		board.set_board((52 + i), 44, 30);
		board.set_board((52 + i), 45, 30);
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
}