#include "Swordsman.h"
#include "Common.h"

Swordsman::Swordsman()
{
	int temp_health = Common::rand_int(100, 150);
	set_stats("cur_health", temp_health);
	set_stats("max_health", temp_health);
	set_stats("cur_mp", 30);
	set_stats("max_mp", 30);

	recruited = true;

	init_skill("slash", "fire_slash", "taunt", "spiral_spin");
}

Swordsman::~Swordsman()
{
}
