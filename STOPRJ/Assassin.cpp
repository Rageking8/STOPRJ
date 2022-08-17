#include "Assassin.h"

Assassin::Assassin()
{
	set_name("Mage");
	set_stats("cur_health", 70);
	set_stats("max_health", 70);
	set_stats("cur_mp", 70);
	set_stats("max_mp", 70);

	init_skill("danger_poke", "strength_dart", "bomb", "backstab");
}

Assassin::~Assassin()
{
}
