#include "Game.h"

void Game::board_gen()
{
	// Map generation
	// Boss Treasure room
	for (int i = 0; i < 12; ++i) { // Column walls
		board.set_board(i, 119, 62);
		board.set_board(i, 141, 62);
	}
	for (int i = 0; i < 23; ++i) { // Row walls
		board.set_board(0, (119 + i), 62);
		if (i >= 6 && i <= 17) continue;
		board.set_board(11, (119 + i), 62);
	}
	for (int i = 0; i < 5; ++i) { // Column walls
		board.set_board((11 + i), 125, 62); // Room 4
		board.set_board((11 + i), 136, 62); // Room 4
		board.set_board((39 + i), 125, 62); // Room 3
		board.set_board((39 + i), 136, 62); // Room 3
		board.set_board((62 + i), 125, 62); // Room 2
		board.set_board((62 + i), 136, 62); // Room 2
		board.set_board((82 + i), 125, 62); // Room 1
		board.set_board((82 + i), 136, 62); // Room 1
	}

	// Boss room 3 (Boss Fight/Throne room)
	for (int i = 0; i < 41; ++i) { // Row walls
		if (i >= 14 && i <= 25) continue;
		board.set_board(15, (111 + i), 62);
		board.set_board(39, (111 + i), 62);
	}
	for (int i = 0; i < 24; ++i) { // Column walls
		board.set_board((15 + i), 111, 62);
		board.set_board((15 + i), 150, 62);
	}
	// Boss room 2 (Mini-boss)
	for (int i = 0; i < 36; ++i) { // Row walls
		if (i >= 12 && i <= 23) continue;
		board.set_board(43, (113 + i), 62);
		board.set_board(62, (113 + i), 62);
		board.set_board(66, (113 + i), 62); // Room 1
		board.set_board(82, (113 + i), 62); // Room 1
	}
	for (int i = 0; i < 18; ++i) { // Column walls
		board.set_board((44 + i), 113, 62);
		board.set_board((44 + i), 148, 62);
	}
	// Boss room 1 (Skeleton Army)
	for (int i = 0; i < 15; ++i) { // Column walls
		board.set_board((67 + i), 113, 62);
		board.set_board((67 + i), 148, 62);
	}
	// Demon king Castle Landmarks/Decorations
	// Gates/Door
	for (int i = 0; i < 10; i++) 
	{
		//board.set_board(86, (126 + i), 6); // Gate 1 (Ask player if they are ready to enter the castle)
		//board.set_board(64, (126 + i), 6); // Gate 2 (After 1st battle)
		//board.set_board(42, (126 + i), 6); // Gate 3 (After 2nd battle)
		//board.set_board(13, (126 + i), 6); // Gate 4 (After boss battle)
	}
	// Rooms "Carpet"
	for (int i = 0; i < 11; i++) // Room 1 (Skeleton Infantry Room) 
	{
		board.set_board((69 + i), 125, -63);
		board.set_board((69 + i), 136, -63);
	}
	for (int i = 0; i < 14; i++) // Room 2 (Mini-Boss/Demon Room)
	{
		board.set_board((46 + i), 122, -63);
		board.set_board((46 + i), 139, -63);
	}
	for (int i = 0; i < 19; i++) // Room 3 (Boss/Throne Room)
	{
		board.set_board((18 + i), 120, -63);
		board.set_board((18 + i), 141, -63);
	}
	// Gold Pile in Treasure room
	for (int i = 0; i < 17; i++)
		board.set_board(1, (122 + i), 61);

	for (int i = 0; i < 15; i++)
		board.set_board(2, (123 + i), 61);

	for (int i = 0; i < 10; i++)
		board.set_board(3, (126 + i), 61);

	for (int i = 0; i < 6; i++)
	{
		board.set_board((4 + i), 129, 61);
		board.set_board((4 + i), 132, 61);
	}
	board.set_board(4, 128, 61);
	board.set_board(4, 133, 61);
	board.set_board(6, 127, 61);
	board.set_board(5, 134, 61);
	board.set_board(7, 128, 61);
	board.set_board(8, 133, 61);
	// Chests
	board.set_board(4, 130, 31);
	board.set_board(4, 131, 31);

	// Boss/Throne Room 3
	// Dining area
	// Table
	for (int i = 0; i < 5; i++)
	{
		// #1
		board.set_board((16 + i), 114, 34); board.set_board((16 + i), 115, 34);
		// #2
		board.set_board((25 + i), 114, 34); board.set_board((25 + i), 115, 34);
		// #3
		board.set_board((34 + i), 114, 34); board.set_board((34 + i), 115, 34);
		// #4
		board.set_board((16 + i), 146, 34); board.set_board((16 + i), 147, 34);
		// #5
		board.set_board((25 + i), 146, 34); board.set_board((25 + i), 147, 34);
		// #6
		board.set_board((34 + i), 146, 34); board.set_board((34 + i), 147, 34);
	}
	// Fire
	for (int i = 0; i < 2; i++)
	{	
		for (int j = 0; j < 2; j++)
		{
			// Left Side
			board.set_board((22 + j), (114 + i), 33);
			board.set_board((31 + j), (114 + i), 33);
			// Right Side
			board.set_board((22 + j), (146 + i), 33);
			board.set_board((31 + j), (146 + i), 33);
		}
		
	}
	// Chairs
	for (int i = 0; i < 5; i += 2)
	{// Left side
		// Facing Right
		board.set_board((16 + i), 113, -35);
		board.set_board((25 + i), 113, -35);
		board.set_board((34 + i), 113, -35);
		// Facing left
		board.set_board((16 + i), 116, -36);
		board.set_board((25 + i), 116, -36);
		board.set_board((34 + i), 116, -36);
		// Right side
		// Facing right
		board.set_board((16 + i), 145, -35);
		board.set_board((25 + i), 145, -35);
		board.set_board((34 + i), 145, -35);
		// Facing left
		board.set_board((16 + i), 148, -36);
		board.set_board((25 + i), 148, -36);
		board.set_board((34 + i), 148, -36);
	}
	// Mini-Boss/ Bathroom Room 2
	// Water/Bathtub/Onsen
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board.set_board((44 + i), (114 + j), 4); //Left side
			board.set_board((44 + i), (145 + j), 4); //Right side
		}
		board.set_board((44 + i), 117, 6); // Wall
		board.set_board((44 + i), 144, 6); // Wall
	}
	// Stairs
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			board.set_board((47 + j), (118 + i), -38); // Left side
			board.set_board((47 + j), (142 + i), -39); // right side
			board.set_board((57 + j), (118 + i), -38); // Left side
			board.set_board((57 + j), (142 + i), -39); // right side
		}
	}
	// Skeleton Infantry/ Sleeping Quarters Room 2
	//Beds
	for (int i = 0; i < 15; i += 4)
	{
		board.set_board((67 + i), 114, 18); board.set_board((68 + i), 114, 18); // Left side
		board.set_board((67 + i), 147, 18); board.set_board((68 + i), 147, 18); // Right side
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 15; j += 4)
		{
			board.set_board((67 + j), (115 + i), 10); board.set_board((68 + j), (115 + i), 10); // Left side
			board.set_board((67 + j), (145 + i), 10); board.set_board((68 + j), (145 + i), 10); // Right side
		}
	}
	//Bedside table
	for (int i = 0; i < 13; i += 4)
	{
		board.set_board((69 + i), 114, 34);
		board.set_board((69 + i), 147, 34);
	}
	//Enemies 
	//Demon king
	board.set_board(16, 130, 23); // room 3
	//Demon enemy
	board.set_board(44, 130, 41); //room 2
	board.set_board(17, 129, 41); // room 3
	//Skeleton
	board.set_board(17, 131, 40); // room 3
	board.set_board(45, 129, 40); // room 2
	board.set_board(45, 131, 40); // room 2
	for (int i = 0; i < 3; i++)
		board.set_board(67, (129 + i), 40); // room 1

	// Bandit camp
	for (int i = 0; i < 50; ++i) // Row walls
		board.set_board(0, i, 2);

	for (int i = 0; i < 15; i++) // Column walls
		board.set_board(i, 0, 2);

	for (int i = 0; i < 2; i++)
		board.set_board(i, 49, 2);

	for (int i = 0; i < 6; i++)
		board.set_board((10 + i), 49, 2);

	for (int i = 0; i < 20; ++i) // Bottom Row Left walls
		board.set_board(15, i, 2);

	for (int i = 30; i < 96; ++i) // Bottom Row Right walls
		board.set_board(15, i, 2);

	for (int i = 0; i < 4; i++) // Column Entrance left walls
		board.set_board((16 + i), 19, 2);

	// Bandit Camp inside walls
	for (int i = 0; i < 3; i++)
		board.set_board((1 + i), 15, 6);

	for (int i = 0; i < 9; i++)
		board.set_board((6 + i), 15, 6);

	for (int i = 1; i < 6; i++)
		board.set_board(10, i, 6);

	for (int i = 10; i < 15; i++)
		board.set_board(10, i, 6);

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
		board.set_board(1, i, 4);

	for (int i = 21; i < 29; i++)
		board.set_board(2, i, 4);

	for (int i = 23; i < 27; i++)
		board.set_board(3, i, 4);

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
	board.set_board(9, 31, 26);
	board.set_board(8, 30, 26);
	board.set_board(8, 32, 26);
	// 2nd encounter
	board.set_board(7, 31, 27);
	//Bandit camp Leader room/ Treasure room
	for (int i = 0; i < 9; i++) // Column
		board.set_board((2 + i), 95, 2);

	for (int i = 49; i < 95; ++i) // Row
		board.set_board(2, i, 2);

	for (int i = 50; i < 95; ++i) // Row
		board.set_board(10, i, 2);

	//for (int i = 0; i < 3; i++) // Door(unlocks after player defeats the boss)
	//{ 
	//	board.set_board((5 + i), 49, 6);
	//}
	for (int i = 0; i < 2; i++) //  Door wall
		board.set_board((3 + i), 49, 2);

	for (int i = 0; i < 2; i++) // Door wall
		board.set_board((8 + i), 49, 2);

	for (int i = 0; i < 7; i++) // Cage Walls (unlocks when combination is correct)
		board.set_board((3 + i), 79, 6);

	board.set_board(6, 81, 79);

	// Chest
	for (int i = 0; i < 3; i++)
	{
		board.set_board(5, (90 + i), 61);
		board.set_board(7, (90 + i), 61);
	}
	board.set_board(6, 91, 31);
	board.set_board(6, 92, 61);
	// Switches
	// Up-Left
	board.set_board(3, 59, 19);// Red
	// Up-Right
	board.set_board(3, 73, 20);// Blue
	// Down-Left
	board.set_board(9, 59, 20);// Blue
	//Down-Right
	board.set_board(9, 73, 19);// Red
	// Starting path to Kingdom of Elves
	for (int i = 0; i < 59; ++i) // Row walls
		board.set_board(100, i, 2);

	for (int i = 0; i < 24; ++i) // Row walls
		board.set_board(94, i, 2);

	for (int i = 25; i < 48; ++i) // Row walls
		board.set_board(94, i, 2);

	for (int i = 23; i < 26; ++i) // Row walls
		board.set_board(93, i, 2);

	for (int i = 0; i < 7; i++) // Column walls
		board.set_board((88 + i), 47, 2);

	for (int i = 0; i < 37; i++) // Column walls + Kingdom of Elves Column right walls
		board.set_board((63 + i), 58, 2);

	// Kingdom of Elves
	for (int i = 11; i < 48; ++i) // Row walls
		board.set_board(87, i, 2);

	for (int i = 11; i < 62; ++i) // Row walls
		board.set_board(63, i, 2);

	for (int i = 0; i < 12; i++) // Column walls
		board.set_board((75 + i), 11, 2);

	board.set_board(63, 11, 2);
	board.set_board(67, 11, 2);
	board.set_board(68, 11, 2);

	// Elf Leader House
	board.set_board(64, 41, 29); // Elf Leader
	for (int i = 34; i < 58; i++)
		board.set_board(75, i, 28);

	for (int i = 0; i < 8; i++)
	{
		board.set_board((64 + i), 34, 28); // Column House wall
		board.set_board((67 + i), 50, 17); // Bedroom wall
		board.set_board((64 + i), 39, -66); // Green Carpet 
		board.set_board((67 + i), 43, -66); // "
		board.set_board((64 + i), 31, 6); // Fence
	}
	for (int i = 35; i < 39; i++) // Green Carpet
		board.set_board(71, i, -67);

	board.set_board(71, 33, 6); // Fence
	board.set_board(71, 32, 6); // Fence
	// Flower Beds
	for (int i = 0; i < 7; i++)
	{
		board.set_board((64 + i), 33, -30);
		board.set_board((64 + i), 32, -30);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board(80, (12 + i), -30);
		board.set_board(81, (12 + i), -30);
		board.set_board(81, (53 + i), -30);
	}

	// Dining table
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			board.set_board((69 + i), (46 + j), 34);
			board.set_board((65 + i), (36 + j), 34);
		}
	}
	// Chair
	for (int i = 0; i < 6; i+=2)
	{
		board.set_board((69 + i), 45, -35);
		board.set_board((69 + i), 48, -36);
	}
	// King Bed
	for (int i = 53; i < 56; i++)
	{
		board.set_board(74, i, 18);
		board.set_board(73, i, 10);
		board.set_board(72, i, 10);
	}
	// Shophouse
	for (int i = 15; i < 20; i++)
		board.set_board(64, i, 17);

	for (int i = 0; i < 4; i++)
	{
		board.set_board((65 + i), 15, 17);
		board.set_board((65 + i), 19, 17);
		board.set_board((79 + i), 17, 6); // Fence between house 1 & 2
	}
	board.set_board(69, 18, 17);
	board.set_board(69, 17, -85);
	board.set_board(69, 16, 17);
	board.set_board(65, 17, 3); // Shop Icon in Kingdom of Elves
	// Pond
	for (int i = 0; i < 3; i++)
		board.set_board((64 + i), 22, 6);

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
		board.set_board(83, 17, 15); board.set_board(85, 17, 15); board.set_board(84, 17, -84); // Door
		board.set_board(75, (13 + i), 15); board.set_board(79, (13 + i), 15); //house 2
		board.set_board(76, 17, 15); board.set_board(78, 17, 15); board.set_board(77, 17, -84); // Door
		board.set_board(76, (53 + i), 15); board.set_board(80, (53 + i), 15); //house 3
		board.set_board(77, 52, 15); board.set_board(79, 52, 15); board.set_board(78, 52, -84); // Door
	}

	// Fountain border (Kingdom of Elves)
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

	// Fountain water (Kingdom of Elves)
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(81 + i, 34 + i2, 4);
	}
	board.set_board(82, 33, 4);
	board.set_board(82, 37, 4);
	// NPCs in Kingdom of Elves
	board.set_board(84, 38, 21);//fountain
	board.set_board(77, 56, 45);//house
	board.set_board(70, 11, 46);//exit/path to mage

	board.set_board(94, 24, 5); // Cart Landmark

	// Path to Mage Town
	for (int i = 6; i < 12; ++i) // Row walls
		board.set_board(69, i, 2);

	for (int i = 0; i < 11; ++i) // Row walls
		board.set_board(75, i, 2);

	for (int i = 0; i < 13; i++) // Column walls
		board.set_board((57 + i), 6, 2);

	for (int i = 0; i < 24; i++) // Column walls
		board.set_board((51 + i), 0, 2);

	for (int i = 0; i < 11; ++i) // Row walls
		board.set_board(51, i, 2);

	for (int i = 6; i < 62; ++i) // Row walls + Mage Town Bottom Row Walls
		board.set_board(57, i, 2);

	// Bandits between Kingdom of Elves and Mage
	for (int i = 0; i < 5; i++)
	{
		board.set_board(64, (1 + i), 26);
	}

	// Mage Town
	for (int i = 0; i < 43; i++) // Column Right walls + Path to Dungeon
		board.set_board((20 + i), 61, 2);

	for (int i = 0; i < 26; i++) // Column Left walls
		board.set_board((26 + i), 11, 2);

	for (int i = 11; i < 54; ++i) // Top Row walls
		board.set_board(26, i, 2);

	// Stone Fences/ Barrier from player walking thru
	board.set_board(51, 50, 6);
	board.set_board(51, 32, 6);
	board.set_board(55, 55, 6);
	board.set_board(56, 55, 6);
	board.set_board(30, 55, 6);

	for (int i = 36; i < 40; i++) // Row
		board.set_board(51, i, 6);

	for (int i = 43; i < 47; i++) // Row
		board.set_board(51, i, 6);

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
	// Mage Academy/School Walls
	for (int i = 12; i < 28; ++i) // Row 
		board.set_board(51, i, 6);

	for (int i = 12; i < 27; ++i) // Row carpet
		board.set_board(29, i, -64);

	for (int i = 12; i < 18; ++i) // Row 
		board.set_board(43, i, 6);

	for (int i = 21; i < 27; ++i) // Row 
		board.set_board(43, i, 6);

	for (int i = 12; i < 18; ++i) // Row carpet
		board.set_board(35, i, -64);

	for (int i = 21; i < 27; ++i) // Row carpet
		board.set_board(35, i, -64);

	for (int i = 0; i < 7; i++) // Column  carpet
	{
		board.set_board((36 + i), 17, -63);
		board.set_board((36 + i), 21, -63);
	}

	for (int i = 0; i < 16; i++) // Column  walls
		board.set_board((35 + i), 27, 6);

	for (int i = 0; i < 3; i++) // Column  walls
		board.set_board((27 + i), 27, 6);

	// Houses in Mage Town
	// House 2
	board.set_board(38, 55, 9);
	board.set_board(40, 55, 9);
	board.set_board(39, 55, -84); // Door
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(37, i, 9);
		board.set_board(41, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
		board.set_board((38 + i), 60, 9);

	// House 3 (Orion)
	board.set_board(46, 59, 78); // Orion Mage
	board.set_board(45, 55, 9);
	board.set_board(47, 55, 9);
	board.set_board(46, 55, -84); // Door
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(44, i, 9);
		board.set_board(48, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
		board.set_board((45 + i), 60, 9);

	// House 4
	board.set_board(52, 55, 9);
	board.set_board(54, 55, 9);
	board.set_board(53, 55, -84); // Door
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(51, i, 9);
		board.set_board(55, i, 9);
	}
	for (int i = 0; i < 3; i++) // Column  walls
		board.set_board((52 + i), 60, 9);

	// House 5
	board.set_board(51, 49, 9);
	board.set_board(51, 47, 9);
	board.set_board(51, 48, -85); // Door
	for (int i = 46; i < 51; ++i) // Row 
		board.set_board(56, i, 9);

	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 46, 9);
		board.set_board((52 + i), 50, 9);
	}
	// House 6
	board.set_board(51, 42, 9);
	board.set_board(51, 40, 9);
	board.set_board(51, 41, -85); // Door
	for (int i = 39; i < 44; ++i) // Row 
		board.set_board(56, i, 9);

	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 39, 9);
		board.set_board((52 + i), 43, 9);
	}
	// House 7
	board.set_board(51, 35, 9);
	board.set_board(51, 33, 9);
	board.set_board(51, 34, -85); // Door
	for (int i = 32; i < 37; ++i) // Row 
		board.set_board(56, i, 9);

	for (int i = 0; i < 4; i++) // Column  walls
	{
		board.set_board((52 + i), 32, 9);
		board.set_board((52 + i), 36, 9);
	}

	// NPCs
	// Open-Area
	board.set_board(39, 59, 47); // inside house 1 #1
	board.set_board(53, 59, 48); // inside house 3 #2
	board.set_board(55, 34, 49); // inside house 6 #3
	board.set_board(52, 24, 50); // First Mage NPC to greet at the start #4
	board.set_board(43, 42, 51); // Second Mage NPC Saying random stuff #5
	board.set_board(34, 39, 52); // Third Mage NPC Saying a wish at the fountain #6
	// Grand Master Mage(GMM)
	board.set_board(32, 12, 24); // Grand Master Mage Named "Pendolf" #7
	// Training Area
	board.set_board(45, 23, 22); // #8
	board.set_board(47, 23, 22); // #9
	board.set_board(49, 23, 22); // #10

	// Target Block/Dummies
	board.set_board(45, 14, 13);
	board.set_board(47, 14, 13);
	board.set_board(49, 14, 13);

	// Mage Town Shophouse
	board.set_board(31, 55, 17);
	board.set_board(32, 55, -84);
	board.set_board(33, 55, 17);
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(30, i, 17);
		board.set_board(34, i, 17);
	}
	for (int i = 0; i < 3; i++) // Column walls
		board.set_board((31 + i), 60, 17);

	// Shop Icon
	board.set_board(32, 59, 3);
	// Grass + flower
	for (int i = 56; i < 61; ++i) // Row 
	{
		board.set_board(35, i, -30);
		board.set_board(36, i, -30);
		board.set_board(42, i, -30);
		board.set_board(43, i, -30);
		board.set_board(49, i, -30);
		board.set_board(50, i, -30);
		board.set_board(56, i, -30);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board((52 + i), 37, -30);
		board.set_board((52 + i), 38, -30);
		board.set_board((52 + i), 44, -30);
		board.set_board((52 + i), 45, -30);
	}

	// Path to Bandit camp + Dungeon
	board.set_board(16, 57, -25); // Directory sign
	for (int i = 0; i < 7; i++) // Column Left walls to bandit
	{
		if (i == 3 || i == 4) continue;
		board.set_board((19 + i), 53, 2);
	}

	for (int i = 16; i < 51; ++i) // Column right against the left world boundary
		board.set_board(i, 0, 2);

	for (int i = 19; i < 53; ++i) // Bottom Row walls to bandit
		board.set_board(19, i, 2);
	for (int i = 61; i < 88; ++i) // Bottom Row walls to dungeon
		board.set_board(19, i, 2);
	for (int i = 0; i < 3; i++) // Left path to dungeon
		board.set_board((20 + i), 87, 2);
	for (int i = 0; i < 7; i++) // right path to dungeon
		board.set_board((16 + i), 95, 2);
	// Dungeon rooms
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			board.set_board((31 + j), (75 + i), 33); // campfire room 1
			board.set_board((75 + j), (73 + i), 33); // campfire room 3
			board.set_board((75 + j), (84 + i), 33); // campfire room 3
			board.set_board((28 + j), (78 + i), 34); // table
		}
	}
	// Chair around fire
	for (int i = 0; i < 2; i++)
	{
		board.set_board((31 + i), 78, -36);
		board.set_board((31 + i), 73, -35);

	}

	// SKeletons
	for (int i = 0; i < 3; i++)
		board.set_board(34, (82 + i), 40);

	// Excalibur stone
	for (int i = 0; i < 5; i++)
	{
		board.set_board(74, (77 + i), 6);
		if (i == 2) continue;
		board.set_board(73, (77 + i), 6);
	}
	for (int i = 0; i < 2; i++)
	{
		board.set_board((71 + i), 78, 6);
		board.set_board((71 + i), 80, 6);
	}
	board.set_board(73, 79, 68); // Sword
	board.set_board(70, 79, 69); // Guardian

	// Maze in room 2
	for (int i = 0; i < 24; i++)
	{
		board.set_board(46, (64 + i), 71);
		board.set_board(59, (64 + i), 71);
		if (i >= 4 && i <= 6) continue;
			board.set_board(48, (64 + i), 71);
			board.set_board(57, (64 + i), 71);
		if (i <= 8) continue;
			board.set_board(50, (64 + i), 71);
		if (i >= 16 && i <= 18) continue;
			board.set_board(53, (64 + i), 71);
	}
	for (int i = 0; i < 24; i++)
	{
		if (i == 18) continue;
		board.set_board(53, (64 + i), 71);
	}
	for (int i = 0; i < 5; i++)
	{
		board.set_board((47 + i), 69, 71);
		board.set_board((49 + i), 67, 71);
		board.set_board((50 + i), 64, 71);
		board.set_board((56 + i), 64, 71);
		if (i == 0) continue;
		board.set_board((49 + i), 71, 71);
		board.set_board((53 + i), 67, 71);
		if (i == 1) continue;
		board.set_board((53 + i), 83, 71);
		board.set_board((51 + i), 77, 71);
		board.set_board((53 + i), 71, 71);
	}
	// Walk-thru Walls
	board.set_board(55, 64, -65);
	board.set_board(45, 87, -65);
	board.set_board(47, 87, -65);
	board.set_board(58, 87, -65);
	board.set_board(60, 87, -65);

	board.set_board(56, 66, 70); //Key

	// Forest
	// Redwood Tree
	board.set_board(23, 51, 44); // #1
	for (int i = 0; i < 3; i++)
		board.set_board(24, (50 + i), 44);

	board.set_board(25, 51, 43);
	board.set_board(21, 45, 44) ; // #2
	for (int i = 0; i < 3; i++)
		board.set_board(22, (44 + i), 44);

	board.set_board(23, 45, 43);
	board.set_board(20, 37, 44); // #3
	for (int i = 0; i < 3; i++)
		board.set_board(21, (36 + i), 44);

	board.set_board(22, 37, 43);
	board.set_board(22, 30, 44); // #4
	for (int i = 0; i < 3; i++)
		board.set_board(23, (29 + i), 44);

	board.set_board(24, 30, 43);
	board.set_board(23, 22, 44); // #5
	for (int i = 0; i < 3; i++)
		board.set_board(24, (21 + i), 44);

	board.set_board(25, 22, 43);
	board.set_board(16, 17, 44); // #6
	for (int i = 0; i < 3; i++)
		board.set_board(17, (16 + i), 44);

	board.set_board(18, 17, 43);
	board.set_board(18, 10, 44); // #7
	for (int i = 0; i < 3; i++)
		board.set_board(19, (9 + i), 44);

	board.set_board(20, 10, 43);
	board.set_board(20, 2, 44); // #8
	for (int i = 0; i < 3; i++)
		board.set_board(21, (1 + i), 44);

	board.set_board(22, 2, 43);
	board.set_board(26, 9, 44); // #9
	for (int i = 0; i < 3; i++)
		board.set_board(27, (8 + i), 44);

	board.set_board(28, 9, 43);
	board.set_board(28, 3, 44); // #10
	for (int i = 0; i < 3; i++)
		board.set_board(29, (2 + i), 44);

	board.set_board(30, 3, 43);
	board.set_board(23, 14, 44); // #11
	for (int i = 0; i < 3; i++)
		board.set_board(24, (13 + i), 44);

	board.set_board(25, 14, 43);

	//Bridge in Forest
	for (int i = 0; i < 4; i++)
	{
		board.set_board((33 + i), 3, -86);
	}
	
	//Grass block as garden in forest
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 && j == 4) continue;
			board.set_board((37 + i), (1 + j), -42);
		}
	}
	//Grass as garden in forest
	for (int i = 0; i < 12; i+=4)
	{
		for (int j = 0; j < 5; j+=3)
		{
			//if (i == 0 && j == 4) continue;
			//board.set_board((37 + i), (1 + j), -2);
			//board.set_board((39 + i), (2 + j), -2);
		}
	}

	//Flowers in Mage Forest Garden
	//Sunflower
	board.set_board(38, 4, -53);
	board.set_board(46, 3, -53);
	board.set_board(50, 2, -53);
	//Rose
	board.set_board(42, 2, -54);
	board.set_board(49, 5, -54);
	board.set_board(50, 1, -54);
	//Lavenders
	board.set_board(37, 1, -55);
	board.set_board(44, 5, -55);
	board.set_board(50, 3, -55);
	//Between Elf and mage
	for (int i = 0; i < 45; i += 3)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 1) continue;
			board.set_board((59 + j), (12 + i), -53);
			board.set_board((59 + j), (13 + i), -54);
			board.set_board((59 + j), (14 + i), -55);
		}
	}
	board.set_board(60, 58, 33);
	// Inside dungeon
	for (int i = 0; i < 14; i+=4) 
	{
		board.set_board((24 + i), 96, -53); // room 1
		board.set_board((27 + i), 99, -54); // room 1
		board.set_board((25 + i), 102, -55); // room 1
		board.set_board((24 + i), 64, -53); // room 1
		board.set_board((27 + i), 67, -54); // room 1
		board.set_board((25 + i), 70, -55); // room 1
		board.set_board((45 + i), 96, -54); // room 2
		board.set_board((48 + i), 99, -53); // room 2
		board.set_board((46 + i), 102, -55); // room 2
		board.set_board((66 + i), 96, -55); // room 3
		board.set_board((69 + i), 99, -54); // room 3
		board.set_board((67 + i), 102, -53); // room 3
		board.set_board((66 + i), 64, -55); // room 3
		board.set_board((69 + i), 67, -54); // room 3
		board.set_board((67 + i), 70, -53); // room 3
	}

	// Cage in forest
	for (int i = 0; i < 3; i++)
		board.set_board((16 + i), 4, 56);
	for (int i = 0; i < 2; i++)
		board.set_board(18, (1 + i), 56);

	// NPCs in forest
	board.set_board(21, 51, 57); // Missing Mage in forest-Entrance #1 
	board.set_board(16, 1, 58); // Missing Mage in forest-Cage #2
	board.set_board(49, 2, 59); // Missing Mage in forest-Garden #3
	// Dungeon Level 
	for (int i = 0; i < 49; i++) // Rows wall
	{
		if (i >= 26 && i <= 32) continue;
		board.set_board(23, (62 + i), 65);// room 1
		board.set_board(40, (62 + i), 65);// room 1
		board.set_board(44, (62 + i), 65);// room 2
		board.set_board(61, (62 + i), 65);// room 2
		board.set_board(65, (62 + i), 65);// room 3
		board.set_board(82, (62 + i), 65);// room 3
	}
	for (int i = 0; i < 16; i++) // outer col wall
	{
		board.set_board((24 + i), 62, 65);// room 1
		board.set_board((24 + i), 110, 65); // room 1
		board.set_board((45 + i), 62, 65); // room 2
		board.set_board((45 + i), 110, 65); // room 2
		board.set_board((66 + i), 62, 65); // room 3
		board.set_board((66 + i), 110, 65); // room 3
	}
	for (int i = 0; i < 4; i++) // inner col gap wall
	{
		board.set_board((40 + i), 87, 65); // room 1
		board.set_board((40 + i), 95, 65); // room 1
		board.set_board((61 + i), 87, 65); // room 2
		board.set_board((61 + i), 95, 65); // room 2
		board.set_board((83 + i), 87, 65); // room 3
		board.set_board((83 + i), 95, 65); // room 3
	}
	for (int i = 0; i < 10; i++) // dungeon wall divider
	{
		board.set_board((27 + i), 87, 65);
		board.set_board((48 + i), 87, 65);
		board.set_board((69 + i), 87, 65);
	}
	for (int i = 0; i < 7; i++) // Door/Gates in Dungeon
	{
		board.set_board(23, (88 + i), 6);
		board.set_board(42, (88 + i), 6);
		board.set_board(63, (88 + i), 6);
		board.set_board(82, (88 + i), 6);
	}
	// Path to demon king castle
	for (int i = 0; i < 6; i++) // inner path
	{
		board.set_board((87 + i), 95, 2);
		board.set_board((87 + i), 125, 2);
	}
	for (int i = 0; i < 14; i++) // outer path
	{
		board.set_board((87 + i), 87, 2);
		board.set_board((87 + i), 136, 2);
	}
	for (int i = 0; i < 49; i++)// row path
		board.set_board(100, (87 + i), 2);
	for (int i = 0; i < 31; i++)// row path
		board.set_board(93, (95 + i), 2);

	// DECORATIONS/EXTRA ROOMS/Empty Spaces
	// River Block
	for (int i = 0; i < 47; i++)
	{
		for (int j = 0; j < 3; j++)
			board.set_board((89 + j), i, 4);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 13; j++)
			board.set_board((76 + j), i, 4);
	}
	for (int i = 0; i < 54; i++)
	{
		board.set_board(58, (7 + i), 4);
		if (i >= 4)
			board.set_board(62, (7 + i), 4);
	}
	board.set_board(59, 11, 4);
	board.set_board(61, 11, 4);

	for (int i = 0; i < 10; i++)
		board.set_board((59 + i), 7, 4);

	for (int i = 0; i < 3; i++)
		board.set_board((59 + i), 60, 4);

	// River In Forest
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 14; j++)
			board.set_board((37 + j), (6 + i), 4);
	}
	for (int i = 0; i < 9; i++) // river 90 curve at forest
	{
		if (i == 2) continue;
		board.set_board(36, (1 + i), 4);
		if (i == 8) continue;
		board.set_board(35, (1 + i), 4);
		if (i == 7) continue;
		board.set_board(34, (1 + i), 4);
		if (i == 6) continue;
		board.set_board(33, (1 + i), 4);
	}
	board.set_board(37, 5, 4);
	// Pond in each dungeon room
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			board.set_board((29 + i), (105 + j), 4);
			board.set_board((50 + i), (105 + j), 4);
			board.set_board((71 + i), (105 + j), 4);
		}
	}
	for (int i = 0; i < 5; i++) // row Wall for pond
	{
		board.set_board(28, (105 + i), 6);
		board.set_board(35, (105 + i), 6);
		board.set_board(49, (105 + i), 6);
		board.set_board(56, (105 + i), 6);
		board.set_board(70, (105 + i), 6);
		board.set_board(77, (105 + i), 6);
	}
	for (int i = 0; i < 8; i++) // col Wall for pond
	{
		board.set_board((28 + i), 104, 6);
		board.set_board((49 + i), 104, 6);
		board.set_board((70 + i), 104, 6);
	}
	for (int i = 0; i < 47; i++) // Grass Block
	{
		board.set_board(92, i, -42);
		if (i > 10)
			board.set_board(88, i, -42);
	}
	for (int i = 0; i < 47; i++)
	{
		if (i >= 23 && i <= 25) continue;
		board.set_board(93, i, -42);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 67; j < 89; j++)
		{
			if (j >= 69 && j <= 75) continue;
			board.set_board(j, (8 + i), -42);
		}

	}
	for (int i = 0; i < 6; i++)// Grass in Dungeon
	{
		for (int j = 0; j < 4; j++)
		{
			board.set_board((24 + j), (104 + i), -42);
			board.set_board((36 + j), (104 + i), -42);
			board.set_board((45 + j), (104 + i), -42);
			board.set_board((57 + j), (104 + i), -42);
			board.set_board((66 + j), (104 + i), -42);
			board.set_board((78 + j), (104 + i), -42);
		}
	}
	for (int i = 0; i < 15; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 46; j++)
		{
			if (i >= 2 && i <= 10) continue;
			board.set_board(i, (50 + j), -42);
		}
	}
	for (int i = 0; i < 20; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 15; j++)
			board.set_board(i, (96 + j), -42);
	}
	for (int i = 0; i < 3; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 49; j++)
		{
			if (j >= 25  && j <= 33) continue;
			board.set_board((20 + i), (62 + j), -42);
			board.set_board((41 + i), (62 + j), -42);
			board.set_board((62 + i), (62 + j), -42);
			board.set_board((83 + i), (62 + j), -42);
		}
	}
	for (int i = 0; i < 37; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 3; j++)
			board.set_board((64 + i), (59 + j), -42);
	}
	for (int i = 0; i < 7; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 89; j++)
		{
			if (j >= 25 && j <= 33) continue;
			if (j >= 63 && j <= 74) continue;
			board.set_board((86 + i), (62 + j), -42);
		}
	}
	for (int i = 0; i < 8; i++)// Grass in empty spaces
	{
		for (int j = 0; j < 89; j++)
		{
			if (j >= 25 && j <= 74) continue;
			board.set_board((93 + i), (62 + j), -42);
		}
	}
	for (int i = 0; i < 12; i++) // Lava
	{
		for (int j = 0; j < 9; j++)
		{
			board.set_board(i, (142 + j), 60);
			if (j == 8) continue;
			board.set_board(i, (111 + j), 60);
		}
	}
	for (int i = 0; i < 3; i++)// Lava
	{
		for (int j = 0; j < 40; j++)
		{
			if (j >= 14 && j <= 25) continue;
			board.set_board((12 + i), (111 + j), 60);
			board.set_board((40 + i), (111 + j), 60);
			board.set_board((63 + i), (111 + j), 60);
			board.set_board((83 + i), (111 + j), 60);
		}
	}
	for (int i = 0; i < 40; i++)// Lava
	{
		for (int j = 0; j < 2; j++)
		{
			board.set_board((43 + i), (111 + j), 60);
			board.set_board((43 + i), (149 + j), 60);
		}
	}
	//Ocean
	for (int i = 0; i < 30; i+=2)
	{
		for (int j = 0; j < 151; j++)
		{
			board.set_board((101 + i), j, 7);
			board.set_board((102 + i), j, 4);
		}
	}
	for (int i = 0; i < 69; i+=7)
	{
		for (int j = 0; j < 11; j+=4)
		{
			if (i == 21 && j == 0) continue;
			board.set_board((132 + j), (7 + i), -2);
			board.set_board((135 + j), (11 + i), -2);
		}
	}
	// Moris Empire and Emperor Castle
	for (int i = 0; i < 19; i++) 
	{
		board.set_board((132 + i), 0, 2);
		board.set_board((134 + i), 150, 2);
		if (i >= 5 && i <= 12) continue;
		board.set_board((132 + i), 75, 2);
	}
	for (int i = 0; i < 10; i++)
		board.set_board((136 + i), 126, 2);

	for (int j = 0; j < 148; j++)
	{
		board.set_board(150, j, 2);
		if (j >= 25 && j <= 31) continue;
		board.set_board(131, j, 2);
	}
	board.set_board(133, 149, 2);
	board.set_board(132, 148, 2);
	board.set_board(149, 148, 2);
	board.set_board(148, 149, 2);
	//Grass
	for (int i = 0; i < 3; i++)
	{
		board.set_board(131, (148 + i), -42);
		board.set_board(150, (148 + i), -42);
	}
	for (int i = 0; i < 2; i++)
	{
		board.set_board(132, (149 + i), -42);
		board.set_board(149, (149 + i), -42);
	}
	board.set_board(133, 150, -42);
	board.set_board(148, 150, -42);

	// Swordsman NPC
	board.set_board(135, 7, 74); // Messenger
	board.set_board(132, 26, 75); // Docks
	board.set_board(138, 41, 76); // Fountain 1
	board.set_board(137, 72, 77); // Garden 2
	board.set_board(144, 91, 72); // Guard 1
	board.set_board(141, 46, 76); // Fountain 2
	board.set_board(133, 67, 77); // Garden 1
	board.set_board(137, 91, 72); // Guard 2
	// Houses
	for (int i = 0; i < 5; i++)
	{
		board.set_board((133 + i), 1, 18); // 1
		board.set_board((139 + i), 1, 18); // 2
		board.set_board((145 + i), 1, 18); // 3
		board.set_board(149, (10 + i), 18); // 4
		board.set_board(149, (18 + i), 18); // 5
		board.set_board(149, (26 + i), 18); // 6
		board.set_board(149, (34 + i), 18); // 7
		board.set_board(149, (42 + i), 18); // 8
		board.set_board(149, (50 + i), 18); // 9
		board.set_board(149, (58 + i), 18); // 10
		board.set_board(149, (66 + i), 18); // 11
		board.set_board(133, (1 + i), 18); // 1
		board.set_board(137, (1 + i), 18); // 1
		board.set_board(139, (1 + i), 18); // 2
		board.set_board(143, (1 + i), 18); // 2 
		board.set_board(145, (1 + i), 18); // 3
		board.set_board(149, (1 + i), 18); // 3
		board.set_board((145 + i), 10, 18); // 4
		board.set_board((145 + i), 14, 18); // 4
		board.set_board((145 + i), 18, 18); // 5
		board.set_board((145 + i), 22, 18); // 5
		board.set_board((145 + i), 26, 18); // 6
		board.set_board((145 + i), 30, 18); // 6
		board.set_board((145 + i), 34, 18); // 7
		board.set_board((145 + i), 38, 18); // 7
		board.set_board((145 + i), 42, 18); // 8
		board.set_board((145 + i), 46, 18); // 8
		board.set_board((145 + i), 50, 18); // 9
		board.set_board((145 + i), 54, 18); // 9
		board.set_board((145 + i), 58, 18); // 10
		board.set_board((145 + i), 62, 18); // 10
		board.set_board((145 + i), 66, 18); // 11
		board.set_board((145 + i), 70, 18); // 11
		// Water
		board.set_board((145 + i), 74, 4);
		//Flowerbeds
		board.set_board(132, (1 + i), -30);
		board.set_board(138, (1 + i), -30);
		board.set_board(144, (1 + i), -30);
		board.set_board(132, (65 + i), -30);
		board.set_board(132, (70 + i), -30);
		board.set_board(134, (65 + i), -30);
		board.set_board(134, (70 + i), -30);
		board.set_board(136, (65 + i), -30);
		board.set_board(136, (70 + i), -30);
		for (int j = 0; j < 3; j++)
		{
			board.set_board((145 + i), (15 + j), -30);
			board.set_board((145 + i), (23 + j), -30);
			board.set_board((145 + i), (31 + j), -30);
			board.set_board((145 + i), (39 + j), -30);
			board.set_board((145 + i), (47 + j), -30);
			board.set_board((145 + i), (55 + j), -30);
			board.set_board((145 + i), (63 + j), -30);
			board.set_board((145 + i), (71 + j), -30);
		}
	}

	board.set_board(134, 6, 18); // 1
	board.set_board(135, 6, -84); // Door
	board.set_board(136, 6, 18); // 1
	board.set_board(140, 6, 18); // 2
	board.set_board(141, 6, -84); // Door
	board.set_board(142, 6, 18); // 2
	board.set_board(146, 6, 18); // 3
	board.set_board(147, 6, -84); // Door
	board.set_board(148, 6, 18); // 3
	board.set_board(144, 11, 18); // 4
	board.set_board(144, 12, -85); // Door
	board.set_board(144, 13, 18); // 4
	board.set_board(144, 19, 18); // 5
	board.set_board(144, 20, -85); // Door
	board.set_board(144, 21, 18); // 5
	board.set_board(144, 27, 18); // 6
	board.set_board(144, 28, -85); // Door
	board.set_board(144, 29, 18); // 6
	board.set_board(144, 35, 18); // 7
	board.set_board(144, 36, -85); // Door
	board.set_board(144, 37, 18); // 7
	board.set_board(144, 43, 18); // 8
	board.set_board(144, 44, -85); // Door
	board.set_board(144, 45, 18); // 8
	board.set_board(144, 51, 18); // 9
	board.set_board(144, 52, -85); // Door
	board.set_board(144, 53, 18); // 9
	board.set_board(144, 59, 18); // 10
	board.set_board(144, 60, -85); // Door
	board.set_board(144, 61, 18); // 10
	board.set_board(144, 67, 18); // 11
	board.set_board(144, 68, -85); // Door
	board.set_board(144, 69, 18); // 11

	// Fountain border (Moris Empire)
	for (int i = 0; i < 3; ++i) {
		board.set_board(137, (43 + i), 2);
		board.set_board(141, (43 + i), 2);
	}
	for (int i = 0; i < 2; ++i) {
		board.set_board(138 + (i * 2), 42, 2);
		board.set_board(138 + (i * 2), 46, 2);
	}
	board.set_board(139, 41, 2);
	board.set_board(139, 47, 2);

	// Fountain water (Moris Empire)
	for (int i = 0; i < 3; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(138 + i, 43 + i2, 4);
	}
	board.set_board(139, 42, 4);
	board.set_board(139, 46, 4);
	// Emperor Castle carpet
	for (int i = 0; i < 50; i++)
	{
		//if (i >= 25 && i <= 33) continue;
		board.set_board(136, (76 + i), -64);
		board.set_board(145, (76 + i), -64);
	}
	// Emperor Throne 
	for (int i = 0; i < 6; i++)
		board.set_board((138 + i), 125, 17);

	board.set_board(138, 124, 17);
	board.set_board(140, 124, 17);
	board.set_board(141, 124, 17);
	board.set_board(143, 124, 17);
	// Emperor (Da man, Da legend, Da myth)
	board.set_board(139, 124, 73);
	//Dining area
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			board.set_board((133 + j), (78 + i), 34);
			board.set_board((147 + j), (78 + i), 34);
		}
	}
	for (int i = 0; i < 40; i+=3) // Chairs
	{
		board.set_board(132, (78 + i), -35);
		board.set_board(149, (78 + i), -35);
	}
	// Bed
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board.set_board((139 + i), (145 + j), 10);
			board.set_board((139 + i), 149, 18);
		}
	}
	// Fountain border (Emperor Room)
	for (int i = 0; i < 3; ++i) {
		board.set_board(138, (132 + i), 2);
		board.set_board(143, (132 + i), 2);
	}
	for (int i = 0; i < 2; ++i) {
		board.set_board(139 + (i * 3), 131, 2);
		board.set_board(139 + (i * 3), 135, 2);
	}
	board.set_board(140, 130, 2);
	board.set_board(140, 136, 2);
	board.set_board(141, 130, 2);
	board.set_board(141, 136, 2);

	// Fountain water (Emperor Room)
	for (int i = 0; i < 4; ++i) {
		for (int i2 = 0; i2 < 3; ++i2)
			board.set_board(139 + i, 132 + i2, 4);
	}
	board.set_board(140, 131, 4);
	board.set_board(140, 135, 4);
	board.set_board(141, 131, 4);
	board.set_board(141, 135, 4);
	//Fishes
	board.set_board(139, 134, 81);
	board.set_board(141, 132, 80);

	// Ship
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
			board.set_board((126 + i), (25 + j), 12);
	}
	board.set_board(127, 33, 12);
	for (int i = 0; i < 9; i++)
	{
		board.set_board(125, (24 + i), 18);
		board.set_board(129, (24 + i), 18);
	}
	board.set_board(126, 33, 18);
	board.set_board(127, 34, 18);
	board.set_board(128, 33, 18);
	for (int i = 0; i < 3; i++)
		board.set_board((126 + i), 24, 18);

	for (int i = 0; i < 3; i++)
		board.set_board(130, (27 + i), 17);
	
	for (int i = 0; i < 7; i++)
	{
		board.set_board(131, (25 + i), 17);
	}
	//Second Spawnpoint (Grass and flowers)
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			board.set_board((95 + i), j, -42);
	}
	board.set_board(96, 0, -53);
	board.set_board(98, 1, -54);
	board.set_board(97, 4, -55);
	board.set_board(95, 3, -53);
}