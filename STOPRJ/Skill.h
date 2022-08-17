#pragma once
#include <string>

class Skill
{
public:
	Skill();
	~Skill();

	struct skill_data {
		std::string name = "";
		int power{};
		int cost{};
		bool active{};
		char skill_type = ' ';
	};

	void init_skill(std::string s1, std::string s2, std::string s3, std::string s4);
	skill_data get_skill_list(int idx);

protected:
	skill_data skill_list[4];

private:
	skill_data get_skill(std::string skill_name);
};

