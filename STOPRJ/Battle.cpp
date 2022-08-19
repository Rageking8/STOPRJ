#include "Game.h"
#include "Common.h"
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

void Game::start_battle(std::string id)
{
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

	bool slot_active[8]{};

	for (int i = 0; i < 4; ++i) {
		if (enemy[i].get_name() != "") {
			slot_active[i] = true;
		}
	}
	slot_active[4] = (swordsman.get_stats("cur_health") > 0);
	slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
	slot_active[6] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
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
				if (current_turn == i)
					SetConsoleTextAttribute(h, 0x09);

				Common::set_cursor(i * 25, 0);
				std::cout << "|======================| ";
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
						std::cout << "| " << i2 + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
					}
					else {
						std::cout << "|                      | ";
					}
				}

				Common::set_cursor(i * 25, 10);
				std::cout << "|======================| ";

				if (current_turn == i)
					SetConsoleTextAttribute(h, 0x07);
			}
		}

		if (slot_active[4]) {
			if (current_turn == 4)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(0, 15);
			std::cout << "|======================| ";
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
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(0, 25);
			std::cout << "|======================| ";

			if (current_turn == 4)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[5]) {
			if (current_turn == 5)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(25, 15);
			std::cout << "|======================| ";
			Common::set_cursor(25, 16);
			std::cout << "| " << mage.get_name() << Common::mul_txt(" ", 21 - mage.get_name().length()) << "| ";
			Common::set_cursor(25, 17);
			std::cout << "| Attack : " << mage.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(mage.get_stats("attack"))) << "| ";
			Common::set_cursor(25, 18);
			std::cout << "| Health : " << mage.get_stats("cur_health") << " / " << mage.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(mage.get_stats("cur_health")) + 3 + Common::int_len(mage.get_stats("max_health")))) << "| ";
			Common::set_cursor(25, 19);
			std::cout << "| MP : " << mage.get_stats("cur_mp") << " / " << mage.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(mage.get_stats("cur_mp")) + 3 + Common::int_len(mage.get_stats("max_mp")))) << "| ";
			Common::set_cursor(25, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(25, 21 + i);
				if (mage.get_skill_list(i).active) {
					std::string tmp_skill_name = mage.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(25, 25);
			std::cout << "|======================| ";

			if (current_turn == 5)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[6]) {
			if (current_turn == 6)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(50, 15);
			std::cout << "|======================| ";
			Common::set_cursor(50, 16);
			std::cout << "| " << elf.get_name() << Common::mul_txt(" ", 21 - elf.get_name().length()) << "| ";
			Common::set_cursor(50, 17);
			std::cout << "| Attack : " << elf.get_stats("attack") << Common::mul_txt(" ", 12 - Common::int_len(elf.get_stats("attack"))) << "| ";
			Common::set_cursor(50, 18);
			std::cout << "| Health : " << elf.get_stats("cur_health") << " / " << elf.get_stats("max_health") << Common::mul_txt(" ", 12 - (Common::int_len(elf.get_stats("cur_health")) + 3 + Common::int_len(elf.get_stats("max_health")))) << "| ";
			Common::set_cursor(50, 19);
			std::cout << "| MP : " << elf.get_stats("cur_mp") << " / " << elf.get_stats("max_mp") << Common::mul_txt(" ", 16 - (Common::int_len(elf.get_stats("cur_mp")) + 3 + Common::int_len(elf.get_stats("max_mp")))) << "| ";
			Common::set_cursor(50, 20);
			std::cout << "|                      | ";

			for (int i = 0; i < 4; ++i) {
				Common::set_cursor(50, 21 + i);
				if (elf.get_skill_list(i).active) {
					std::string tmp_skill_name = elf.get_skill_list(i).name;
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(50, 25);
			std::cout << "|======================| ";

			if (current_turn == 6)
				SetConsoleTextAttribute(h, 0x07);
		}

		if (slot_active[7]) {
			if (current_turn == 7)
				SetConsoleTextAttribute(h, 0x09);

			Common::set_cursor(75, 15);
			std::cout << "|======================| ";
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
					std::cout << "| " << i + 1 << " " << tmp_skill_name << Common::mul_txt(" ", 19 - tmp_skill_name.length()) << "| ";
				}
				else {
					std::cout << "|                      | ";
				}
			}

			Common::set_cursor(75, 25);
			std::cout << "|======================| ";

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

						(current_turn == 5 && (!mage.get_skill_list(std::stoi(skill_input) - 1).active || mage.get_stats("cur_mp") < mage.get_skill_list(std::stoi(skill_input) - 1).cost)) ||

						(current_turn == 6 && (!elf.get_skill_list(std::stoi(skill_input) - 1).active || elf.get_stats("cur_mp") < elf.get_skill_list(std::stoi(skill_input) - 1).cost)) ||

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
				else if (current_turn == 6) {
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
					slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
					slot_active[6] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
					slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

					if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
						// Enemy all dead

						if (id == "ambush") {
							story.winElora();
						}
						//system("cls");
						//std::cout << "You Won";
						break;
					}
					else if (!slot_active[4] && !slot_active[5] && !slot_active[6] && !slot_active[7]) {
						// Ally all dead

						if (id == "ambush") {
							story.loseElora();
						}
						//system("cls");
						//std::cout << "You lose";
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
							enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

							if (swordsman.get_stats("cur_health") <= 0) {
								for (int i2 = 15; i2 < 26; ++i2) {
									Common::set_cursor(0, i2);
									std::cout << "                         ";
								}
							}
							break;
						case 5:
							mage.set_stats("cur_health", mage.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
							enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

							if (mage.get_stats("cur_health") <= 0) {
								for (int i2 = 15; i2 < 26; ++i2) {
									Common::set_cursor(25, i2);
									std::cout << "                         ";
								}
							}
							break;
						case 6:
							elf.set_stats("cur_health", elf.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
							enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

							if (elf.get_stats("cur_health") <= 0) {
								for (int i2 = 15; i2 < 26; ++i2) {
									Common::set_cursor(50, i2);
									std::cout << "                         ";
								}
							}
							break;
						case 7:
							assassin.set_stats("cur_health", assassin.get_stats("cur_health") - enemy[current_turn].get_stats("attack") - enemy[current_turn].get_skill_list(i).power);
							enemy[current_turn].set_stats("cur_mp", enemy[current_turn].get_stats("cur_mp") - enemy[current_turn].get_skill_list(i).cost);

							if (assassin.get_stats("cur_health") <= 0) {
								for (int i2 = 15; i2 < 26; ++i2) {
									Common::set_cursor(75, i2);
									std::cout << "                         ";
								}
							}
							break;
						}
					}
					break;
				}
			}

			for (int i = 0; i < 4; ++i)
				slot_active[i] = (enemy[i].get_name() != "" && enemy[i].get_stats("cur_health") > 0);
			slot_active[4] = (swordsman.get_stats("cur_health") > 0);
			slot_active[5] = (mage.get_recruited() && (mage.get_stats("cur_health") > 0));
			slot_active[6] = (elf.get_recruited() && (elf.get_stats("cur_health") > 0));
			slot_active[7] = (assassin.get_recruited() && (assassin.get_stats("cur_health") > 0));

			if (!slot_active[0] && !slot_active[1] && !slot_active[2] && !slot_active[3]) {
				// Enemy all dead

				if (id == "ambush") {
					story.winElora();
				}
				//system("cls");
				//std::cout << "You Won";
				break;
			}
			else if (!slot_active[4] && !slot_active[5] && !slot_active[6] && !slot_active[7]) {
				// Ally all dead

				if (id == "ambush") {
					story.loseElora();
				}
				//system("cls");
				//std::cout << "You lose";
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

			Sleep(1000);
		}

		Common::set_cursor(47, 28);
		std::cout << " ";
	}
}