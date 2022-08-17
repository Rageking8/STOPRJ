#pragma once
#include <string>

namespace Common
{
	// Prints text for prompting and returns user input
	std::string input(std::string txt, bool write = true);

	// Prints given text in specified text colour and background (using color_code)
	void color_print(unsigned short color_code, std::string txt);

	// Prints given text with writing animation
	// Returns std::string to be able to use in Common::input
	std::string write_ani(std::string txt, const unsigned short delay_ms = 14);

	// Generates a random integer in range [min, max]
	int rand_int(int min, int max);

	// Print string mulitplied by a number and returns the resulting string
	std::string mul_txt(std::string txt, unsigned no, bool print = false);
};
