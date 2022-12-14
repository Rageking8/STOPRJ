#include "Common.h"
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include "conio.h"
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

std::string Common::input(std::string txt, bool write)
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	if (write)
		std::cout << txt;
	std::string ret;
	std::getline(std::cin, ret);
	return ret;
}

void Common::color_print(unsigned short color_code, std::string txt)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color_code);
	std::cout << txt;
	SetConsoleTextAttribute(h, 0x07);
}

void Common::color_print(unsigned short color_code, int num)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, color_code);
	std::cout << num;
	SetConsoleTextAttribute(h, 0x07);
}

void Common::color_print(short x, short y, unsigned short color_code, std::string txt)
{
	set_cursor(x, y);
	color_print(color_code, txt);
}

void Common::print_frame()
{
	system("cls");
	Common::set_cursor(0, 0);
	for (int i = 0; i < 5; ++i)
		Common::color_print(0xE0, "                         ");

	for (int i = 1; i < 30; ++i) {
		Common::set_cursor(0, i);
		Common::color_print(0xE0, "  ");
		Common::color_print(0x80, " ");

		if (i == 1 || i == 29) {
			Common::move_cursor('A');
			Common::color_print(0xC0, "  ");
			Common::set_cursor(121, i);
			Common::color_print(0xC0, "  ");
		}
		else {
			Common::set_cursor(122, i);
			Common::color_print(0x80, " ");
			Common::color_print(0xE0, "  ");
			continue;
		}
		Common::set_cursor(123, i);
		Common::color_print(0xE0, "  ");
	}

	Common::color_print(2, 2, 0xE0, "  ");
	Common::color_print(4, 1, 0xE0, "  ");
	Common::color_print(2, 28, 0xE0, "  ");
	Common::color_print(4, 29, 0xE0, "  ");
	Common::color_print(119, 1, 0xE0, "  ");
	Common::color_print(121, 2, 0xE0, "  ");
	Common::color_print(119, 29, 0xE0, "  ");
	Common::color_print(121, 28, 0xE0, "  ");

	Common::set_cursor(0, 30);
	for (int i = 0; i < 5; ++i)
		Common::color_print(0xE0, "                         ");
}

std::string Common::write_ani(std::string txt, const unsigned short delay_ms)
{
	for (const auto i : txt) {
		std::cout << i;
		Sleep(delay_ms);
	}

	return txt;
}

std::string Common::write_ani(unsigned short color_code, std::string txt, const unsigned short delay_ms)
{
	for (const auto i : txt) {
		color_print(color_code, std::string() + i);
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

void Common::cursor_vis(bool new_state)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(h, &cursorInfo);
	cursorInfo.bVisible = new_state;
	SetConsoleCursorInfo(h, &cursorInfo);
}

void Common::set_cursor(short x, short y)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, COORD{ x, y });
}

void Common::move_cursor(char dir)
{
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(h, &cbsi))
	{
		COORD pos = cbsi.dwCursorPosition;
		switch (dir) {
			case 'w':
			case 'W':
				set_cursor(pos.X, pos.Y - 1);
				break;
			case 'a':
			case 'A':
				set_cursor(pos.X - 1, pos.Y);
				break;
			case 's':
			case 'S':
				set_cursor(pos.X, pos.Y - 1);
				break;
			case 'd':
			case 'D':
				set_cursor(pos.X + 1, pos.Y);
				break;
		}
	}
}

int Common::int_len(unsigned num)
{
	if (num < 10) return 1;
	num /= 10;
	int ret = 1;
	while (num > 9) {
		num /= 10;
		ret++;
	}
	return ret + 1;
}

void Common::any_key_press()
{
	auto start = std::chrono::high_resolution_clock::now();
	while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() < 100) {
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	}
	int c = _getch();
	if (c == 224) {
		c = _getch();
	}
}

void Common::any_key_press(std::string txt)
{
	std::cout << txt;
	any_key_press();
}

Common::Timer::Timer()
{
	start = std::chrono::high_resolution_clock::now();
}

Common::Timer::~Timer()
{
}

long long Common::Timer::end()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
}
