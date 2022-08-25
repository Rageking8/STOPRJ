#include "Assassin.h"

Assassin::Assassin()
{
	set_name("Assassin");
	set_stats("cur_health", 100);
	set_stats("max_health", 100);
	set_stats("cur_mp", 70);
	set_stats("max_mp", 70);

	init_skill("dagger_poke", "strength_dart", "bomb", "backstab");
}

Assassin::~Assassin()
{
}
