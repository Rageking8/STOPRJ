#include "Game.h"
#include <iostream>

size_t top_of_stack;

size_t SizeOfStack()
{
	int x = 0;
	return top_of_stack - (size_t)&x;
}

int main()
{
	int x = 0;
	top_of_stack = (size_t)&x;
	while (true) {
		Game game;
		game.start();
		
		std::cout << SizeOfStack();

		while (true);
	}
}
