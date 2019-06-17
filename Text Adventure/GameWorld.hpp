#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP
#include "Room.hpp"
#include "Food.hpp"
#include "Drink.hpp"
#include "StatUp.hpp"
#include "Scroll.hpp"
#include "Move.hpp"


class GameWorld
{
public:
	GameWorld(std::string playerName, std::string roomMateName);
	Room* MakeGameWorld();
	Room* GetCurrRoom();
	void SetCurrRoom(Room* room);

	void Look(std::string direction);
	void LinkRooms(Room* roomOne, Room* roomTwo, std::string direction);
	void PlayTheGame(Room* startingRoom, Player* human);
	void LookAround();
	void LookAroundPlus();

private:
	Room* currCheckpoint;
	Room* currRoom;
	std::string playerName;
	std::string roomMateName;
};

#endif