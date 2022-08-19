#include "Elf.h"

Elf::Elf()
{
	set_name("Elf");
	set_stats("cur_health", 90);
	set_stats("max_health", 90);
	set_stats("cur_mp", 90);
	set_stats("max_mp", 90);

	init_skill("shoot_arrow", "raining_arrow", "piercing_arrow", "bullet_arrow");
}

Elf::~Elf()
{
}
