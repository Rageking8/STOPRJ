#pragma once
#include <string>
#include <chrono>

namespace Common
{
	// Prints text for prompting and returns user input
	std::string input(std::string txt, bool write = true);

	// Prints given text in specified text colour and background (using color_code)
	void color_print(unsigned short color_code, std::string txt);
	void color_print(unsigned short color_code, int num);
	
	// Move cursor then color print
	void color_print(short x, short y, unsigned short color_code, std::string txt);

	// Prints given text with writing animation
	// Returns std::string to be able to use in Common::input
	std::string write_ani(std::string txt, const unsigned short delay_ms = 12);

	std::string write_ani(unsigned short color_code, std::string txt, const unsigned short delay_ms = 12);

	// Generates a random integer in range [min, max]
	int rand_int(int min, int max);

	// Print string mulitplied by a number and returns the resulting string
	std::string mul_txt(std::string txt, unsigned no, bool print = false);

	// Change visibility of console cursor
	void cursor_vis(bool new_state);

	// Sets cursor to new coordinate
	void set_cursor(short x, short y);

	// Move cursor in one direction (WASD)
	void move_cursor(char dir);

	// Get length of integer (number of digits)
	int int_len(unsigned num);

	// Wait for any key to be pressed before proceeding
	void any_key_press();

	// Print text before waiting
	void any_key_press(std::string txt);

	// Timer starts when object is instantiated and ends when the end() member function is called
	// Return time elapsed unit is in nanoseconds (1 second = 1,000,000,000 nanoseconds)
	class Timer {
	public:
		Timer();
		~Timer();
		long long end();
	private:
		std::chrono::high_resolution_clock::time_point start;
	};
};
