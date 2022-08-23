#pragma once
#include <string>

class Story
{
public:
	void set_player_name(std::string inp);

	void after_start_menu(); // after player inputs their name
	void prologue(); // after interacting with the emperor
	void foundCart(bool coin); // interact with the cart

	void meetElora(); // elf ambush
	void winElora();
	void eloraQuest_inProgress(); // talking to elora before bandits are defeated
	void recruitElora(); // after defeating the bandits on the path
	void recruitElora_loseBandits(); // losing to the bandits on the path

	void meetOrion_winBandits(); // interacting with orion's house (defeated bandits)
	void meetOrion_loseBandits(); // encountering orion on the path from caershire to the bandit camp (lose to bandits)
	void recruitOrion_main(); // bandits defeated
	void recruitOrion_eloraDead(); // bandits defeated but elora dies
	void defeatBandits_orionDead(); // bandits defeated but orion dies
	void defeatBandits_oriAndElrDead(); // bandits defeated but orion AND elora die

	void meetBlaise_main(); // entering treasure room if all party members are alive
	void killBlaise();
	void recruitBlaise();

	void meetBlaise_eloraDead(); // entering treasure room if elora is dead
	void meetBlaise_orionDead(); // entering treasure room if orion is dead: forced to recruit blaise
	void meetBlaise_partyDead(); // entering treasure room if orion AND elora are dead: forced to recruit blaise

	void beforeFightDK_main(); // before entering demon king's throne room
	void defeatDK_main(); // player, orion and elora are alive

	void defeatDK_blaiseOnly(); // only player and blaise are alive (choice input after this)
	void killBlaise_blaiseOnly();
	void forgiveBlaise_blaiseOnly();

	void defeatDK_eloraDead(); // player and orion are alive
	void defeatDK_orionDead(); // player and elora are alive
	void defeatDK_playerOnly(); // only player is alive

	void blaiseBetrayal_orionAlive(); // check if player, orion and blaise are alive
	void blaiseBetrayal_orionDead(); // check if player, elora AND blaise are alive
	void defeatBlaise_main(); // player, orion and elora are alive after blaise is defeated
	void defeatBlaise_orionDead(); // player and elora are alive after blaise is defeated
	void defeatBlaise_eloraDead(); // player and orion are alive after blaise is defeated
	void defeatBlaise_othersDead(); // occurs if orion and/or elora (depending on whether they're alive after DK is defeated) die during the fight with blaise

	void ending_main(); // player, orion and elora are alive
	void ending_partyMemDead(); // player and orion or elora are alive
	void ending_playerOnly(); // only player is alive
	void ending_blaiseAlive(); // player and blaise are alive, but orion and elora are dead

	void gameOver_playerDead(); // if player dies AND there are remaining party members alive
	void gameOver_everyoneDead(); // if everyone in the party dies INCLUDING the player

	// caershire magic school side quest: find the missing students
	// reward: armour + 2 MP potions + 20 gold
	void magicSchool_start(); // interact with grand master mage pendolf
	void magicSchool_accept(); // "i can help you look for them."
	void magicSchool_decline(); // "that's concerning."
	void magicSchool_student1Found(); //student 1 is lost
	void magicSchool_student2Trapped(); // student 2 is trapped in a cage
	void magicSchool_student2Found(); // after defeating the bandit
	void magicSchool_student3Found(); //student 3 got distracted by their garden
	void magicSchool_inProgress(); // interacting with pendolf before all 3 students are found
	void magicSchool_complete(); // interacting with pendolf once all 3 students are found

	// kingdom of elves side quest: find jade
	// reward: sword
	void KoE_start();
	void KoE_accept(); // "i could help you find them."
	void KoE_decline(); // "good luck!"
	void KoE_inProgress();
	void KoE_complete();

	// excalibur dungeon quest
	// reward: excalibur (+20 attack) (maybe "auto-equip"? like just add 20 attack points or something)
	void excalibur_floor1(); // player interacts with the bandits
	void excalibur_defeatedSkels();
	void excalibur_floor2(); // player tries to go through door without the key
	void excalibur_doorUnlocked(); // player has the key to the door
	void excalibur_floor3(); // player interacts with olaf the stone giant
	void excalibur_giantDefeated();
	void excalibur_completed(); // player interacts with the stone that has the excalibur

	// caershire (mage town) npc interactions
	void npc1(); // house
	void npc2(); // house
	void npc3(); // house
	void npc4(); // entrance to caershire
	void npc5(); // middle
	void npc6(); // fountain
	void npc7(); // grand master mage (pendolf) after completing side quest
	void npc8_9_10(); // training (will not respond)

	// kingdom of elves npc interactions
	void npc11(); // fountain
	void npc12(); // house
	void npc13(bool bandits); // near the path to caershire (mage town)

	// moris empire npc interactions
	void npc14(bool state); // boat
	void npc15_16(); // 2 npcs at the fountain (same dialogue)
	void npc17_18(); // 2 npcs gardening (same dialogue)
	void npc19_20(); // 2 npc guards (same dialogue)

	void treasureRoomHint();

private:
	std::string name;
};
