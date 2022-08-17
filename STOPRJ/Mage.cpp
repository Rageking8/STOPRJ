#include "Mage.h"

Mage::Mage()
{
	set_name("Mage");
	set_stats("cur_health", 50);
	set_stats("max_health", 50);
	set_stats("cur_mp", 150);
	set_stats("max_mp", 150);

	init_skill("arcane_bullet", "healing", "enchant", "fireball");
}

Mage::~Mage()
{
}
