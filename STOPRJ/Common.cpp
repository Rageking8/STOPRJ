#include "Common.h"
#include <string>
#include <iostream>
#include <random>
#include "Windows.h"

std::string Common::input(std::string txt, bool write)
{
	if (write)
		std::cout << txt;
	std::string ret;
	std::getline(std::cin, ret);
	return ret;
}

void Common::color_print(unsigned short color_code, std::string txt)
{
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color_code);
	std::cout << txt;
	SetConsoleTextAttribute(h, 7);
}

std::string Common::write_ani(std::string txt, const unsigned short delay_ms)
{
	for (const auto i : txt) {
		std::cout << i;
		Sleep(delay_ms);
	}

	return txt;
}

int Common::rand_int(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

std::string Common::mul_txt(std::string txt, unsigned no, bool print)
{
	std::string ret = "";
	for (unsigned i = 0; i < no; ++i) {
		if (print)
			std::cout << txt;
		ret += txt;
	}
	return ret;
}
