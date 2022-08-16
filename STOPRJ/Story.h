#pragma once

class Story
{
public:
	void prologue();
	void foundCart();

	void meetElora();
	void winElora();
	void loseElora();
	void recruitElora();

	void outsideOrionResidence();
	void meetOrion();
	void recruitOrion_main();
	void recruitOrion_eloraDead();

	void meetBlaise_main();
	void killBlaise_main();
	void recruitBlaise_main();
	void meetBlaise_eloraDead();
	void meetBlaise_orionDead();
	void meetBlaise_partyDead();

	void beforeFightDK_main();
	void defeatDK_main();
	void defeatDK_blaiseOnly();
	void killBlaise_blaiseOnly();
	void forgiveBlaise_blaiseOnly();

	void blaiseBetrayal_main();
	void defeatBlaise_main();
	void blaiseBetrayal_orionDead();
	void defeatBlaise_orionDead();

	void ending_main(); // player, orion and elora are alive
	void ending_partyMemDead(); // player and orion or elora are alive, OR only player is alive
	void ending_blaiseAlive(); // player and blaise are alive, but orion and elora are dead

	void gameOver_playerDead(); // if player dies AND there are remaining party members alive
	void gameOver_everyoneDead(); // if everyone in the party dies INCLUDING the player
};

