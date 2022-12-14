#pragma once
#include <string>

class Story
{
public:
	void set_player_name(std::string inp);

	void after_start_menu(); // after player talks to messenger
	void prologue(); // after interacting with the emperor
	void foundCart(bool coin); // interact with the cart

	void meetElora(); // elf ambush
	void winElora();
	void eloraQuest_inProgress(); // talking to elora before bandits are defeated
	void recruitElora(); // after defeating the bandits on the path
	void recruitElora_loseBandits(); // losing to the bandits on the path

	void meetOrion_winBandits(); // interacting with orion's house (defeated bandits)
	void enterCamp_winBandits(); // entering bandit camp after winning 1st bandit fight
	void interactWCampBandits_winBandits(); // interacting with bandits at camp after winning 1st bandit fight
	void enterCamp_loseBandits(); // entering bandit camp after losing 1st bandit fight
	void meetOrion_loseBandits(); // encountering orion on the path from caershire to the bandit camp (lose to bandits)
	void recruitOrion_main(); // bandits defeated
	void recruitOrion_eloraDead(); // bandits defeated but elora dies
	void defeatBandits_orionDead(); // bandits defeated but orion dies
	void defeatBandits_oriAndElrDead(); // bandits defeated but orion AND elora die

	bool meetBlaise_main(); // entering treasure room if all party members are alive
	void killBlaise();
	void recruitBlaise();

	bool meetBlaise_eloraDead(); // entering treasure room if elora is dead
	void meetBlaise_orionDead(); // entering treasure room if orion is dead: forced to recruit blaise
	void meetBlaise_partyDead(); // entering treasure room if orion AND elora are dead: forced to recruit blaise

	void DKC_floor1(); // encountering armoured skeletons
	void DKC_floor1Complete(); // defeat armoured skeletons
	void DKC_floor2(); // encountering demon + 2 armoured skeles
	void DKC_floor2Complete(); // defeat demon + armoured skeles
	void beforeFightDK_main(); // before entering demon king's throne room
	void defeatDK_main(); // player, orion and elora are alive

	void defeatDK_blaiseOnly(); // only player and blaise are alive (choice input after this)
	void killBlaise_blaiseOnly();
	void forgiveBlaise_blaiseOnly();

	void defeatDK_eloraDead(); // player and orion are alive
	void defeatDK_orionDead(); // player and elora are alive
	void defeatDK_playerOnly(); // only player is alive

	// caershire magic school side quest: find the missing students
	// reward: 2 vitality potions + 2 MP potions + 20 coins
	void magicSchool_start(); // interact with grand master mage pendolf
	void magicSchool_accept(); 
	void magicSchool_decline(); 
	void magicSchool_student1Found(); //student 1 is lost
	void magicSchool_student2Found(); // student 2 is in a cage; before obtaining the 60 coins in the bushes
	void magicSchool_student3Found(); //student 3 got distracted by their garden
	void magicSchool_inProgress(); // interacting with pendolf before all 3 students are found
	void magicSchool_complete(); // interacting with pendolf once all 3 students are found

	// Kingdom of elves side quest: find jade
	// reward: 2 attack potions
	void KoE_start(); // talk to aerith (npc12) in their house
	void KoE_accept(); 
	void KoE_decline(); 
	void KoE_inProgress(int count);
	void KoE_jadeFound(int count); // when player steps on specific blocks
	void KoE_complete();

	// excalibur dungeon quest
	// reward: excalibur (+20 attack) (maybe "auto-equip"? like just add 20 attack points or something)
	void excalibur_floor1Start(); // player enters the first floor
	void excalibur_floor1InteractWBones(); // player interacts with pile of bones
	void excalibur_defeatedSkels();
	void excalibur_lockedInFloor2(); // immediately after player enters floor 2
	void excalibur_floor2(); // player tries to go through door without the key
	void excalibur_foundKey();
	void excalibur_doorUnlocked(); // player has the key to the door
	void excalibur_floor3(); // player enters floor 3
	void excalibur_interactWOlaf(); // player interacts with the stone giant, triggers battle
	void excalibur_giantDefeated(); // player wins against stone giant
	void excalibur_completed(); // player interacts with the stone that has the excalibur

	// caershire (mage town) npc interactions
	void npc1(); // house
	void npc2(); // house
	void npc3(); // house
	void npc4(bool state); // entrance to caershire
	void npc5(); // middle
	void npc6(); // fountain
	void npc7(); // grand master mage (pendolf) after completing side quest
	void npc8_9_10(); // training (will not respond)

	// kingdom of elves npc interactions
	void npc11(); // fountain
	void npc12(); // house, after completing side quest
	void npc13(bool bandits); // near the path to caershire (mage town)

	// moris empire npc interactions
	void npc14(bool state); // boat FROM moris empire
	void npc15_16(); // 2 npcs at the fountain (same dialogue)
	void npc17_18(); // 2 npcs gardening (same dialogue)
	void npc19_20(); // 2 npc guards (same dialogue)
	void npc21(); // boat TO moris empire

	void beforeTalkingToMessenger(); // right after name input
	void boardBoat(); // player steps on the dock
	void banditTreasureRoomHint(int state); // hint to unlock bandits' treasure room
	void collectTreasure(); // player interacts with chests in the bandits' treasure room
	void excalibur_warning(); // warning note in floor 2
	void fairy_start(int coins); // interact with the fairy after the excalibur dungeon
	void fairy_recoverHP(); 
	void fairy_recoverMP();
	void fairy_notEnoughCoins(); // user inputs 1 or 2 but coins < 100
	void fairy_refuse(); 

	void ending_main(); // player, orion and elora are alive
	void ending_partyMemDead(); // player and orion or elora are alive
	void ending_playerOnly(); // only player is alive
	void ending_blaiseAlive(); // player and blaise are alive, but orion and elora are dead

	void blaiseBetrayal_orionAlive(); // check if player, orion and blaise are alive
	void blaiseBetrayal_orionDead(); // check if player, elora AND blaise are alive
	void defeatBlaise_main(); // player, orion and elora are alive after blaise is defeated
	void defeatBlaise_orionDead(); // player and elora are alive after blaise is defeated
	void defeatBlaise_eloraDead(); // player and orion are alive after blaise is defeated

	void gameOver_playerDead(); // if player dies AND there are remaining party members alive
	void gameOver_everyoneDead(); // if everyone in the party dies INCLUDING the player

private:
	std::string name;
};
