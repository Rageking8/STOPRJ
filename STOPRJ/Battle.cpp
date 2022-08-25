#include "Game.h"
#include "Common.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

bool Game::start_battle(std::string id)
{
	bool ret = false;
	Common::cursor_vis(true);
	const static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	Character enemy[4];

	if (id == "ambush") {
		for (int i = 0; i < 4; ++i) {
			enemy[i].set_name("Elf Troop");
			enemy[i].set_stats("cur_health", 5);
			enemy[i].set_stats("max_health", 5);
			enemy[i].set_stats("cur_mp", 20);
			enemy[i].set_stats("max_mp", 20);
			enemy[i].init_skill("shoot_arrow", "raining_arrow", "piercing_arrow", "bullet_arrow");
		}
	}
	else if (id == "bandit_1") {
		for (int i = 0; i < 4; ++i) {
			enemy[i].set_name("Bandits");
			enemy[i].set_stats("cur_health", 10);
			enemy[i].set_stats("max_health", 10);
			enemy[i].set_stats("cur_mp", 25);
			enemy[i].set_stats("max_mp", 25);
			enemy[i].init_skill("dagger_poke", "strength_dart", "bomb", "backstab");
		}
	}
	else if (id == "bandit_2") {
		for (int i = 0; i < 2; ++i) {
			enemy[i].set_name("Bandits");
			enemy[i].set_stats("cur_health", 15);
			enemy[i].set_stats("max_health", 15);
			enemy[i].set_stats("cur_mp", 25);
			enemy[i].set_stats("max_mp", 25);
			enemy[i].init_skill("dagger_poke", "strength_dart", "bomb", "backstab");
		}
		enemy[2].set_name("Bandit Leader");
		enemy[2].set_stats("attack", 5);
		enemy[2].set_stats("cur_health", 25);
		enemy[2].set_stats("max_health", 25);
		enemy[2].set_stats("cur_mp", 50);
		enemy[2].set_stats("max_mp", 50);
		enemy[2].init_skill("dagger_poke", "strength_dart", "bomb", "backstab");
		enemy[2].set_active(2, true);
	}
	else if (id == "dun_f1") {
		for (int i = 0; i < 4; ++i) {
			enemy[i].set_name("Skeleton");
			enemy[i].set_stats("attack", 3);
			enemy[i].set_stats("cur_health", 20);
			enemy[i].set_stats("max_health", 20);
			enemy[i].set_stats("cur_mp", 50);
			enemy[i].set_stats("max_mp", 50);
			enemy[i].init_skill("slash", "headbutt", "shield_bash", "arm_slap");
			enemy[i].set_active(2, true);
		}
	}
	else if (id == "dun_f3") {
		enemy[0].set_name("Olaf");
		enemy[0].set_stats("attack", 20);
		enemy[0].set_stats("cur_health", 130);
		enemy[0].set_stats("max_health", 130);
		enemy[0].set_stats("cur_mp", 80);
		enemy[0].set_stats("max_mp", 80);
		enemy[0].init_skill("slash", "headbutt", "shield_bash", "arm_slap");
		enemy[0].set_active(2, true);
		enemy[0].set_active(3, true);
	}
	else if (id == "dkc_1") {
		for (int i = 0; i < 4; ++i) {
			enemy[i].set_name("Lava Skeleton");
			enemy[i].set_stats("attack", 10);
			enemy[i].set_stats("cur_health", 40);
			enemy[i].set_stats("max_health", 40);
			enemy[i].set_stats("cur_mp", 55);
			enemy[i].set_stats("max_mp", 55);
			enemy[i].init_skill("slash", "headbutt", "shield_bash", "arm_slap");
			enemy[i].set_active(2, true);
			enemy[i].set_active(3, true);
		}
	}
	else if (id == "dkc_2") {
		for (int i = 0; i < 3; ++i) {
			enemy[i].set_name("Skeleton");
			enemy[i].set_stats("attack", 13);
			enemy[i].set_stats("cur_health", 60);
			enemy[i].set_stats("max_health", 60);
			enemy[i].set_stats("cur_mp", 60);
			enemy[i].set_stats("max_mp", 60);
			enemy[i].init_skill("slash", "headbutt", "shield_bash", "arm_slap");
			enemy[i].set_active(2, true);
			enemy[i].set_active(3, true);
		}
		enemy[3].set_name("Demon");
		enemy[3].set_stats("attack", 30);
		enemy[3].set_stats("cur_health", 180);
		enemy[3].set_stats("max_health", 180);
		enemy[3].set_stats("cur_mp", 155);
		enemy[3].set_stats("max_mp", 155);
		enemy[3].init_skill("demon_slash", "demon_eye_beam", "demon_strength", "fire_breath");
		enemy[3].set_active(2, true);
		enemy[3].set_active(3, true);
	}
	else if (id == "dkc_3") {
		for (int i = 0; i < 2; ++i) {
			enemy[i].set_name("Skeleton");
			enemy[i].set_stats("attack", 15);
			enemy[i].set_stats("cur_health", 70);
			enemy[i].set_stats("max_health", 70);
			enemy[i].set_stats("cur_mp", 60);
			enemy[i].set_stats("max_mp", 60);
			enemy[i].init_skill("slash", "headbutt", "shield_bash", "arm_slap");
			enemy[i].set_active(2, true);
			enemy[i].set_active(3, true);
		}
		enemy[2].set_name("Demon");
		enemy[2].set_stats("attack", 32);
		enemy[2].set_stats("cur_health", 190);
		enemy[2].set_stats("max_health", 190);
		enemy[2].set_stats("cur_mp", 160);
		enemy[2].set_stats("max_mp", 160);
		enemy[2].init_skill("demon_slash", "demon_eye_beam", "demon_strength", "fire_breath");
		enemy[2].set_active(2, true);
		enemy[2].set_active(3, true);

		enemy[3].set_name("Demon King");
		enemy[3].set_stats("attack", 40);
		enemy[3].set_stats("cur_health", 200);
		enemy[3].set_stats("max_health", 200);
		enemy[3].set_stats("cur_mp", 200);
		enemy[3].set_stats("max_mp", 200);
		enemy[3].init_skill("demon_punch", "long_live_the_king", "demon_summon", "hellfire");
		enemy[3].set_active(2, true);
		enemy[3].set_active(3, true);
	}

	bool slot_active[8]{};

	for (int i = 0; i < 4; ++i) {
		if (enemy[i].get_name() != "") {
			slot_active[i] = true;
		}
	}
	slot_active[4] = (swordsman.get_stats("cur_health") > 0);
	slot_active[5] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
	slot_active[6] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
	slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

	int current_turn = -1;
	for (int i = 4; i < 8; ++i) {
		if (slot_active[i]) {
			current_turn = i;
			break;
		}
	}

	while (true) {
		for (int i = 0; i < 4; ++i) {
			if (slot_active[i]) {
				int tmp_color = 0x07;
				if (current_turn == i) {
					SetConsoleTextAttribute(h, 0x0E);
					tmp_color = 0x0E;
				}

				Common::set_cursor(i * 25, 0);
				//std::cout << "|======================| ";
				DWORD n;
				WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n, nullptr);
				Common::set_cursor(i * 25, 1);
				std::cout << "| " << enemy[i].get_name() << Common::mul_txt(" ", 21 - enemy[i].get_name().length()) << "| ";
				Common::set_cursor(i * 25, 2);
				std::cout << "| Attack : " << enemy[i].get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(enemy[i].get_stats("attack"))) << "| ";
				Common::set_cursor(i * 25, 3);
				std::cout << "| Health : " << enemy[i].get_stats("cur_health") << " / " << enemy[i].get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(enemy[i].get_stats("cur_health")) + 3 + Common::int_len(enemy[i].get_stats("max_health")))) << "| ";
				Common::set_cursor(i * 25, 4);
				std::cout << "| MP : " << enemy[i].get_stats("cur_mp") << " / " << enemy[i].get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(enemy[i].get_stats("cur_mp")) + 3 + Common::int_len(enemy[i].get_stats("max_mp")))) << "| ";
				Common::set_cursor(i * 25, 5);
				std::cout << "|                      | ";

				for (int i2 = 0; i2 < 4; ++i2) {
					Common::set_cursor(i * 25, 6 + i2);
					if (enemy[i].get_skill_list(i2).active) {
						std::string tmp_skill_name = enemy[i].get_skill_list(i2).name;
						Common::color_print(tmp_color, "| " + std::to_string(i2 + 1) + " ");
						enemy[i].print_color_name(i2);
						std::cout << Common::mul_txt(" ", 19 - tmp_skill_name.length());
						Common::color_print(tmp_color, "| ");
					}
					else {
						Common::color_print(tmp_color, "|                      | ");
					}
				}

				Common::set_cursor(i * 25, 10);
				//Common::color_print(tmp_color, "|======================| ");
				SetConsoleTextAttribute(h, tmp_color);
				DWORD n2;
				WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n2, nullptr);
				SetConsoleTextAttribute(h, 0x07);

				if (current_turn == i)
					SetConsoleTextAttribute(h, 0x07);
			}
		}

		if (slot_active[4]) {
			int tmp_color = 0x07;
			if (current_turn == 4) {
				SetConsoleTextAttribute(h, 0x0E);
				tmp_color = 0x0E;
			}

			Common::set_cursor(0, 15);
			//std::cout << "|======================| ";
			DWORD n;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n, nullptr);
			Common::set_cursor(0, 16);
			std::cout << "| " << swordsman.get_name() << Common::mul_txt(" ", 21 - swordsman.get_name().length()) << "| ";
			Common::set_cursor(0, 17);
			std::cout << "| Attack : " << swordsman.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(swordsman.get_stats("attack"))) << "| ";
			Common::set_cursor(0, 18);
			std::cout << "| Health : " << swordsman.get_stats("cur_health") << " / " << swordsman.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(swordsman.get_stats("cur_health")) + 3 + Common::int_len(swordsman.get_stats("max_health")))) << "| ";
			Common::set_cursor(0, 19);
			std::cout << "| MP : " << swordsman.get_stats("cur_mp") << " / " << swordsman.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(swordsman.get_stats("cur_mp")) + 3 + Common::int_len(swordsman.get_stats("max_mp")))) << "| ";
			Common::set_cursor(0, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(0, 21 + i);
				if (swordsman.get_skill_list(i).active) {
					std::string tmp_skill_name = swordsman.get_skill_list(i).name;
					Common::color_print(tmp_color, "| " + std::to_string(i + 1) + " ");
					swordsman.print_color_name(i);
					std::cout << Common::mul_txt(" ", 19 - tmp_skill_name.length());
					Common::color_print(tmp_color, "| ");
				}
				else {
					Common::color_print(tmp_color, "|                      | ");
				}
			}

			Common::set_cursor(0, 25);
			//Common::color_print(tmp_color, "|======================| ");
			SetConsoleTextAttribute(h, tmp_color);
			DWORD n2;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n2, nullptr);
			SetConsoleTextAttribute(h, 0x07);

			if (current_turn == 4)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[5]) {
			int tmp_color = 0x07;
			if (current_turn == 5) {
				SetConsoleTextAttribute(h, 0x0E);
				tmp_color = 0x0E;
			}

			Common::set_cursor(25, 15);
			//std::cout << "|======================| ";
			DWORD n;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n, nullptr);
			Common::set_cursor(25, 16);
			std::cout << "| " << elf.get_name() << Common::mul_txt(" ", 21 - elf.get_name().length()) << "| ";
			Common::set_cursor(25, 17);
			std::cout << "| Attack : " << elf.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(elf.get_stats("attack"))) << "| ";
			Common::set_cursor(25, 18);
			std::cout << "| Health : " << elf.get_stats("cur_health") << " / " << elf.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(elf.get_stats("cur_health")) + 3 + Common::int_len(elf.get_stats("max_health")))) << "| ";
			Common::set_cursor(25, 19);
			std::cout << "| MP : " << elf.get_stats("cur_mp") << " / " << elf.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(elf.get_stats("cur_mp")) + 3 + Common::int_len(elf.get_stats("max_mp")))) << "| ";
			Common::set_cursor(25, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(25, 21 + i);
				if (elf.get_skill_list(i).active) {
					std::string tmp_skill_name = elf.get_skill_list(i).name;
					Common::color_print(tmp_color, "| " + std::to_string(i + 1) + " ");
					elf.print_color_name(i);
					std::cout << Common::mul_txt(" ", 19 - tmp_skill_name.length());
					Common::color_print(tmp_color, "| ");
				}
				else {
					Common::color_print(tmp_color, "|                      | ");
				}
			}

			Common::set_cursor(25, 25);
			//Common::color_print(tmp_color, "|======================| ");
			SetConsoleTextAttribute(h, tmp_color);
			DWORD n2;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n2, nullptr);
			SetConsoleTextAttribute(h, 0x07);

			if (current_turn == 5)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[6]) {
			int tmp_color = 0x07;
			if (current_turn == 6) {
				SetConsoleTextAttribute(h, 0x0E);
				tmp_color = 0x0E;
			}

			Common::set_cursor(50, 15);
			//std::cout << "|======================| ";
			DWORD n;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n, nullptr);
			Common::set_cursor(50, 16);
			std::cout << "| " << mage.get_name() << Common::mul_txt(" ", 21 - mage.get_name().length()) << "| ";
			Common::set_cursor(50, 17);
			std::cout << "| Attack : " << mage.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(mage.get_stats("attack"))) << "| ";
			Common::set_cursor(50, 18);
			std::cout << "| Health : " << mage.get_stats("cur_health") << " / " << mage.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(mage.get_stats("cur_health")) + 3 + Common::int_len(mage.get_stats("max_health")))) << "| ";
			Common::set_cursor(50, 19);
			std::cout << "| MP : " << mage.get_stats("cur_mp") << " / " << mage.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(mage.get_stats("cur_mp")) + 3 + Common::int_len(mage.get_stats("max_mp")))) << "| ";
			Common::set_cursor(50, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(50, 21 + i);
				if (mage.get_skill_list(i).active) {
					std::string tmp_skill_name = mage.get_skill_list(i).name;
					Common::color_print(tmp_color, "| " + std::to_string(i + 1) + " ");
					mage.print_color_name(i);
					std::cout << Common::mul_txt(" ", 19 - tmp_skill_name.length());
					Common::color_print(tmp_color, "| ");
				}
				else {
					Common::color_print(tmp_color, "|                      | ");
				}
			}

			Common::set_cursor(50, 25);
			//Common::color_print(tmp_color, "|======================| ");
			SetConsoleTextAttribute(h, tmp_color);
			DWORD n2;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n2, nullptr);
			SetConsoleTextAttribute(h, 0x07);

			if (current_turn == 6)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[7]) {
			int tmp_color = 0x07;
			if (current_turn == 7) {
				SetConsoleTextAttribute(h, 0x0E);
				tmp_color = 0x0E;
			}

			Common::set_cursor(75, 15);
			//std::cout << "|======================| ";
			DWORD n;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n, nullptr);
			Common::set_cursor(75, 16);
			std::cout << "| " << assassin.get_name() << Common::mul_txt(" ", 21 - assassin.get_name().length()) << "| ";
			Common::set_cursor(75, 17);
			std::cout << "| Attack : " << assassin.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(assassin.get_stats("attack"))) << "| ";
			Common::set_cursor(75, 18);
			std::cout << "| Health : " << assassin.get_stats("cur_health") << " / " << assassin.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(assassin.get_stats("cur_health")) + 3 + Common::int_len(assassin.get_stats("max_health")))) << "| ";
			Common::set_cursor(75, 19);
			std::cout << "| MP : " << assassin.get_stats("cur_mp") << " / " << assassin.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(assassin.get_stats("cur_mp")) + 3 + Common::int_len(assassin.get_stats("max_mp")))) << "| ";
			Common::set_cursor(75, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(75, 21 + i);
				if (assassin.get_skill_list(i).active) {
					std::string tmp_skill_name = assassin.get_skill_list(i).name;
					Common::color_print(tmp_color, "| " + std::to_string(i + 1) + " ");
					assassin.print_color_name(i);
					std::cout << Common::mul_txt(" ", 19 - tmp_skill_name.length());
					Common::color_print(tmp_color, "| ");
				}
				else {
					Common::color_print(tmp_color, "|                      | ");
				}
			}

			Common::set_cursor(75, 25);
			//Common::color_print(tmp_color, "|======================| ");
			SetConsoleTextAttribute(h, tmp_color);
			DWORD n2;
			WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), L"+――――――――――――――――――――――+ ", 26, &n2, nullptr);
			SetConsoleTextAttribute(h, 0x07);

			if (current_turn == 7)
				SetConsoleTextAttribute(h, 0x07);
		}

		Common::set_cursor(0, 27);
		if (current_turn > 3) {
			// Allies turn

			bool cast_skill = true;

			std::string skill_input = Common::input("                             \nEnter which skill to cast (S for skill book) : ");
			while ((skill_input != "1" && skill_input != "2" && skill_input != "3" && skill_input != "4" && skill_input != "S" && skill_input != "s") ||
				((skill_input != "S" && skill_input != "s") &&

					((current_turn == 4 && (!swordsman.get_skill_list(std::stoi(skill_input) - 1).active || swordsman.get_stats("cur_mp") < swordsman.get_skill_list(std::stoi(skill_input) - 1).cost)) ||

						(current_turn == 5 && (!elf.get_skill_list(std::stoi(skill_input) - 1).active || elf.get_stats("cur_mp") < elf.get_skill_list(std::stoi(skill_input) - 1).cost)) ||

						(current_turn == 6 && (!mage.get_skill_list(std::stoi(skill_input) - 1).active || mage.get_stats("cur_mp") < mage.get_skill_list(std::stoi(skill_input) - 1).cost)) ||


						(current_turn == 7 && (!assassin.get_skill_list(std::stoi(skill_input) - 1).active || assassin.get_stats("cur_mp") < assassin.get_skill_list(std::stoi(skill_input) - 1).cost))))) {

				Common::set_cursor(47, 28);
				for (unsigned i = 0; i < skill_input.length(); ++i)
					std::cout << " ";
				Common::set_cursor(0, 27);
				skill_input = Common::input("Invalid skill / Not enough MP\nEnter which skill to cast (S for skill book) : ");
			}

			if (skill_input == "S" || skill_input == "s") {
				print_all_skill();
				system("cls");
				cast_skill = false;
			}
			else {
				int tmp_pow = 0;
				char tmp_skill_type = ' ';

				if (current_turn == 4) {
					if (swordsman.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = swordsman.get_stats("attack") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (swordsman.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						swordsman.set_stats("attack", swordsman.get_stats("attack") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") + swordsman.get_skill_list(std::stoi(skill_input) - 1).power);
						if (swordsman.get_stats("cur_health") > swordsman.get_stats("max_health"))
							swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
					}

					swordsman.set_stats("cur_mp", swordsman.get_stats("cur_mp") - swordsman.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 5) {
					if (elf.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = elf.get_stats("attack") + elf.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (elf.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						elf.set_stats("attack", elf.get_stats("attack") + elf.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						elf.set_stats("cur_health", elf.get_stats("cur_health") + elf.get_skill_list(std::stoi(skill_input) - 1).power);
						if (elf.get_stats("cur_health") > elf.get_stats("max_health"))
							elf.set_stats("cur_health", elf.get_stats("max_health"));
					}
					elf.set_stats("cur_mp", elf.get_stats("cur_mp") - elf.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 6) {
					if (mage.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = mage.get_stats("attack") + mage.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (mage.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						mage.set_stats("attack", mage.get_stats("attack") + mage.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						mage.set_stats("cur_health", mage.get_stats("cur_health") + mage.get_skill_list(std::stoi(skill_input) - 1).power);
						if (mage.get_stats("cur_health") > mage.get_stats("max_health"))
							mage.set_stats("cur_health", mage.get_stats("max_health"));
					}

					mage.set_stats("cur_mp", mage.get_stats("cur_mp") - mage.get_skill_list(std::stoi(skill_input) - 1).cost);
				}
				else if (current_turn == 7) {
					if (assassin.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'D') {
						tmp_pow = assassin.get_stats("attack") + assassin.get_skill_list(std::stoi(skill_input) - 1).power;
						tmp_skill_type = 'D';
					}
					else if (assassin.get_skill_list(std::stoi(skill_input) - 1).skill_type == 'A') {
						assassin.set_stats("attack", assassin.get_stats("attack") + assassin.get_skill_list(std::stoi(skill_input) - 1).power);
					}
					else {
						assassin.set_stats("cur_health", assassin.get_stats("cur_health") + assassin.get_skill_list(std::stoi(skill_input) - 1).power);
						if (assassin.get_stats("cur_health") > assassin.get_stats("max_health"))
							assassin.set_stats("cur_health", assassin.get_stats("max_health"));
					}
					assassin.set_stats("cur_mp", assassin.get_stats("cur_mp") - assassin.get_skill_list(std::stoi(skill_input) - 1).cost);
				}

				if (tmp_skill_type == 'D') {
					int tmp_active_enemy[4]{};
					int current_idx = 0;
					for (int i = 0; i < 4; ++i) {
						if (slot_active[i]) {
							tmp_active_enemy[current_idx] = i;
							current_idx++;
						}
					}
					int tmp_rand_enemy = tmp_active_enemy[Common::rand_int(0, current_idx - 1)];

					enemy[tmp_rand_enemy].set_stats("cur_health", enemy[tmp_rand_enemy].get_stats("cur_health") - tmp_pow);

					if (enemy[tmp_rand_enemy].get_stats("cur_health") <= 0) {
						for (int i = 0; i < 11; ++i) {
							Common::set_cursor(tmp_rand_enemy * 25, i);
							std::cout << "                         ";
						}
					}

					for (int i = 0; i < 4; ++i)
						slot_active[i] = (enemy[i].get_name() != "" && enemy[i].get_stats("cur_health") > 0);
					slot_active[4] = (swordsman.get_stats("cur_health") > 0);
					slot_active[5] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
					slot_active[6] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
					slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

					Common::cursor_vis(false);
					if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
						// Enemy all dead

						if (id == "ambush") {

							system("cls");


							Common::write_ani("You've gotten through your first battle! Just be careful, though. If your HP reaches ZERO, you die.\n\n"
								"However, for this BATTLE, and the next one, you can still progress with the story, regardless of whether you\n"
								"win or lose. Afterwards, it's an instant GAME OVER.\n\n"
								"Also, since your allies' MP cannot be recovered, any buffs received during BATTLEs will be retained even\n"
								"after a BATTLE ends.\n\n"
								"Now that you've gotten the basics of BATTLE, you'll be on your own from here on out! Good luck!\n\n");

							Common::any_key_press("Press any key to continue");

							story.winElora();
							swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
						}
						else if (id == "bandit_1") {
							story.recruitElora();
						}
						else if (id == "bandit_2") {
							if (elf.get_stats("cur_health") <= 0 && mage.get_stats("cur_health") <= 0) {
								story.defeatBandits_oriAndElrDead();
							}
							else if (elf.get_stats("cur_health") <= 0) {
								story.recruitOrion_eloraDead();
							}
							else if (mage.get_stats("cur_health") <= 0) {
								story.defeatBandits_orionDead();
							}
							else {
								story.recruitOrion_main();
							}
						}
						else if (id == "dun_f1") {
							story.excalibur_defeatedSkels();
						}
						else if (id == "dun_f3") {
							story.excalibur_giantDefeated();
						}
						else if (id == "dkc_1") {
							story.DKC_floor1Complete();
						}
						else if (id == "dkc_2") {
							story.DKC_floor2Complete();
						}
						else if (id == "dkc_3") {
							if ((slot_active[5] && slot_active[6]) || (slot_active[5] && slot_active[6] && slot_active[7])) {
								// player, orion and elora are alive / player, orion, elora, blaise are alive
								story.defeatDK_main();
								if (slot_active[7]) {
									story.blaiseBetrayal_orionAlive();
									story.defeatBlaise_main();
								}
								story.ending_main();
							}
							else if (slot_active[7]) {
								// only player and blaise are alive (choice input after this)
								story.defeatDK_blaiseOnly();
							}
							else if (slot_active[6] || (slot_active[6] && slot_active[7])) {
								// player and orion / player, orion and blaise alive
								story.defeatDK_eloraDead();
								if (slot_active[7]) {
									story.blaiseBetrayal_orionAlive();
									story.defeatBlaise_eloraDead();
								}
								story.ending_partyMemDead();
							}
							else if (slot_active[5] || (slot_active[5] && slot_active[7])) {
								// player and elora / player, elora and blaise alive
								story.defeatDK_orionDead();
								if (slot_active[7]) {
									story.blaiseBetrayal_orionDead();
									story.defeatBlaise_orionDead();
								}

								story.ending_partyMemDead();
							}
							else {
								// only player is alive
								story.defeatDK_playerOnly();
								story.ending_playerOnly();
							}
						}
						ret = true;

						break;
					}
					else if (!slot_active[4]) {

						if (id == "bandit_1") {

							story.recruitElora_loseBandits();

						}
						else if (id == "bandit_2" || id == "dun_f1" || id == "dun_f3" || id == "dkc_1" || id == "dkc_2") {

							if (slot_active[5] || slot_active[6] || slot_active[7])
								story.gameOver_playerDead();
							else
								story.gameOver_everyoneDead();

						}
						else {
							story.gameOver_everyoneDead();
						}
						ret = false;

						break;
					}
				}

				int tmp_active_ally[4]{};
				int current_idx = 0;
				for (int i = 4; i < 8; ++i) {
					if (slot_active[i]) {
						tmp_active_ally[current_idx] = i;
						current_idx++;
					}
				}
				for (int i = 0; i < current_idx; ++i) {
					if (tmp_active_ally[i] == current_turn && i < current_idx - 1) {
						current_turn = tmp_active_ally[i + 1];
						break;
					}
					else if (tmp_active_ally[i] == current_turn && i == current_idx - 1) {
						for (int i2 = 0; i2 < 4; ++i2) {
							if (slot_active[i2]) {
								current_turn = i2;
								break;
							}
						}
					}
				}
			}

		}
		else if (current_turn >= 0) {
			// Enemy turn

			int tmp_active_ally[4]{};
			int current_idx = 0;
			for (int i = 4; i < 8; ++i) {
				if (slot_active[i]) {
					tmp_active_ally[current_idx] = i;
					current_idx++;
				}
			}
			int tmp_rand_ally = tmp_active_ally[Common::rand_int(0, current_idx - 1)];

			for (int i = 3; i >= 0; --i) {
				if (enemy[current_turn].get_skill_list(i).cost <= enemy[current_turn].get_stats("cur_mp") && enemy[current_turn].get_skill_list(i).active) {
					if (enemy[current_turn].get_skill_list(i).skill_type == 'A') {
						enemy[current_turn].set_stats("attack", enemy[current_turn].get_stats("attack") + enemy[current_turn].get_skill_list(i).power);
					}
					else if (enemy[current_turn].get_skill_list(i).skill_type == 'H') {
						enemy[current_turn].set_stats("cur_health", enemy[current_turn].get_stats("cur_health") + enemy[current_turn].get_skill_list(i).power);
						if (enemy[current_turn].get_stats("cur_health") > enemy[current_turn].get_stats("max_health"))
							enemy[current_turn].set_stats("cur_health", enemy[current_turn].get_stats("max_health"));
					}
					else {
						switch (tmp_rand_ally) {
							case 4:
								swordsman.set_stats("cur_health", swordsman.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								if (swordsman.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(0, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 5:
								elf.set_stats("cur_health", elf.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								if (elf.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(25, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 6:
								mage.set_stats("cur_health", mage.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								if (mage.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(50, i2);
										std::cout << "                         ";
									}
								}
								break;
							case 7:
								assassin.set_stats("cur_health", assassin.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
								if (assassin.get_stats("cur_health") <= 0) {
									for (int i2 = 15; i2 < 26; ++i2) {
										Common::set_cursor(75, i2);
										std::cout << "                         ";
									}
								}
								break;
						}
					}
					enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);
					break;
				}
			}

			for (int i = 0; i < 4; ++i)
				slot_active[i] = (enemy[i].get_name() != "" && enemy[i].get_stats("cur_health") > 0);
			slot_active[4] = (swordsman.get_stats("cur_health") > 0);
			slot_active[5] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
			slot_active[6] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
			slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

			Common::cursor_vis(false);
			if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
				// Enemy all dead

				if (id == "ambush") {

					system("cls");

					Common::write_ani("You've gotten through your first battle! Just be careful, though. If your HP reaches ZERO, you die.\n\n"
									  "However, for this BATTLE, and the next one, you can still progress with the story, regardless of whether you\n"
									  "win or lose. Afterwards, it's an instant GAME OVER.\n\n"
									  "Also, since your allies' MP cannot be recovered, any buffs received during BATTLEs will be retained even\n"
									  "after a BATTLE ends.\n\n"
									  "Now that you've gotten the basics of BATTLE, you'll be on your own from here on out! Good luck!\n\n");

					Common::any_key_press("Press any key to continue");

					story.winElora();
					swordsman.set_stats("cur_health", swordsman.get_stats("max_health"));
				}
				else if (id == "bandit_1") {
					story.recruitElora();
				}
				else if (id == "bandit_2") {
					if (elf.get_stats("cur_health") <= 0 && mage.get_stats("cur_health") <= 0) {
						story.defeatBandits_oriAndElrDead();
					}
					else if (elf.get_stats("cur_health") <= 0) {
						story.recruitOrion_eloraDead();
					}
					else if (mage.get_stats("cur_health") <= 0) {
						story.defeatBandits_orionDead();
					}
					else {
						story.recruitOrion_main();
					}
				}
				else if (id == "dun_f1") {
					story.excalibur_defeatedSkels();
				}
				else if (id == "dun_f3") {
					story.excalibur_giantDefeated();
				}
				else if (id == "dkc_1") {
					story.DKC_floor1Complete();
				}
				else if (id == "dkc_2") {
					story.DKC_floor2Complete();
				}
				else if (id == "dkc_3") {
					if ((slot_active[5] && slot_active[6]) || (slot_active[5] && slot_active[6] && slot_active[7])) {
						// player, orion and elora are alive / player, orion, elora, blaise are alive
						story.defeatDK_main();
						if (slot_active[7]) {
							story.blaiseBetrayal_orionAlive();
							story.defeatBlaise_main();
						}
						story.ending_main();
					}
					else if (slot_active[7]) {
						// only player and blaise are alive (choice input after this)
						story.defeatDK_blaiseOnly();
					}
					else if (slot_active[6] || (slot_active[6] && slot_active[7])) {
						// player and orion / player, orion and blaise alive
						story.defeatDK_eloraDead();
						if (slot_active[7]) {
							story.blaiseBetrayal_orionAlive();
							story.defeatBlaise_eloraDead();
						}
						story.ending_partyMemDead();
					}
					else if (slot_active[5] || (slot_active[5] && slot_active[7])) {
						// player and elora / player, elora and blaise alive
						story.defeatDK_orionDead();
						if (slot_active[7]) {
							story.blaiseBetrayal_orionDead();
							story.defeatBlaise_orionDead();
						}

						story.ending_partyMemDead();
					}
					else {
						// only player is alive
						story.defeatDK_playerOnly();
						story.ending_playerOnly();
					}
				}
				ret = true;

				break;
			}
			else if (!slot_active[4]) {

				if (id == "bandit_1") {

					story.recruitElora_loseBandits();

				}
				else if (id == "bandit_2" || id == "dun_f1" || id == "dun_f3" || id == "dkc_1" || id == "dkc_2") {

					if (slot_active[5] || slot_active[6] || slot_active[7])
						story.gameOver_playerDead();
					else
						story.gameOver_everyoneDead();

				}
				else {
					story.gameOver_everyoneDead();
				}
				ret = false;

				break;
			}

			int tmp_active_enemy[4]{};
			current_idx = 0;
			for (int i = 0; i < 4; ++i) {
				if (slot_active[i]) {
					tmp_active_enemy[current_idx] = i;
					current_idx++;
				}
			}
			for (int i = 0; i < current_idx; ++i) {
				if (tmp_active_enemy[i] == current_turn && i < current_idx - 1) {
					current_turn = tmp_active_enemy[i + 1];
					break;
				}
				else if (tmp_active_enemy[i] == current_turn && i == current_idx - 1) {
					for (int i2 = 4; i2 < 8; ++i2) {
						if (slot_active[i2]) {
							current_turn = i2;
							break;
						}
					}
				}
			}

			Sleep(700);
		}

		Common::set_cursor(47, 28);
		std::cout << " ";
	}
	return ret;
}