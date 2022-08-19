#pragma once

class Story
{
public:
	void prologue(); // after starting the game
	void foundCart(bool coin); // interact

	void meetElora(); // elf ambush
	void winElora();
	void loseElora();
	void eloraQuest_inProgress(); // talking to elora before bandits are defeated
	void recruitElora(); // after defeating the bandits on the path

	void outsideOrionResidence(); // interacting with orion's door
	void meetOrion(); // encountering orion on the path from caershire to the bandit camp
	void recruitOrion_main(); // defeat bandits
	void recruitOrion_eloraDead(); // defeat bandits but elora dies

	void meetBlaise_main(); // entering treasure room if all party members are alive (choice input after this)
	void killBlaise_main();
	void recruitBlaise_main();

	void meetBlaise_eloraDead(); // entering treasure room if elora is dead: blaise dies to orion after he enters
	void meetBlaise_orionDead(); // entering treasure room if orion is dead: forced to recruit blaise
	void meetBlaise_partyDead(); // entering treasure room if orion AND elora are dead: forced to recruit blaise

	void beforeFightDK_main(); // before entering demon king's throne room
	void defeatDK_main();

	void defeatDK_blaiseOnly(); // only player and blaise are alive (choice input after this)
	void killBlaise_blaiseOnly();
	void forgiveBlaise_blaiseOnly();

	void defeatDK_eloraDead(); // only player and orion are alive
	void defeatDK_orionDead(); // only player, elora and blaise are alive
	void defeatDK_playerOnly(); // only player is alive

	void blaiseBetrayal_main(); // every party member is alive
	void blaiseBetrayal_orionDead(); // only player, elora and blaise are alive
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
	// reward: armour + 2 MP potions + 20 gold
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

	// Find excalibur mini-event
	void excalibur_start(); // interact with rock
	void excalibur_success();
	void excalibur_failure();

	// Caershire npc interactions
	void npc1(); // house
	void npc2(); // house
	void npc3(); // house
	void npc4(); // entrance
	void npc5(); // middle
	void npc6(); // fountain
	void npc7(); // grand master mage (pendolf) after completing side quest
	void npc8_9_10(); // training (will not respond)

	// kingdom of elves npc interactions
	void npc11(); // fountain
	void npc12(); // house
	void npc13(); // near the path to caershire (mage town)

	void treasureRoomHint();
};