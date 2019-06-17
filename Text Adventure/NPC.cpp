#include "NPC.hpp"

NPC::NPC(std::string name, std::string talkText, std::string talkTextAgain, std::string bio, bool hasItem, Item* giveItem)
{
	this->name = name;
	this->talkText = talkText;
	this->talkTextAgain = talkTextAgain;
	this->bio = bio;
	this->hasItem = hasItem;
	this->giveItem = giveItem;
}
void NPC::TalkTo(Player* player)
{
	if (talkedOnce == false)
	{
		talkedOnce = true;
		if (hasItem == true)
		{
			std::cout << talkText << std::endl << "you got " << giveItem->GetName() << std::endl;
			player->AddItem(giveItem);
		}
		else
		{
			std::cout << talkText << std::endl;
		}
	}
	else
	{
		std::cout << talkTextAgain;
	}
	std::cout << "\n\n";

}
std::string NPC::GetName()
{
return this->name;
}
void NPC::PrintBio()
{
	std::cout << bio <<std::endl <<std::endl;
}