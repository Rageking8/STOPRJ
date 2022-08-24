#include "Skill.h"
#include "Common.h"


Skill::Skill()
{

}

Skill::~Skill()
{
}

void Skill::init_skill(std::string s1, std::string s2, std::string s3, std::string s4)
{
	skill_list[0] = get_skill(s1);
	skill_list[1] = get_skill(s2);
	skill_list[2] = get_skill(s3);
	skill_list[3] = get_skill(s4);
}

Skill::skill_data Skill::get_skill_list(int idx)
{
	return (idx >= 0 && idx <= 3) ? skill_list[idx] : skill_data{};
}

void Skill::print_color_name(int idx)
{
	switch (get_skill_list(idx).skill_type) {
		case 'D' :
			Common::color_print(0x0C, get_skill_list(idx).name);
			break;
		case 'A':
			Common::color_print(0x09, get_skill_list(idx).name);
			break;
		case 'H':
			Common::color_print(0x0A, get_skill_list(idx).name);
			break;
	}
}

void Skill::set_active(int idx, bool new_b)
{
	if (idx >= 0 && idx <= 3) {
		skill_list[idx].active = new_b;
	}
}

Skill::skill_data Skill::get_skill(std::string skill_name)
{
	if (skill_name == "slash")
		return skill_data{ "Slash", 5, 0, true, 'D' };
	else if (skill_name == "fire_slash")
		return skill_data{ "Fire Slash", 10, 5, true, 'D' };
	else if (skill_name == "taunt")
		return skill_data{ "Taunt", 5, 10, false, 'A' };
	else if (skill_name == "spiral_spin")
		return skill_data{ "Spiral Spin", 60, 15, false, 'D' };
	else if (skill_name == "arcane_bullet")
		return skill_data{ "Arcane Bullet", 3, 0, true, 'D' };
	else if (skill_name == "healing")
		return skill_data{ "Healing", 50, 20, true, 'H' };
	else if (skill_name == "enchant")
		return skill_data{ "Enchant", 10, 30, false, 'A' };
	else if (skill_name == "fireball")
		return skill_data{ "Fireball", 100, 100, false, 'D' };
	else if (skill_name == "shoot_arrow")
		return skill_data{ "Shoot Arrow", 5, 0, true, 'D' };
	else if (skill_name == "raining_arrow")
		return skill_data{ "Raining Arrow", 10, 5, true, 'D' };
	else if (skill_name == "piercing_arrow")
		return skill_data{ "Piercing Arrow", 30, 10, false, 'D' };
	else if (skill_name == "bullet_arrow")
		return skill_data{ "Bullet Arrow", 60, 45, false, 'D' };
	else if (skill_name == "dagger_poke")
		return skill_data{ "Dagger Poke", 5, 0, true, 'D' };
	else if (skill_name == "strength_dart")
		return skill_data{ "Strength Dart", 10, 20, true, 'A' };
	else if (skill_name == "bomb")
		return skill_data{ "Bomb", 45, 15, false, 'D' };
	else if (skill_name == "backstab")
		return skill_data{ "Backstab", 125, 35, false, 'D' };
	else if (skill_name == "headbutt")
		return skill_data{ "Headbutt", 10, 10, true, 'D' };
	else if (skill_name == "shield_bash")
		return skill_data{ "Shield Bash", 15, 15, false, 'D' };
	else if (skill_name == "arm_slap")
		return skill_data{ "Arm Slap", 30, 15, false, 'D' };
	else if (skill_name == "demon_slash")
		return skill_data{ "Demon Slash", 30, 0, true, 'D' };
	else if (skill_name == "demon_eye_beam")
		return skill_data{ "Demon Eye Beam", 90, 20, true, 'D' };
	else if (skill_name == "demon_strength")
		return skill_data{ "Demon Strength", 10, 40, false, 'A' };
	else if (skill_name == "fire_breath")
		return skill_data{ "Fire Breath", 100, 100, false, 'D' };
	else if (skill_name == "demon_punch")
		return skill_data{ "Demon Punch", 40, 0, true, 'D' };
	else if (skill_name == "long_live_the_king")
		return skill_data{ "Long live The King", 50, 20, true, 'H' };
	else if (skill_name == "demon_summon")
		return skill_data{ "Demon Summon", 20, 40, false, 'A' };
	else if (skill_name == "hellfire")
		return skill_data{ "Hellfire", 120, 100, false, 'D' };
	else
		return skill_data{};
}
