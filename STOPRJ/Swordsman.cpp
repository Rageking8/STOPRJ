#include "Swordsman.h"
#include "Common.h"

Swordsman::Swordsman()
{
	int temp_health = Common::rand_int(100, 150);
	int temp_mana = Common::rand_int(30, 50);
	set_stats("cur_health", temp_health);
	set_stats("max_health", temp_health);
	set_stats("cur_mp", temp_mana);
	set_stats("max_mp", temp_mana);

	recruited = true;

	init_skill("slash", "fire_slash", "taunt", "spiral_spin");
}

Swordsman::~Swordsman()
{
}
