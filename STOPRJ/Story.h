#pragma once

class Story
{
public:
	void prologue();
	void foundCart(bool coin);

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
	void defeatDK_blaiseOnly(); // player and blaise are alive
	void killBlaise_blaiseOnly();
	void forgiveBlaise_blaiseOnly();

	void defeatDK_eloraDead(); // player and orion are alive
	void defeatDK_orionDead(); // player, elora and blaise are alive
	void defeatDK_playerOnly();

	void blaiseBetrayal_main();
	void blaiseBetrayal_orionDead(); // only happens if player, elora and blaise are alive
	void defeatBlaise_main();
	void defeatBlaise_orionDead();
	void defeatBlaise_eloraDead();
	void defeatBlaise_othersDead();

	void ending_main(); // player, orion and elora are alive
	void ending_partyMemDead(); // player and orion or elora are alive
	void ending_playerOnly(); // only player is alive
	void ending_blaiseAlive(); // player and blaise are alive, but orion and elora are dead

	void gameOver_playerDead(); // if player dies AND there are remaining party members alive
	void gameOver_everyoneDead(); // if everyone in the party dies INCLUDING the player

	// caershire magic school side quest: find the missing students
	// reward: attack-boosting equipment + 2 MP potions + 20 gold
	void magicSchool_start();
	void magicSchool_accept(); // "i can help you look for them"
	void magicSchool_decline(); // "that's concerning"
	void magicSchool_student1Found(); //student 1 is lost
	void magicSchool_student2Trapped(); //student 2 is trapped in a cage
	void magicSchool_student2Found();
	void magicSchool_student3Found(); //student 3 forgot they had to go back
	void magicSchool_inProgress();
	void magicSchool_complete();

	// kingdom of elves side quest: elora's bow
	// reward: forest bow (+10 attack)
	void KoE_start();
	void KoE_accept(); // "i could help you find them"
	void KoE_decline(); // "good luck!"
	void KoE_inProgress();
	void KoE_complete();

	// find excalibur
	void excalibur_start();
	void excalibur_success(); 
	void excalibur_failure(); 

	// caershire npc interactions
	void npc1(); // house
	void npc2(); // house
	void npc3(); // house
	void npc4(); // entrance
	void npc5(); // middle
	void npc6(); // fountain
	void npc7(); // grand master mage (pendolf) after completing side quest
	void npc8_9_10(); // training (will not respond)

	// kingfom of elves npc interactions
	void npc11(); // fountain
	void npc12(); // house
	void npc13(); // somewhere else

	void treasureRoomHint();
};

