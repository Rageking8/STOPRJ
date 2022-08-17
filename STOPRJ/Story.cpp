#include "Story.h"
#include "Common.h"
#include <iostream>
#include "Windows.h"

void Story::prologue()
{
	system("cls");

	const char* story_arr[]{
		"Knight PLAYER, I have a job for you.\n"
		"As you already know, our treasure has gone missing.\n"
		"I suspect the Demon King has something to do with this predicament.\n\n",

		"You are to defeat the Demon King and retrieve our stolen treasures.\n"
		"However, you need the help of three important people to succeed.\n\n",

		"First, seek out ELORA of the Kingdom of Elves.\n"
		"She is the leader of the elves, and a very skilled marksman.\n\n",

		"Next, you need to locate Elder Mage ORION of Caershire.\n"
		"He is rather... reclusive, and stubborn, but his wisdom and experience may prove to be of use.\n\n",

		"The last person you need to recruit is a very strong rogue named BLAISE.\n"
		"Nobody has been able to find him these days, but I trust you can do it.\n\n",

		"Good luck, PLAYER. I leave this task in your capable hands.\n\n",
	};

	for (const auto i : story_arr) {
		Common::color_print(0x0e, "EMPEROR:\n");
		Common::write_ani(i);
	}

	Common::input("Press enter to continue ");
}

void Story::foundCart()
{
	system("cls");

	const char* story_arr[]{
	"There's a suspicious-looking cart here...\n"
	"Maybe I'll do a little digging and see if I can find anything.\n\n",

	"You investigate the suspicious cart.\n"
	"However, you end up finding nothing of interest.\n\n",

	"Well, that's sad.\n"
	"I can't get to the Kingdom of Elves with this cart blocking the path.\n"
	"Might as well take a detour. I have to get there somehow.\n\n",
	};
	
	for (const auto i : story_arr) {
		Common::color_print(0x0b, "PLAYER:\n");
		Common::write_ani(i);
	}

	Common::input("Press enter to continue ");
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
	
	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Wait!I'm not here to fight!\n\n"
					  "The Elves seem to have disregarded your claim, and are challenging you to a BATTLE!\n\n");

	Common::input("Press enter to continue ");
}

void Story::winElora()
{
	system("cls");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("No... I could not have been defeated by a mere bandit!\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("That's what I'm trying to tell you, I'm not a bandit!\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("You aren't one of them? Well, that's... rather embarrassing.\n"
					  "As an apology, let us accompany you to our Kingdom so that you may recover after our fight.\n\n"
					  "The Elves bring you back to the Kingdom of Elves and provide you with medical assistance.\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("I believe I should formally introduce myself.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("My name is ELORA. I am the leader of the Kingdom of Elves.\n"
					  "I would like to extend my sincerest apologies for earlier. You see, our kingdom is currently\n"
					  "under threat from the bandits nearby, and I mistakenly assumed you were one of their allies.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Bandits? I could help you guys clear them out. You know, as thanks for patching me up and all.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("That would be much appreciated. Thank you for your kind offer.\n\n");

	Common::input("Press enter to continue ");
}

void Story::loseElora()
{
	system("cls");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("Hmph, we will be taking you with us, and you will be answering our questions.\n\n"
					  "You have been captured by the elves...\nThey tossed you into a cell, and all you could do was wait.\n\n");

	Common::write_ani(". . .\n\n"
					  "The next day, you were taken to an interrogation room, where the STRONG ELF was waiting.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Before you say anything, there's been a misunderstanding, I'm not with the bandits.\n"
					  "If you don't believe me, you could always ask the guards to search me.\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("...Very well. You two over there, search this individual's belongings!\n\n"
					  "The guards inspected you and your belongings, but they couldn't find any\n"
					  "indication of you being a bandit.\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("...It seems I may have made a mistake.\n"
					  "I sincerely apologise for this misunderstanding. I was merely worried\n"
					  "about the bandits invading our kingdom. Let me patch you up.\n\n"
					  "The STRONG ELF provides you with medical assistance.\n\n");

	Common::color_print(0x0a, "STRONG ELF:\n");
	Common::write_ani("I believe I should formally introduce myself.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("My name is ELORA. I am the leader of the Kingdom of Elves.\n"
					  "I would like to extend my sincerest apologies once again. You see, our kingdom is currently\n"
					  "under threat from the bandits nearby, and I mistakenly assumed you were one of their allies.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Bandits? I could help you guys clear them out.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("You are still offering to help, even after we defeated and captured you?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Well, yeah. I did cause some panic for you, so the least I can do is to get\n"
					  "rid of some of your worries.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("You are a good person. Thank you for your kind offer.\n\n");

	Common::input("Press enter to continue ");
}

void Story::recruitElora()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Have the bandits been cleared out?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Yeah, it took a while, but it's done.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("My sincerest thanks once again. At least some of my worries have been alleviated.\n"
					  "Is there, perhaps, any way I could show my gratitude?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Well, I'm on a quest to defeat the Demon King and retrieve my empire's treasure, and\n"
					  "you're one of the heroes I have to seek assistance from.\n"
					  "Would it be alright for you to join me in doing so?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("...I am rather worried of what would happen if I were to leave.\n"
					  "This seems to be rather important for you, though, so I could appoint someone to look\n"
					  "after the kingdom in my stead.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Very well, I shall accompany you on your journey. I do hope I can be of assistance.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::input("Press enter to continue ");
}

void Story::outsideOrionResidence()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Is one of the other people you were tasked to seek the Elder Mage ORION?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Yep! I've heard he's a bit of a shut-in, though. So it might be a little difficult to convince\n"
					  "him to join us.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I do not think you could convince him; he has a... distaste for being in a party.\n"
					  "All I know is that he had a harsh falling out with his party members at the time.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Oh. Well, there's no harm in trying, right?\n\n"
					  "You knock on the door, but you are met with no response.\nYou try knocking again, but once again there is no response from the other side.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("That's weird. Where could he be?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Maybe he's really busy right now. Let's find our last party member first, and then\n"
					  "come back here later.\n\n");

	Common::input("Press enter to continue ");
}

void Story::meetOrion()
{
	system("cls");

	Common::write_ani("Your party arrives at a bandit camp, and you notice ORION fighting against a group of bandits.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Isn't that him? What's he doing fighting the bandits on his own?\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("He is seriously injured! We must provide assistance as soon as possible!\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Stay back! I don't need any help, this is *my* job to do!\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("But you're using up so much mana! Won't this have adverse effects on your body?\n"
					  "At least give yourself some time to recharge, we can handle this batch!\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Darned kids, I swear... Fine, I'll let you two help out.\n\n");

	Common::input("Press enter to continue ");
}

void Story::recruitOrion_main()
{
	system("cls");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Thanks for the help, I guess.\n"
					  "You two came all the way here to find me, I assume. What do you want?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Well, I'm on a quest to defeat the Demon King, and you're one of the people I\n"
					  "was tasked to seek out.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("PLAYER, I do not think you should--\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I might as well join you. It's the least I can do since you helped me out with those bandits.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Wait, really? I thought you hated the idea of being in a party.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("You're right. But I'm only doing this because I have to repay you for getting rid of those bandits.\n"
					  "Even though I'd rather not join you guys, I'm a man of my word.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::input("Press enter to continue ");
}

void Story::recruitOrion_eloraDead()
{
	system("cls");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...Thanks for the help, I guess. And uh, sorry about your friend.\n"
					  "You came all the way here to find me, I assume. What do you want?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Uh... I'm on a quest to defeat the Demon King, and you're one of the people I\n"
					  "was tasked to seek out.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I'll join you. It's the least I can do since you helped me out with those bandits.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Huh? Don't you hate the idea of being in a party?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I do. But I'm only doing this because I have to repay you for getting rid of those bandits.\n"
					  "Even though I'd rather not join you, I'm a man of my word.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::input("Press enter to continue ");
}

void Story::meetBlaise_main()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, ORION notices something lying on the ground.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...That's my brother's sword.\n\n"
					  "ORION walks over to the sword and picks it up, closely inspecting it.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I see. These are the same bandits that killed my brother, and caused\n"
					  "everything to fall apart!\n\n");

	Common::color_print(0x0c, "BANDIT:\n");
	Common::write_ani("Hey, hey, hey, what's all this ruckus in here? What are you people trying to do, hmm?\n\n"
					  "ORION seems to immediately recognise the bandit.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("You! You're the one who took everything from me! Isn't it only right that I take\n"
					  "something from you in exchange, Blaise?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh? Last I checked, what you're doing is called 'stealing'. Besides, whatever happened\n"
					  "to that guy was bound to happen anyway. He was just too weak.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("PLAYER! I refuse to stand for this any longer! I want you to get rid of this heartless bandit!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Are you sure? According to my sources, I'm pretty sure you *need* me, don't you?\n"
					  "Think about it, PLAYER. You could receive help from the strongest bandit around.\n\n"
					  "You feel conflicted. On one hand, ORION deserves closure for his brother's death.\n"
					  "On the other, you were tasked to recruit BLAISE, and he would be a useful addition to the party.\n\n");

}

void Story::killBlaise_main()
{
	system("cls");

	Common::write_ani("You unsheathe your sword and point it at BLAISE.\nHe does not seem scared at all, in fact, he's smiling.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh well, I knew this would happen. Mark my words, though. You'll regret doing this.\n\n"
					  ". . .\n\n"
					  "You have killed ");

	Common::color_print(0x0c, "BLAISE.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Hah, you made the right choice, kid.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I think so, too. Maybe this was for the best.\n"
					  "Now that we are done here, perhaps we should continue on our journey.\n\n");

	Common::input("Press enter to continue ");
}

void Story::recruitBlaise_main()
{
	system("cls");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("...I hate to admit it, but he's right. We *do* need him.\n"
					  "I *was* tasked with finding him to get his help, after all.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("I knew you would make the right choice. The more the merrier, am I right?\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Fine, don't listen to me, PLAYER. I'll see how you react when you realise\n"
					  "this was a horrible decision for you to make.\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("Well, regardless of the... tension between you two, I suppose we are still a team.\n"
					  "Perhaps we should continue on our journey.\n\n");

	Common::input("Press enter to continue ");
}

void Story::meetBlaise_eloraDead()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, ORION notices something lying on the ground.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("...That's my brother's sword.\n\n"
					  "ORION walks over to the sword and picks it up, closely inspecting it.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("I see. These are the same bandits that killed my brother, and caused\n"
					  "everything to fall apart!\n\n");

	Common::color_print(0x0c, "BANDIT:\n");
	Common::write_ani("Hey, hey, hey, what's all this ruckus in here? What are you people trying to do, hmm?\n\n"
					  "ORION seems to immediately recognise the bandit.\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("You! You're the one who took everything from me! Isn't it only right that I take\n"
					  "something from you in exchange, Blaise?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Oh? Last I checked, what you're doing is called 'stealing'. Besides, whatever happened\n"
					  "to that guy was bound to happen anyway. He was just too weak.\n\n");

	Common::write_ani("Before you could say anything, ORION summons his staff and uses a FIREBALL on BLAISE.\n\n"
					  ". . .\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been killed.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("What did you just do?!\n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Just gave the kid what he deserves. Not that it matters now, though. Don't\n"
					  "you have a task to complete? We should get going.\n\n");

	Common::input("Press enter to continue ");
}

void Story::meetBlaise_orionDead()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, a BANDIT is already there waiting.\n\n");

	Common::color_print(0x0c, "BANDIT:\n");
	Common::write_ani("I've been expecting you, PLAYER. My sources tell me you're looking for my help?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("...You must be BLAISE then?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Bingo! You're absolutely correct! I'm sure you know of my capabilities by now, yes?\n"
					  "Trust me, I'll be able to provide all the strength and support you need!\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("PLAYER, are you certain we should let him join us?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("He *is* one of the people who could possibly help us, so... why not?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Sweet! You guys can count on me!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I am a little worried, since he *is* a bandit, but... I trust your judgement, PLAYER.\n"
					  "Well then, perhaps we should continue our journey.\n\n");

	Common::input("Press enter to continue ");
}

void Story::meetBlaise_partyDead()
{
	system("cls");

	Common::write_ani("Immediately after entering the bandits' treasure room, a BANDIT is already there waiting.\n\n");

	Common::color_print(0x0c, "BANDIT:\n");
	Common::write_ani("I've been expecting you, PLAYER. My sources tell me you're looking for my help?\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("...You must be BLAISE then?\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Bingo! You're absolutely correct! I'm sure you know of my capabilities by now, yes?\n"
					  "Trust me, I'll be able to provide all the strength and support you need!\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("I mean... sure, I guess.\n\n");
	
	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Sweet! You can count on me!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("has been recruited to your party!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Now that our alliance has been established, to... wherever it is you need to go\n"
					  "we go!\n\n");

	Common::input("Press enter to continue ");
}

void Story::beforeFightDK_main()
{
	system("cls");

	Common::write_ani("Your party is standing right outside the Demon King's throne room.\n"
					  "You're wondering if you're even up to the task.\n\n"
					  "In an attempt to reassure yourself, you tell yourself that the\n"
					  "emperor trusted you with this for a reason.\n\n"
					  "And now, you lead your party into the throne room, where the Demon\n"
					  "King is waiting...\n\n");

	Common::input("Press enter to continue ");
}

void Story::defeatDK_main()
{
	system("cls");

	Common::write_ani(". . .\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Did... did we do it? Did we beat the Demon King? \n\n");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("It appears so. We should be able to retrieve your empire's treasure now.\n\n"
					  "You and your party enter the Demon King's treasure room.\nSure enough, the stolen treasures were in there.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("I... Thank you guys. I couldn't have done this without you. \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Bah, we did what we could.\n\n");

	Common::input("Press enter to continue ");
}

void Story::blaiseBetrayal_main()
{
	system("cls");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Well, I guess we should--\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Not so fast, PLAYER.\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("You know, I have to thank you for letting me join you.\n"
					  "Now, I finally have the opportunity to get what I want.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Wait, what do you mean? \n\n");

	Common::color_print(0x0d, "ORION:\n");
	Common::write_ani("Oh, my god, he's talking about the treasure! I told you, you should have\n"
					  "killed him when you had the chance, but *no*, you didn't listen!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("That is indeed correct, my dear Elder Mage!\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("No... I'm not letting you take my empire's treasure!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("Is that so...? If you really want this treasure back, then I\n"
					  "have no choice but to fight you for it!\n\n");

	Common::color_print(0x0c, "BLAISE:\n");
	Common::write_ani("It's a fight to the death, so we're going all out! I'm sure I can take\n"
					  "on all three of you at once!\n\n");

	Common::input("Press enter to continue ");
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

	Common::input("Press enter to continue ");
}

void Story::ending_main()
{
	system("cls");

	Common::color_print(0x0a, "ELORA:\n");
	Common::write_ani("I suppose we are done here, then.\n\n");

	Common::color_print(0x0b, "PLAYER:\n");
	Common::write_ani("Yeah, let's get all the treasure and bring them back to Moris.\n\n"
					  "Your party collects all the stolen treasure, then makes their way back to Moris Empire.\n\n"
					  "When you set foot into the empire, the Emperor is already standing at the entrance, waiting for you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("A warm welcome home, Knight PLAYER.\n"
					  "I knew this responsibility was in good hands. I would like to offer my sincerest gratitude to you.\n\n");

	Common::color_print(0x0e, "EMPEROR:\n");
	Common::write_ani("And to the two of you as well, ELORA and ORION. Thank you for providing the\n"
					  "help you could to PLAYER. I would like to ask, what of BLAISE...?\n\n");

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

	Common::input("Press enter to continue ");
}

void Story::gameOver_playerDead()
{
	system("cls");

	Common::write_ani("You have died.\n\n"
					  "In your honour, the rest of your party went on to fight the Demon King. However, with\n"
					  "no one to lead them, the Demon King ended up defeating all of your party members.\n\n");

	Common::input("Press enter to continue ");
}

void Story::gameOver_everyoneDead()
{
	system("cls");

	Common::write_ani("You and your party members have died.\n\n"
					  "With no one to stop him, the Demon King ended up gaining more power, and killing\n"
					  "all who oppose him.\n\n");

	Common::input("Press enter to continue ");
}