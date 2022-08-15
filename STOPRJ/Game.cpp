#include "Game.h"
#include <iostream>
#include <string>

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
	system("cls");
	input("Ensure that the console window is full screen : ");
	system("cls");
	board.print_board();
}

std::string Game::input(std::string txt)
{
	std::string ret;
	std::cout << txt;
	std::getline(std::cin, ret);
	return ret;
}
