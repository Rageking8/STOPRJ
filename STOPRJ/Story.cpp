#include "Story.h"
#include "Common.h"
#include <string>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

void Story::set_player_name(std::string inp)
{
	name = inp;
}

void Story::after_start_menu()
{
	system("cls");
	Common::write_ani("To: Knight " + name + "\n\n"
					  "The Emperor has requested your attendance. Please head to the castle immediately\n"
					  "after receiving and opening this letter.\n\n");

	Common::color_print(0x09, "MESSENGER:\n");
	Common::write_ani("The castle's on the right side of the Empire, in case you're unaware.\n"
					  "If you ever get lost on the way, you can always have a look at your map by accessing the menu.\n"
					  "I'll be taking my leave now. Have a nice day.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::prologue()
{
	system("cls");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Knight " + name + ", I have a job for you.\n\n");

	const char* story_arr[]{
		"As you already know, our treasure has gone missing.\n"
		"I suspect the Demon King has something to do with this predicament.\n\n",

		"You are to defeat the Demon King and retrieve our stolen treasures.\n"
		"However, you need the help of three important people to succeed.\n\n",

		"First, seek out ELORA of the Kingdom of Elves.\n"
		"She is the leader of the elves, a very skilled marksman, and one of the most social\n"
		"people around. I'm sure you will get along well with her.\n\n",

		"Next, you need to locate Elder Mage ORION of Caershire.\n"
		"He is rather... reclusive, and stubborn, but his wisdom and experience may prove to be of use.\n\n",

		"The last person you need to recruit is a very strong assassin named BLAISE.\n"
		"Nobody has been able to find him these days, but I trust you can do it.\n\n",

		"You may begin your mission by going to the dock and boarding the boat to travel across the ocean\n"
		"to the Kingdom of Elves.\n\n"
	};

	for (const auto i : story_arr) {
		Common::color_print(0x0e, "EMPEROR:\n");
		Common::write_ani(i);
	}

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Good luck, " + name + ". I leave this paramount task in your capable hands.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::foundCart(bool coin)
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("There's a very damaged cart here...\n"
					  "Maybe I'll do a little digging and see if I can find anything.\n\n");

	if (coin)
		Common::write_ani("You dig through the cart and find 20 coins. Upon further investigation, you came to\n"
						  "the conclusion that it belongs to the elves.\n\n");
	else
		Common::write_ani("You dig through the cart, but find that it's empty as the cart has already been looted.\n"
						  "You confirm that it belongs to the elves.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("If the elves' cart is here, then that probably means the Kingdom of Elves is nearby, and\n"
					  "I'm on the right track. I wonder why the cart's in such bad shape, though...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetElora()
{
	system("cls");

	Common::write_ani("Just as you were about to set foot into the Kingdom of Elves,\n"
				  	  "an arrow comes flying towards you!\n\n"
					  "You narrowly dodge the arrow, and look up to see an army of elves aiming at you!\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("You dare to trespass on our land? What a foolish move.\n"
					  "I refuse to let our Kingdom be threatened by the likes of you!\n\n");
	
	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Wait! I'm not here to fight!\n\n"
					  "The Elves seem to have disregarded your claim, and are challenging you to a BATTLE!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::winElora()
{
	system("cls");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("No... I could not have been defeated by a mere bandit!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("That's what I'm trying to tell you, I'm not a bandit!\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("You aren't one of them? Well, that's... rather embarrassing.\n"
					  "As an apology, let us accompany you to our Kingdom so that you may recover after our fight.\n\n"
					  "The Elves bring you back to the Kingdom of Elves and provide you with medical assistance,\n"
					  "bringing you back to full health.\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("I believe I should formally introduce myself.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("My name is ELORA. I am the leader of the Kingdom of Elves.\n"
					  "I would like to extend my sincerest apologies for earlier. You see, our kingdom is currently\n"
					  "under threat from the bandits nearby, and I mistakenly assumed you were one of their allies.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Bandits? I could help you guys clear them out. You know, as thanks for patching me up and all.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("That would be much appreciated. Thank you for your kind offer.\n"
					  "I believe some of them were last seen west from here, on the path connecting\n"
					  "our kingdom and Caershire.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I would advise you to first pay a visit to our SHOP, and purchase some\n"
					  "equipment. It's the yellow building also to the west from here.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("The equipment they provide could help with defeating the bandits.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Got it, I'll do my best.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::eloraQuest_inProgress()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("The bandits were last seen west from here, on the path connecting\n"
					  "our kingdom and Caershire. Hopefully they are manageable for you.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I would advise you to first pay a visit to our SHOP, and purchase some\n"
					  "equipment. It's the yellow building also to the west from here.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("The equipment they provide could help with defeating the bandits.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::recruitElora()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Have the bandits been cleared out?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah, it took a while, but it's done.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("My sincerest thanks once again. At least some of my worries have been alleviated.\n"
					  "Is there, perhaps, any way I could show my gratitude?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Well, I'm on a quest to defeat the Demon King and retrieve my empire's treasure, and\n"
					  "you're one of the heroes I have to seek assistance from.\n"
					  "Would it be alright for you to join me in doing so?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("...I am rather worried of what would happen if I were to leave.\n"
					  "This seems to be rather important for you, though, so I could appoint someone to look\n"
					  "after the kingdom in my stead.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Very well, I shall accompany you on your journey. I do hope I can be of assistance.\n\n");

	Common::color_print(0x0a, "ELORA ");
	Common::write_ani("has been recruited to your party!\n\n"
					  "You have unlocked a new skill!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Alright! Well, our next stop is Caershire, so we should probably make our way there.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Is one of the other people you were tasked to seek the Elder Mage ORION?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah! I'm not sure where I can find him, though.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I happen to have some information that might be helpful to you. Elder Mage\n"
					  "ORION usually dons a blue starry robe.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("As far as I know, he rarely ever leaves his house, which is on the right side of town.\n"
					  "I have visited a few times to request his aid, so that is how I know.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("That could help, thanks!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::recruitElora_loseBandits()
{
	system("cls");

	Common::write_ani("You have been defeated by the bandits...\n\n"
					  ". . .\n\n"
					  "You wake up and find yourself in an unfamiliar location. You sit up and begin looking\n"
					  "around the room, wondering where you are.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Ah, you are finally awake. One of the elves found you knocked unconscious and brought\n"
					  "you here. Your injuries were rather severe, so I patched up I could.\n"
					  "Worry not, I have helped to clear out the remaining bandits.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Oh, thank you. I'm sorry for the trouble.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("It is all right. I should show my gratitude to you for trying, at least. Is there,\n"
					  "perhaps, anything I could do?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Well, I'm on a quest to defeat the Demon King and retrieve my empire's treasure, and\n"
					  "you're one of the heroes I have to seek assistance from.\n"
					  "Would it be alright for you to join me in doing so?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("...I am rather worried of what would happen if I were to leave.\n"
					  "This seems to be rather important for you, though, so I could appoint someone to look\n"
					  "after the kingdom in my stead.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Very well, I shall accompany you on your journey. I do hope I can be of assistance.\n\n");

	Common::color_print(0x0a, "ELORA ");
	Common::write_ani("has been recruited to your party!\n\n"
					  "You have unlocked a new skill!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Alright! Well, our next stop is Caershire, so we should probably make our way there.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Is one of the other people you were tasked to seek the Elder Mage ORION?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah! I'm not sure where I can find him, though.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I happen to have some information that might be helpful to you. Elder Mage\n"
					  "ORION usually dons a blue starry robe.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Last I've heard, he was tasked by the town's GRAND MASTER to clear out the bandit\n"
					  "camp north of Caershire. We could probably have a look there.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("That could help, thanks!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetOrion_winBandits()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Wait, you wish to ask Elder Mage ORION to join us, right?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yep! As I've said, he's one of the people I have to seek assistance from.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I do not know if you could convince him; he has a... distaste for being in a party.\n"
					  "All I know is that he had a harsh falling out with his party members at the time.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Oh. Well, there's no harm in trying, right?\n\n"
					  "You knock on the door, but you are met with no response.\n\n"
					  ". . .\n\n"
					  "Suddenly, the door opens and you see a grumpy-looking old man with a blue starry robe.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Hi! You're... uh, Elder Mage ORION, right?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Just ORION will do. Now what is it? This better be important, I'm busy with preparations\n"
					  "right now.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Um... Could we possibly help out with that?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Fine. I have to defeat some bandits at the camp north from here, but I was told not to do it alone.\n"
					  "You guys can join me, or whatever.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Great! Let's go, then!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetOrion_loseBandits()
{
	system("cls");

	Common::write_ani("Your party arrives at a bandit camp, and you notice an old man with a blue starry\n"
					  "robe fighting against a group of bandits.\n"
					  "Based on ELORA's description, you come to the conclusion that the old man is ORION.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Isn't that him? What's he doing fighting the bandits on his own?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("He is seriously injured, and bleeding! We must provide assistance as soon as possible!\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Stay back! I don't need any help, this is *my* job to do!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("But you're using up so much mana! Won't this have adverse effects on your body?\n"
					  "At least let us handle some of these guys!\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Darned kids, I swear... Fine, I'll let you two help out.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::recruitOrion_main()
{
	system("cls");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Thanks for the help, I guess.\n"
					  "You two came all the way here to find me, I assume. What do you want?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Well, I'm on a quest to defeat the Demon King, and you're one of the people I\n"
					  "was tasked to seek out.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani(name + ", I do not think you should--\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I might as well join you. It's the least I can do since you helped me out with those bandits.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Wait, really? I thought you hated the idea of being in a party.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("You're right. But I'm only doing this because I have to repay you for getting rid of those bandits.\n"
					  "Even though I'd rather not join you guys, I'm a man of my word.\n\n");

	Common::color_print(0x0d, "ORION ");
	Common::write_ani("has been recruited to your party!\n\n"
					  "You have unlocked a new skill!\n\n"
					  "Suddenly, you hear the gate to the bandit camp close behind you!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Drat! How are we gonna get out of here?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("We should look around the camp and see if there is a way for us to leave this place.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::recruitOrion_eloraDead()
{
	system("cls");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Thanks for the help, I guess. And uh, sorry about your friend.\n"
					  "You came all the way here to find me, I assume. What do you want?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Uh... I'm on a quest to defeat the Demon King, and you're one of the people I\n"
					  "was tasked to seek out.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I'll join you. It's the least I can do since you helped me out with those bandits.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Huh? Don't you hate the idea of being in a party?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I do. But I'm only doing this because I have to repay you for getting rid of those bandits.\n"
					  "Even though I'd rather not join you, I'm a man of my word.\n\n");

	Common::color_print(0x0d, "ORION ");
	Common::write_ani("has been recruited to your party!\n\n"
					  "You have unlocked a new skill!\n\n"
					  "Suddenly, you hear the gate to the bandit camp close behind you!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Drat! How are we gonna get out of here?\n\n");

	Common::color_print(0x0a, "ORION:\n");
	Common::write_ani("There's gotta be *something* that can help us leave this place. Let's have a look around the camp.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBandits_orionDead()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Orion, he...\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("How unfortunate... May he rest in peace, wherever he may be.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah, I hope so, too.\n"
					  "We should probably leave and try to find out where our last party member might be.\n\n"
					  "Right as you turn around, the gate to the bandit camp closes in front of your eyes!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Drat! How are we gonna get out of here?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("We should look around the camp and see if there is a way for us to leave this place.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBandits_oriAndElrDead()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Oh... I wasn't expecting this.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I should probably leave and try to find out where BLAISE might be.\n\n"
					  "Right as you turn around, the gate to the bandit camp closes in front of your eyes!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Drat! How am I gonna get out of here?\n"
					  "Guess I'll look around the camp and see if there's a way to leave this place.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetBlaise_main()
{
	system("cls");

	Common::write_ani("Immediately after opening the door to the bandits' treasure room, ORION recognises the figure\n"
					  "in front of your party.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Wait a minute. I know who you are!\n"
					  "BLAISE! You were the last person I wanted to see here!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh my, we meet again, ORION. Thanks for unlocking the room for me.\n\n"
					  "ORION looks behind BLAISE and notices that most of the treasure seems to be missing.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("No... you're doing the exact same thing you've done before! Taking everything and causing\n"
					  "discord and chaos within a group!\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Is... Is *he* why you are so against the idea of joining a party?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Yes! He caused my brother's death AND my entire party at the time to fall out! I'll bet\n"
					  "he's trying to make those bandits -- his 'allies' -- suffer the same fate!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh? I have no idea what you're talking about; I'm just taking what belongs to me.\n"
					  "I provided these guys with my strength, so it's only fair I take what I deserve, no?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani(name + "! I refuse to stand for this any longer! I want you to get rid of this heartless bandit!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Are you sure? According to my sources, I'm pretty sure you *need* me, don't you?\n"
					  "Think about it, " + name + ". You could receive help from the strongest bandit around.\n\n"
					  "You feel conflicted. On one hand, ORION deserves closure for his brother's death.\n"
					  "On the other, you were tasked to recruit BLAISE, and he would be a useful addition to the party.\n\n");
}

void Story::killBlaise_main()
{
	system("cls");

	Common::write_ani("You unsheathe your sword and point it at BLAISE.\nHe does not seem scared at all, in fact, he's smiling.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("...Oh well, I knew this would happen. Mark my words, though. You'll regret doing this.\n\n"
					  ". . .\n\n"
					  "You have killed ");

	Common::color_print(0x0c, "BLAISE.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Hah, you made the right choice, kid.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I think so, too. Maybe this was for the best.\n"
					  "Now that we are done here, perhaps we should continue on our journey.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::recruitBlaise_main()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("...I hate to admit it, but he's right. We *do* need him.\n"
					  "I *was* tasked with finding him to get his help, after all.\n\n");

	Common::color_print(0x0c, "BLAISE ");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Hah, I knew you would make the right choice! The more the merrier, am I right?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Fine, don't listen to me, " + name + ". I'll see how you react when you realise\n"
					  "this was a horrible decision for you to make.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Well, regardless of the... tension between you two, we are still a team, and we have\n"
					  "to work together. Perhaps we should continue on our journey.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetBlaise_eloraDead()
{
	system("cls");

	Common::write_ani("Immediately after opening the door to the bandits' treasure room, ORION recognises the figure\n"
					  "in front of your party.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Wait a minute. I know who you are!\n"
					  "BLAISE! You were the last person I wanted to see here!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh my, we meet again, ORION. Thanks for unlocking the room for me.\n\n"
					  "ORION looks behind BLAISE and notices that most of the treasure seems to be missing.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("No... you're doing the exact same thing you've done before! Taking everything and causing\n"
					  "discord and chaos within a group!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Wait... Is *he* why you're so against the idea of being in a party?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Yes! He caused my brother's death AND my entire party at the time to fall out! I'll bet\n"
					  "he's trying to make those bandits -- his 'allies' -- suffer the same fate!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh? I have no idea what you're talking about; I'm just taking what belongs to me.\n"
					  "I provided these guys with my strength, so it's only fair I take what I deserve, no?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani(name + "! I refuse to stand for this any longer! I want you to get rid of this heartless bandit!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Are you sure? According to my sources, I'm pretty sure you *need* me, don't you?\n"
					  "Think about it, " + name + ". You could receive help from the strongest bandit around.\n\n"
					  "You feel conflicted. On one hand, ORION deserves closure for his brother's death.\n"
					  "On the other, you were tasked to recruit BLAISE, and he would be a useful addition to the party.\n\n");
}

void Story::meetBlaise_orionDead()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, an ASSASSIN seems to already be there waiting.\n\n");

	Common::color_print(0x0c, "ASSASSIN:\n");
	Common::write_ani("I've been expecting you, " + name + ". My sources tell me you're looking for my help?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("...You must be BLAISE then?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Bingo! You're absolutely correct! I'm sure you know of my capabilities by now, yes?\n"
					  "Trust me, I'll be able to provide all the strength and support you need!\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani(name + ", are you certain we should let him join us?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("He *is* one of the people who could possibly help us, so... why not?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Sweet! You guys can count on me!\n\n");

	Common::color_print(0x0c, "BLAISE ");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I am a little worried, since he's an ally of the bandits, but... I trust your judgement, " + name + ".\n"
					  "Well then, perhaps we should continue our journey.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::meetBlaise_partyDead()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, an ASSASSIN seems to already be there waiting.\n\n");

	Common::color_print(0x0c, "ASSASSIN:\n");
	Common::write_ani("I've been expecting you, " + name + ". My sources tell me you're looking for my help?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("...You must be BLAISE then?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Bingo! You're absolutely correct! I'm sure you know of my capabilities by now, yes?\n"
					  "Trust me, I'll be able to provide all the strength and support you need!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I mean... sure, I guess.\n\n");
	
	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Sweet! You can count on me!\n\n");

	Common::color_print(0x0c, "BLAISE ");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Now that our alliance has been established, to... wherever it is you need to go\n"
					  "we go!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::beforeFightDK_main()
{
	system("cls");

	Common::write_ani("Your party stands right outside the Demon King's throne room.\n"
					  "You're wondering if you're even up to the task.\n\n"
					  "In an attempt to reassure yourself, you tell yourself that the emperor trusted\n"
					  "you with this for a reason.\n\n"
					  "And now, you lead your party into the throne room, where the Demon King\n"
					  "is waiting...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatDK_main()
{
	system("cls");

	Common::write_ani(". . .\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Did... did we do it? Did we beat the Demon King? \n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("It appears so. We should be able to retrieve your empire's treasure now.\n\n"
					  "You and your party enter the Demon King's treasure room.\nSure enough, the stolen treasures were in there.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I... Thank you guys. I couldn't have done this without you. \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Heh, we did what we could.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatDK_blaiseOnly()
{
	system("cls");

	Common::write_ani(". . .\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Did... did we do it? Did we beat the Demon King?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Yeah, we did! And you couldn't have done it without my help!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani(". . .\n"
					  "Well, I guess my job here is done, and you don't need me anymore, yeah?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("What do you mean?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("You know, I only joined you to get revenge for what you did to the bandits.\n"
					  "They were like family to me, so I wanted you to feel the pain I felt, but...\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Then I realised, you lost your other allies too, yeah? We're kind of the same\n"
					  "in that sense, so now I feel kinda bad.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("I'm part of the bandits, so you probably have some kind of hatred or prejudice\n"
					  "towards me for the pain and destruction I've caused your allies.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("How about this: why not just kill me?\n"
					  "That way, you can honour the ones you've lost.\n\n");
}

void Story::killBlaise_blaiseOnly()
{
	system("cls");

	Common::write_ani("You unsheathe your sword and point it at BLAISE. He smiles to himself in\n"
					  "resignation.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Yeah. I deserve this.\n\n"
					  ". . .\n\n"
					  "You have killed ");

	Common::color_print(0x0c, "BLAISE.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::forgiveBlaise_blaiseOnly()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("You know what, I'd consider this an equivalent exchange. I killed the ones you\n"
					  "considered family, and I guess I got my karma for that.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("We could work together from here on out, if you're okay with that. I don't\n"
					  "want to leave anyone alone.\n\n"
					  "BLAISE seemed unsure at first, but then he smiled and held out his fist.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Guess we're a team from now on, partner. \n\n"
					  "You mirror BLAISE's smile, and return his fist bump.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah. I guess we are.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatDK_eloraDead()
{
	system("cls");

	Common::write_ani(". . .\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Did... did we do it? Did we beat the Demon King? \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("We sure did. We can go bring your empire's treasure back now.\n\n"
					  "You and your party enter the Demon King's treasure room.\nSure enough, the stolen treasures were in there.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I... Thank you, ORION. I couldn't have done this without you. \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Heh, I did what I could.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatDK_orionDead()
{
	system("cls");

	Common::write_ani(". . .\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Did... did we do it? Did we beat the Demon King? \n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("It appears so. We should be able to retrieve your empire's treasure now.\n\n"
					  "You and your party enter the Demon King's treasure room.\nSure enough, the stolen treasures were in there.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I... Thank you guys. I couldn't have done this without you. \n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("It was our pleasure to help.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatDK_playerOnly()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I... I did it. I beat the Demon King. I can bring the treasures back now.\n\n"
					  "You enter the Demon King's treasure room.\nSure enough, the stolen treasures were in there.\n\n");

	Common::any_key_press("Press any key to continue");

}

void Story::blaiseBetrayal_main()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Well, I guess we should--\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Not so fast, " + name + ".\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("You know, I have to thank you for letting me join you.\n"
					  "Now, I finally have the opportunity to get what I want.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Wait, what do you mean? \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Oh, my god, he's talking about the treasure! I told you, you should have\n"
					  "killed him when you had the chance, but *no*, you didn't listen!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("That is indeed correct, my dear Elder Mage!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("No... I'm not letting you take my empire's treasure!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Is that so...? If you really want this treasure back, then I\n"
					  "have no choice but to fight you for it!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("It's a fight to the death, so we're going all out! I'm sure I can take\n"
					  "on all three of you at once!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::blaiseBetrayal_orionDead()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Well, I guess we should--\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Not so fast, " + name + ".\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("You know, I have to thank you for letting me join you.\n"
					  "Now, I finally have the opportunity to get what I want.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Wait, what do you mean? \n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Well... I joined you so I could get my revenge for what you did to the bandits.\n"
					  "I'll be taking your treasure, so you have nothing to bring back to your empire,\n"
					  "and maybe you'll lose everything too, just like I did!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("No... I'm not letting you take my empire's treasure!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Is that so...? If you really want this treasure back, then I\n"
					  "have no choice but to fight you for it!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("It's a fight to the death, so we're going all out! I'm sure I can take\n"
					  "on both of you at once!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBlaise_main()
{
	system("cls");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Hah... I should've expected this. You're way stronger than you look.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Perhaps we should let ORION do the honours. After all, he is the one who lost many\n"
					  "things to this bandit.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...I've waited for this moment.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("I'm sure you have, old man.\n\n"
					  ". . .\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("used a FIREBALL on BLAISE.\n\n"
					  "You can hear BLAISE screaming in agony.\n\n"
					  ". . .\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been killed.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Hmph. Good riddance.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBlaise_orionDead()
{
	system("cls");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Hah... I should've expected this. You're way stronger than you look.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("It's a fight to the death, right? All I need to do right now is just\n"
					  "get rid of you.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("...Fine, you win. I don't have the strength to do anything anymore.\n\n"
					  "BLAISE closes his eyes in resignation. You unsheathe your sword.\n\n"
					  ". . .\n\n"
					  "You have killed ");

	Common::color_print(0x0c, "BLAISE.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Well... I was expecting this to happen. He got what he deserved.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah. He really did.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBlaise_eloraDead()
{
	system("cls");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Hah... I should've expected this. You're way stronger than you look.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("You wanna do the honours, ORION?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...I've waited for this moment.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("I'm sure you have, old man.\n\n"
		". . .\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("used a FIREBALL on BLAISE.\n\n"
		"You can hear BLAISE screaming in agony.\n\n"
		". . .\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been killed.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Hmph. Good riddance.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::defeatBlaise_othersDead()
{
	system("cls");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Hah... I should've expected this. You're way stronger than you look.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("It's a fight to the death, right? All I need to do right now is just\n"
					  "get rid of you.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("...Fine, you win. I don't have the strength to do anything anymore.\n\n"
					  "BLAISE closes his eyes in resignation. You unsheathe your sword.\n\n"
					  ". . .\n\n"
					  "You have killed ");

	Common::color_print(0x0c, "BLAISE.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::ending_main()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I suppose we are done here, then.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Yeah, let's get all the treasure and bring them back to Moris.\n\n"
					  "Your party collects all the stolen treasure, then makes their way back to Moris Empire.\n\n"
					  "When you set foot into the empire, the Emperor is already standing at the entrance, waiting for you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("A warm welcome home, Knight " + name + ".\n"
					  "I knew this responsibility was in good hands. I would like to offer my sincerest gratitude to you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("And to the two of you as well, ELORA and ORION. Thank you for providing the\n"
					  "help you could to " + name + ". I would like to ask, what of BLAISE... ? \n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("He is... no longer with us.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("It's a long story, your highness.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("...I understand. I would be lying if I said this was unexpected.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Regardless, as thanks for retrieving our treasures, I would like to\n"
					  "hold a ceremony in your honour.\n\n"
					  "The ceremony was attended by the whole empire.\n"
					  "Word of your achievements have spread to the other kingdoms, and you and your\n"
					  "party have earned great recognition.\n\n"
					  "Who knows? Maybe you will have more great adventures like this one.\n\nfin.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::ending_partyMemDead()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Looks like we're done here, let's get all the treasure and bring them back to Moris.\n\n"
					  "Your party collects all the stolen treasure, then makes their way back to Moris Empire.\n\n"
					  "When you set foot into the empire, the Emperor is already standing at the entrance, waiting for you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("A warm welcome home, Knight " + name + ".\n"
					  "I knew this responsibility was in good hands. I would like to offer my sincerest gratitude to you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("...It seems that you have lost some of your party members.\n"
					  "I would be lying if I said that I wasn't expecting this.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Regardless, as thanks for retrieving our treasures, I would like to\n"
					  "hold a ceremony in your honour.\n\n"
					  "The ceremony was attended by the whole empire.\n"
					  "Word of your achievements have spread to the other kingdoms, and you and your\n"
					  "party have earned great recognition.\n\n"
					  "Who knows? Maybe you will have more great adventures like this one.\n\nfin.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::ending_playerOnly()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Looks like I'm done here, then.\n\n"
					  "You collect all the stolen treasure, then make your way back to Moris Empire.\n\n"
					  "When you set foot into the empire, the Emperor is already standing at the entrance, waiting for you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("A warm welcome home, Knight " + name + ".\n"
					  "I knew this responsibility was in good hands. I would like to offer my sincerest gratitude to you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("...I am rather curious, though. Did you not manage to find any of the three heroes?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("I did, but they...\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("...I understand. I would be lying if I said this was unexpected.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Regardless, as thanks for retrieving our treasures, I would like to\n"
					  "hold a ceremony in your honour.\n\n"
					  "The ceremony was attended by the whole empire.\n"
					  "Word of your achievements have spread to the other kingdoms, and you have\n"
					  "earned great recognition.\n\n"
					  "This may not be the ideal outcome, but maybe your next adventure will be better.\n\nfin.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::ending_blaiseAlive()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Looks like we're done here, let's get all the treasure and bring them back to Moris.\n\n"
					  "Your party collects all the stolen treasure, then makes their way back to Moris Empire.\n\n"
					  "When you set foot into the empire, the Emperor is already standing at the entrance, waiting for you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("A warm welcome home, Knight " + name + ".\n"
					  "I knew this responsibility was in good hands. I would like to offer my sincerest gratitude to you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("...It seems that you have lost some of your party members.\n"
					  "I would be lying if I said that I wasn't expecting this.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Well, both of us made it out alive! We got your treasure back, so now what?\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("Well, as thanks for retrieving our treasures, I would like to hold a ceremony\n"
					  "in your honour.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("That's... kinda underwhelming, but it's fine, I guess.\n\n"
					  "The ceremony was attended by the whole empire.\n"
					  "Word of your achievements have spread to the other kingdoms, and you and your\n"
					  "party have earned great recognition.\n\n"
					  "BLAISE has been getting a better reputation and he's not sure how to feel, but,\n"
					  "in his words, 'he'll take it.'\n\n"
					  "Who knows? Maybe you will have more great adventures like this one.\n\nfin.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::gameOver_playerDead()
{
	system("cls");

	Common::write_ani("You have died.\n\n"
					  "In your honour, the rest of your party went on to fight the Demon King. However, with\n"
					  "no one to lead them, the Demon King ended up defeating all of your party members.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::gameOver_everyoneDead()
{
	system("cls");

	Common::write_ani("You and your party members have died.\n\n"
					  "With no one to stop him, the Demon King ended up gaining more power, and killing\n"
					  "all who oppose him.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_start()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Oh, goodness... where could they be?\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Is something the matter?\n\n");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Oh, yes, yes! Three of our top students have gone missing!\n"
					  "It's been two days since they've been sent out on a mission,\n"
					  "and we haven't heard anything from them!\n\n");
}

void Story::magicSchool_accept()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("You'll help find them? Oh, thank you, thank you, kind soul!\n"
					  "They were sent to clear out the bandit camp north of Caershire, so\n"
					  "you could start there.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_decline()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Oh dear, I do hope they're safe...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_student1Found()
{
	system("cls");

	Common::color_print(0x0d, "MIRIAM:\n");
	Common::write_ani("...Huh? The GRAND MASTER sent you out to find me? But I'm looking for my\n"
					  "friends! They've gotten lost in there, too!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Don't worry, I can help you find them.\n\n");

	Common::color_print(0x0d, "MIRIAM:\n");
	Common::write_ani("Really? ...Well, I guess if you've been tasked by the GRAND MASTER, I can trust\n"
					  "you! I'll head back first, then. I hope you can find my friends!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_student2Trapped()
{
	system("cls");

	Common::color_print(0x0d, "WESLEY:\n");
	Common::write_ani("Look, I don't know how many times I have to say this, I don't care for\n"
					  "your threats, I won't tell you... Oh, you're not a bandit?\n\n");

	Common::color_print(0x0d, "WESLEY:\n");
	Common::write_ani("You were sent by the GRAND MASTER to find me? Well, as you can see, I am\n"
					  "currently *trapped* in a cage, so I need to get out of here to go back!\n\n"
					  "You try to use brute force to break the cage door...\n\n");

	Common::color_print(0x04, "BANDIT:\n");
	Common::write_ani("Hey! What're you trying to do?\n\n"
					  "The BANDIT guarding the cage has you at knife point, and is challenging you to a BATTLE!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_student2Found()
{
	system("cls");

	Common::write_ani("You take the key from the unconscious BANDIT.\n\n");

	Common::color_print(0x0d, "WESLEY:\n");
	Common::write_ani("Quickly, let me out of here!\n\n");

	Common::write_ani("You unlock the cage door.\n\n");

	Common::color_print(0x0d, "WESLEY:\n");
	Common::write_ani("Ah, finally! It was terribly cramped in there. Thanks for helping me out!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_student3Found()
{
	system("cls");

	Common::color_print(0x0d, "CHARLIE:\n");
	Common::write_ani(". . .\n"
					  "Oh, I was supposed to be back at school how long ago?\n\n");

	Common::color_print(0x0d, "CHARLIE:\n");
	Common::write_ani("Sorry, I got a little... distracted. I'll head back immediately.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_inProgress()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Oh dear, oh dear, where could they be?\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::magicSchool_complete()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Oh, thank you, thank you! I knew I could count on you to find them!\n"
					  "Please, take these as a token of my appreciation!\n\n"
					  "You obtained some ARMOUR, 2 MP POTIONS, and 20 COINS!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::KoE_start()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("You look a little lost. Do you perhaps need help with something?\n\n");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("Yeah, actually. I do need some help. I want to make a weapon inspired by Miss ELORA,\n"
					  "but I don't know where I can find one of the materials.\n\n");
}

void Story::KoE_accept()
{
	system("cls");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("Thanks for offering to help, pal! I need you to help me find three chunks\n"
					  "of jade. They're pretty hard to find, from what I hear, so good luck with\n"
					  "that!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::KoE_decline()
{
	system("cls");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("Thanks, pal. I'll keep asking around until I get something.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::KoE_inProgress()
{
	system("cls");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("I need you to help me find three chunks of jade, pal!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::KoE_complete()
{
	system("cls");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("Hey, you actually found the jade! Hand them over, I'll start work immediately.\n\n"
					  "The BLACKSMITH starts forging the weapon.\n\n"
					  ". . .\n\n");

	Common::color_print(0x09, "BLACKSMITH:\n");
	Common::write_ani("Alright, it's done! There was a lot more excess than I expected, so I made another one\n"
					  "for you as a token of my appreciation. Here you go, pal!\n\n"
					  "You obtained a SWORD!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_floor1()
{
	system("cls");

	Common::write_ani("As soon as you enter the dungeon, you hear a rattling sound coming from the pile of bones\n"
					  "in front of you.\n\n"
					  ". . .\n\n"
					  "The bones have become SKELETONS, and are challenging you to a BATTLE!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_defeatedSkels()
{
	system("cls");

	Common::write_ani("The skeletons crumble into the pile of bones they once were.\n\n"
					  "You can now advance to the next floor!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_floor2()
{
	system("cls");

	Common::write_ani("This door seems to be locked... It looks like you need a key to unlock it.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_doorUnlocked()
{
	system("cls");

	Common::write_ani("You used the key you found to unlock the door.\n\n"
					  ". . .\n\n"
					  "You can now advance to the next floor!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_floor3()
{
	system("cls");

	Common::write_ani("As soon as you walk into the room, the door shuts right behind you!\n\n"
					  "You look around the room, and you make eye contact with a STONE GIANT!\n\n");

	Common::color_print(0x08, "OLAF THE STONE GIANT:\n");
	Common::write_ani("Another challenger who wishes to pull the EXCALIBUR out of its stone...\n"
					  "Countless others have tried, but all have failed. To be deemed worthy,\n"
					  "great strength must be shown.\n\n");

	Common::color_print(0x08, "OLAF THE STONE GIANT:\n");
	Common::write_ani("O young one, the STONE GIANT challenges you to a fight.\n"
					  "Should you be victorious, you shall obtain the EXCALIBUR's might.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_giantDefeated()
{
	system("cls");

	Common::color_print(0x08, "OLAF THE STONE GIANT:\n");
	Common::write_ani("Alas, the STONE GIANT has been defeated, and the young hero has won.\n"
					  "Worthy of wielding the EXCALIBUR, you are the chosen one.\n\n");

	Common::color_print(0x08, "OLAF THE STONE GIANT:\n");
	Common::write_ani("Go on now, young hero, and pull the EXCALIBUR from its stone.\n"
					  "From this day forth, its strength shall be your own.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::excalibur_completed()
{
	system("cls");

	Common::write_ani("You grab onto the handle of the EXCALIBUR.\n"
					  "Something tells you that you shouldn't let go of it, no matter what happens.\n"
					  "As you pull out the sword, you feel a burning sensation on your palm.\n\n"
					  "Suddenly, a bright light engulfs the entire room.\n\n"
					  ". . .\n\n"
					  "It feels like you've gotten stronger.\n"
					  "You have obtained and equipped the EXCALIBUR!\n\n"
					  "The door has been opened, and you have reunited with your party!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc1()
{
	system("cls");

	Common::color_print(0x0d, "NORAH:\n");
	Common::write_ani("I'm saving up for a new house! This one's way too small for me.\n"
					  "I guess that's what happens when you collect too many things...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc2()
{
	system("cls");

	Common::color_print(0x0d, "KINGSLEY:\n");
	Common::write_ani("How am I going to get this spell right? I've tried hundreds of\n"
					  "times, but I can never seem to get the hang of it...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc3()
{
	system("cls");

	Common::color_print(0x0d, "LUNA:\n");
	Common::write_ani("My sister's one of the top students of the School of Magic! I\n"
					  "hope I can be just like her someday.\n\n");

	Common::color_print(0x0d, "LUNA:\n");
	Common::write_ani("I can only cast tiny spells, though... so I'm going to need a lot\n"
					  "more practice!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc4()
{
	system("cls");

	Common::color_print(0x0d, "PETER:\n");
	Common::write_ani("Welcome to Caershire! I hope you enjoy your visit!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc5()
{
	system("cls");

	Common::color_print(0x0d, "IRIS:\n");
	Common::write_ani("Casting healing spells is really tough. The spell sequences are\n"
					  "so long and complicated! It's really giving me a headache...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc6()
{
	system("cls");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("So, what did you wish for?\n\n");

	Common::color_print(0x0d, "MAEVE:\n");
	Common::write_ani("What did I wish for, you ask? Hehe, I can't tell you, or it'll never\n"
					  "come true!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc7()
{
	system("cls");

	Common::color_print(0x0d, "GRAND MASTER MAGE PENDOLF:\n");
	Common::write_ani("Welcome to the School of Magic! Enjoy your stay!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc8_9_10()
{
	system("cls");

	Common::write_ani("They seem to be busy training...\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc11()
{
	system("cls");

	Common::color_print(0x0a, "GORWIN:\n");
	Common::write_ani("Welcome to the Kingdom of Elves! We hope you enjoy your stay here.\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Thanks! This sure is a wonderful Kingdom.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc12()
{
	system("cls");

	Common::color_print(0x0a, "AERITH:\n");
	Common::write_ani("This bow was given to me by my father. I've been using it for over 20\n"
					  "years, and it hasn't ever failed me!\n\n");

	Common::color_print(0x0b, name + ":\n");
	Common::write_ani("Amazing!\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc13(bool bandits)
{
	system("cls");

	if (bandits == false) {
		Common::color_print(0x0a, "THALIA:\n");
		Common::write_ani("I've never actually been outside the kingdom, and I want to explore, but I've heard\n"
						  "stories about the outside world, horror stories...\n\n");

		Common::color_print(0x0a, "THALIA:\n");
		Common::write_ani("I don't know if it's a good idea anymore.\n\n");

		Common::color_print(0x0b, name + ":\n");
		Common::write_ani("If it's about the bandits, don't worry. I'll get rid of them!\n\n");

		Common::color_print(0x0a, "THALIA:\n");
		Common::write_ani("Really? Thanks a lot!\n\n");
	}
	else {
		Common::color_print(0x0a, "THALIA:\n");
		Common::write_ani("You've managed to clear the bandits? Thank you so much! Maybe I'll be able to\n"
						  "explore without the fear of being threatened by any bandits now!\n\n");
	}

	Common::any_key_press("Press any key to continue");
}

void Story::npc14(bool state)
{
	system("cls");

	Common::color_print(0x09, "MASON:\n");
	if (state)
		Common::write_ani("Best of luck for your next journey!\n"
						  "Bring some souvenirs back if you can! ...Haha, I'm just kidding, you don't have to!\n\n");
	else
		Common::write_ani("Hey, kid! Heard the Emperor's looking for you, it's best if you go immediately!\n"
						  "If you can't recall where the castle is, it's east from here. Just keep going in\n"
						  "that direction and you'll be able to find it.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc15_16()
{
	system("cls");

	Common::write_ani("They seem to be really focused on whatever they're wishing for...\n"
					  "Maybe it's best not to disturb them.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc17_18()
{
	system("cls");

	Common::write_ani("They seem to be really absorbed in their garden...\n"
					  "You can see the effort they've put into taking care of their plants.\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::npc19_20()
{
	system("cls");

	Common::color_print(0x09, "GUARD:\n");
	Common::write_ani("Are you here to see the EMPEROR?\n\n");

	Common::any_key_press("Press any key to continue");
}

void Story::treasureRoomHint()
{
	system("cls");

	Common::write_ani("You pick up the note on the floor and begin to read it:\n"
					  "BLUE, RED, RED, BLUE.\n\n");

	Common::any_key_press("Press any key to continue");
}
