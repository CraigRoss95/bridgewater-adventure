#ifndef NPC_HPP
#define NPC_HPP
#include "Player.hpp"
#include "Food.hpp"
#include "Drink.hpp"

class NPC
{
public:
	NPC(std::string name, std::string talkText, std::string talkTextAgain, std::string bio, bool hasItem, Item* giveItem);
	void TalkTo(Player* player);
	std::string GetName();
	void PrintBio();

	
private:
	std::string name;
	std::string talkText;
	std::string talkTextAgain;
	std::string bio;
	bool hasItem;
	bool talkedOnce = false;
	Item* giveItem;
};
#endif